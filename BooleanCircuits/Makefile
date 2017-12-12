#
# File: Makefile
# Creator: George Ferguson
# Created: Mon Nov 28 13:52:02 2016
# Time-stamp: <Mon Nov 28 14:31:03 EST 2016 ferguson>
#

SRCS = Value.c Gates.c Circuit.c CircuitBuilder.c CircuitTester.c boolsim.c
HDRS = Value.h Gates.h Circuit.h CircuitBuilder.h CircuitTester.h
OBJS = $(SRCS:.c=.o)
EXE = boolsim
ZIPDIR = mshems_project5

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

clean:
	-rm $(OBJS) $(EXE)

zip:
	mkdir '$(ZIPDIR)'
	cp -p $(SRCS) $(HDRS) Makefile README.txt '$(ZIPDIR)'
	zip -r '$(ZIPDIR)' '$(ZIPDIR)'
	rm -r '$(ZIPDIR)'
