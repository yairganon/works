#lang racket                   ;;
(provide (all-defined-out))    ;;
;; DO NOT EDIT ABOVE THIS LINE ;;
;;;;;;;;;;;;;;;;
;; Question 2 ;;
;;;;;;;;;;;;;;;;

; Signature: heads-rec(lst)
; Type:[List(List) -> List]
; Purpose: Return the first element of each sublist
; Pre-conditions:Length of the sublists is at least 1
; Tests: (heads-iter '((3 4) (1 1))) ==> '(3 1)
(define heads-rec
  (lambda (lst)
    (if (empty? lst) '() (append (list (caar lst)) (heads-rec (cdr lst))))
    ))

; Signature: heads-iter(lst)
; Type:[List(List) -> List]
; Purpose: Return the first element of each sublist
; Pre-conditions:Length of the sublists is at least 1
; Tests: (heads-iter '((3 4) (1 1))) ==> '(3 1)
(define heads-iter
  (lambda (lst)
    (heads-iter-helper lst '())
    ))

; Signature: heads-iter-helper(lst,target)
; Type:[List(List)*List -> List]
; Purpose: Return the first element of each sublist
; Pre-conditions:Length of the sublists is at least 1
; Tests: (heads-iter '((3 4) (1 1))) ==> '(3 1)
(define heads-iter-helper (lambda (lst target)
    (if (empty? lst) target (heads-iter-helper (cdr lst) (append target (list (caar lst)))))))                       

;;;;;;;;;;;;;;;;
;; Question 3 ;;
;;;;;;;;;;;;;;;;

; Signature: compose(fun-list , x)
; Type: [List -> Number]
; Purpose: Applying the composition of all the functions on x
; Pre-conditions: fun-list is list of functions ,where each function accepts one parameter
; Tests:(compose (list (lambda (x) (+ x 1))(lambda (x) (* x x)))5) ==> 26
(define compose
  (lambda (fun-list x)
    (compose-helper (reverse fun-list) x)
    ))
; Signature: compose-helper(fun-list , x)
; Type: [List -> Number]
; Purpose: Applying the composition of all the functions on x
; Pre-conditions: fun-list is list of functions ,where each function accepts one parameter
; Tests:(compose (list (lambda (x) (+ x 1))(lambda (x) (* x x)))5) ==> 26
(define compose-helper
  (lambda (fun-list x)
    (display x) (newline)
    (if (empty? fun-list) x (compose-helper (cdr fun-list) ((car fun-list) x)))
    ))
;;;;;;;;;;;;;;;;
;; Question 4 ;;
;;;;;;;;;;;;;;;;

; Signature: iter-tree(tree , iter)
; Type:[List -> List]
; Purpose: print labeled tree in specifc order.
; Pre-conditions:iter is a a traversal strategy in the form of a procedure. tree is a  a labeled tree.
; Tests:(iter-tree '(1 (#f 21 a) (3 b 32)) pre-iter) ==>'(1 #f 21 a 3 b 32) , (iter-tree '(1 (#f 21 a) (3 b 32)) in-iter) ==>'(21 #f a 1 b 3 32)
(define iter-tree
  (lambda (tree iter)
    (iter tree)
    ))
; Signature:pre-iter(tree)
; Type:[List -> List]
; Purpose: returns a list of the labels of the subtree in pre-order.
; Pre-conditions:tree is a  a labeled tree.
; Tests:(pre-iter '(1 (#f 21 a) (3 b 32))) ==>'(1 #f 21 a 3 b 32)
(define pre-iter
  (lambda (tree)
        (if (list? tree)
            (if (=(length tree)1) 
                            (pre-iter (car tree))
                            (if (=(length tree)0)
                                tree 
                                (append (list (car tree)) (pre-iter  (cadr tree)) (pre-iter (cddr tree)))
                                )
                            )
            (list tree)
            )
    )
  )

; Signature:in-iter(tree)
; Type:[List -> List]
; Purpose: returns a list of the labels of the subtree in in-order.
; Pre-conditions:tree is a  a labeled tree.
; Tests:(in-iter '(1 (#f 21 a) (3 b 32))) ==>'(21 #f a 1 b 3 32)
(define in-iter
  (lambda (tree)
        (if (list? tree)
            (if (=(length tree)1) 
                            (in-iter (car tree))
                            (if (=(length tree)0)
                                tree 
                                (append (in-iter  (cadr tree))  (list (car tree)) (in-iter (cddr tree)))
                                )
                            )
            (list tree)
            )
    )
  )