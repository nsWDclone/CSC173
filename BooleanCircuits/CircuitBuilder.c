#include "CircuitBuilder.h"

Circuit* build_circuit_A(){
  Value* inx = new_Value(false);
  Value* iny = new_Value(false);
  Value* inz = new_Value(false);

  Gate* not1 = new_Inverter(iny);
  Gate* and1 = new_AndGate(inx, Gate_getOutput(not1));
  Gate* and2 = new_AndGate(iny, inz);
  Gate* or1  = new_OrGate(Gate_getOutput(and1), Gate_getOutput(and2));

  Gate** gates = new_Gate_array(4);
  gates[0] = not1;
  gates[1] = and1;
  gates[2] = and2;
  gates[3] = or1;

  Value** inputs = new_Value_array(3);
  inputs[0] = inx;
  inputs[1] = iny;
  inputs[2] = inz;

  Value** outputs = new_Value_array(1);
  outputs[0] = Gate_getOutput(or1);

  return new_Circuit(3, inputs, 1, outputs, 4, gates);
}

Circuit* build_circuit_B(){
  Value* inx = new_Value(false);
  Value* iny = new_Value(false);
  Value* inz = new_Value(false);

  Gate* not1 =  new_Inverter(iny);
  Gate* nand1 = new_NandGate(inx, Gate_getOutput(not1));
  Gate* nand2 = new_NandGate(iny, inz);
  Gate* nor1  = new_NorGate(Gate_getOutput(nand1), Gate_getOutput(nand2));

  Gate** gates = new_Gate_array(4);
  gates[0] = not1;
  gates[1] = nand1;
  gates[2] = nand2;
  gates[3] = nor1;

  Value** inputs = new_Value_array(3);
  inputs[0] = inx;
  inputs[1] = iny;
  inputs[2] = inz;

  Value** outputs = new_Value_array(1);
  outputs[0] = Gate_getOutput(nor1);

  return new_Circuit(3, inputs, 1, outputs, 4, gates);
}

Circuit* build_circuit_C(){
  Value* inx = new_Value(false);
  Value* iny = new_Value(false);

  Gate* and1 = new_AndGate(iny, inx);
  Gate* not1 = new_Inverter(inx);
  Gate* not2 = new_Inverter(iny);
  Gate* and2 = new_AndGate(Gate_getOutput(not1), Gate_getOutput(not2));
  Gate* or1  = new_OrGate(Gate_getOutput(and1), Gate_getOutput(and2));

  Value** inputs = new_Value_array(2);
  inputs[0] = inx;
  inputs[1] = iny;

  Gate** gates = new_Gate_array(5);
  gates[0] = and1;
  gates[1] = not1;
  gates[2] = not2;
  gates[3] = and2;
  gates[4] = or1;

  Value** outputs = new_Value_array(1);
  outputs[0] = Gate_getOutput(or1);

  return new_Circuit(2, inputs, 1, outputs, 5, gates);
}

Circuit* build_circuit_ADDER(){
  Value* inx = new_Value(false);
  Value* iny = new_Value(false);
  Value* inc = new_Value(false);

  Gate* notx = new_Inverter(inx);
  Gate* noty = new_Inverter(iny);
  Gate* notc = new_Inverter(inc);
  Gate* and1 = new_And3Gate(Gate_getOutput(notx), Gate_getOutput(noty), inc);
  Gate* and2 = new_And3Gate(Gate_getOutput(notx), iny, Gate_getOutput(notc));
  Gate* and4 = new_And3Gate(Gate_getOutput(notx), iny, inc);
  Gate* and3 = new_And3Gate(inx, Gate_getOutput(noty), Gate_getOutput(notc));
  Gate* and5 = new_And3Gate(inx, Gate_getOutput(noty), inc);
  Gate* and6 = new_And3Gate(inx, iny, Gate_getOutput(notc));
  Gate* and7 = new_And3Gate(inx, iny, inc);
  Gate* or1  = new_Or4Gate(
    Gate_getOutput(and1), Gate_getOutput(and2),
    Gate_getOutput(and4), Gate_getOutput(and7)
  );
  Gate* or2  = new_Or4Gate(
    Gate_getOutput(and3), Gate_getOutput(and5),
    Gate_getOutput(and6), Gate_getOutput(and7)
  );

  Value** inputs = new_Value_array(3);
  inputs[0] = inx;
  inputs[1] = iny;
  inputs[2] = inc;

  Gate** gates = new_Gate_array(12);
  gates[0] = notx;
  gates[1] = noty;
  gates[2] = notc;
  gates[3] = and1;
  gates[4] = and2;
  gates[5] = and3;
  gates[6] = and4;
  gates[7] = and5;
  gates[8] = and6;
  gates[9] = and7;
  gates[10] = or1;
  gates[11] = or2;

  Value** outputs = new_Value_array(2);
  outputs[0] = Gate_getOutput(or2);
  outputs[1] = Gate_getOutput(or1);

  return new_Circuit(3, inputs, 2, outputs, 12, gates);
}
