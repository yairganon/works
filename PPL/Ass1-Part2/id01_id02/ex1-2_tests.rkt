#lang racket

(require "utils.rkt")
(require "ex1-2.rkt")

(define (q2-tests)
  (run-tests
   (test (heads-rec '((1))) => '(1))
   (test (heads-rec '((1 little) (2 little) (3 little indians))) => '(1 2 3))
   (test (heads-rec '((Never has a man influenced physics so profoundly as Niels Bohr in the early 1900s.)
                      (going back to this time period, little was known about atomic structure. Bohr set out)
                      (to end the obscurity of physics. However, things didn’t come easy for Bohr. He had to)
                      (give up most of his life for physics and research of many hypothesis. But, this is why)
                      (you and I have even heard of the quantum theory and atomic structures. Bohr came)
                      (up with his quantum theory while studying at Cambridge. Bohr was a sceptic and he ))) => '(Never going to give you up))
   (test (heads-iter '((1))) => '(1))
   (test (heads-iter '((Never has a man influenced physics so profoundly as Niels Bohr in the early 1900s.)
                      (going back to this time period, little was known about atomic structure. Bohr set out)
                      (to end the obscurity of physics. However, things didn’t come easy for Bohr. He had to)
                      (give up most of his life for physics and research of many hypothesis. But, this is why)
                      (you and I have even heard of the quantum theory and atomic structures. Bohr came)
                      (up with his quantum theory while studying at Cambridge. Bohr was a sceptic and he ))) => '(Never going to give you up))
   (test (heads-iter '((1 little) (2 little) (3 little indians))) => '(1 2 3))
   ))


(define (q3-tests)
  (run-tests
   (test (compose (list) 5) => 5)
   (test (compose (list (lambda (x) x)) 5) => 5)
   (test (compose (list add1 sqr) 5) => 26)
   (test (compose (list sqr add1) 5) => 36)
   (test (compose (list (lambda (x) (* 2 x)) (lambda (x) (* 2 x)) (lambda (x) (* 2 x))) 5) => 40)
   ))

(define (q4-tests)
  (run-tests
   (test (iter-tree '(F (B A (D C E)) (G () (I H ()))) pre-iter) => '(F B A D C E G I H))
   (test (iter-tree '(F (B A (D C E)) (G () (I H ()))) in-iter) => '(A B C D E F G H I))
   ))

(q2-tests)
(q3-tests)
(q4-tests)
