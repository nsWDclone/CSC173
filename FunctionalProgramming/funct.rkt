#lang racket

(displayln "MATH FUNCTIONS")
;Find absulute value of a number
(define (absval n)
  (if (positive? n) n
    (begin
      (set! n (* n -1))
      n)))
(display "  Absolute value of -64 = ")(absval -64)

;Find the n-th term of the fibonacci sequence
(define (nth-fib x)
    (if (<= x 2) 1
    (+ (nth-fib(sub1 (sub1 x))) (nth-fib (sub1 x)))))
(display "  10th fibonacci number = ")(nth-fib 10)

;Find factorial of a number
(define (factorial x)
  (if (zero? x) 1
  (* x (factorial(sub1 x)))))
(display "  4! = ")(factorial 4)

(displayln "LIST FUNCTIONS")
;Add to end of list
(define (add-to-end n list)
  (begin
    (define l '())
    (set! l (list* n (reverse list)))
    (reverse l)))
(display "  Add '4' to end of list (1 2 3) = ")(add-to-end 4 (list 1 2 3))

;Find index of member of a list
(define (index-of tgt l)
  (define (find l curr tgt)
    (if (equal? (list-ref l curr) tgt) 0
      (+ 1 (find l (add1 curr) tgt))))
  (find l 0 tgt))
(display "  Index of '4' in list (1 3 5 7 9 2 4 6 8) = ")(index-of 4 '(1 3 5 7 9 2 4 6 8))

(define (add3 x) (+ 3 x))
(define (times2 x) (* 2 x))
(define (map-funct p l)
  (begin
    (define l2 (build-list (length l) (lambda (x) (p (list-ref l x)))))
    l2))
(display "  Map 'add3' to each element in list (1 2 3 4) = ")(map-funct add3 '(1 2 3 4))
(display "  Map 'times2' to each element in list (1 2 3 4) = ")(map-funct times2 '(1 2 3 4))

(displayln "SET FUNCTIONS")
;Test membership in a list/set
(define (mbr x set n)
  (if(>= n (length set)) #f
    (if(equal? (list-ref set n) x) #t
      (mbr x set (add1 n)))))
(display "  Is 'a' a member of list (b c a d)? ")(mbr 'a '(b c a d) 0)

;Insertion into a list/set, ignoring duplicates
(define (insert x set)
    (if(mbr x set 0) set (add-to-end x set)))
(display "  Insert '5' into list (1 2 3 4) = ")(insert 5 '(1 2 3 4))
(display "  Insert '3' into list (1 2 3 4) = ")(insert 3 '(1 2 3 4))

;Union of two lists/sets
(define (union s1 s2)
  (define (union s1 s2 u n)
    (if(>= n (length s1)) u
      (if(mbr (list-ref s1 n) s2 0)
        (union s1 s2 u (add1 n))
        (begin
          (set! u (add-to-end (list-ref s1 n) u))
          (union s1 s2 u (add1 n))))))
  (define u s2)
  (union s1 s2 u 0))
(display "  Union (unsorted) of lists (1 2 3 4) and (3 4 5 6) = ")(union '(1 2 3 4) '(3 4 5 6))

;Create set of factors
(define (f-set n)
  (define (f-set n i fset)
    (if(equal? i n)
      fset
      (begin
        (if(equal? (modulo n i) 0)
          (set! fset (f-set n (add1 i) (add-to-end i fset)))
          (set! fset (f-set n (add1 i) fset)))))
    fset)
  (define f '())
  (f-set n 1 f))
;(f-set 20)

(displayln "REQUIRED FUNCTIONS")
(define (perfect? n)
  (if(equal? n (foldl + 0 (f-set n))) #t #f))
(display "  Is 10 a perfect number? ")(perfect? 10)

(define (abundant? n)
  (if(< n (foldl + 0 (f-set n))) #t #f))
(display "  Is 10 an abundant number? ")(abundant? 10)

(define (deficient? n)
  (if(> n (foldl + 0 (f-set n))) #t #f))
(display "  Is 10 a deficient number? ")(deficient? 10)
