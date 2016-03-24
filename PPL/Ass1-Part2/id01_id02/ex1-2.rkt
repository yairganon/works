#lang racket                   ;;
(provide (all-defined-out))    ;;
;; DO NOT EDIT ABOVE THIS LINE ;;
;;;;;;;;;;;;;;;;
;; Question 2 ;;
;;;;;;;;;;;;;;;;

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
(define heads-rec
  (lambda (lst)
    (if (empty? lst) '() (append (list (caar lst)) (heads-rec (cdr lst))))
    ))

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
(define heads-iter
  (lambda (lst)
    (heads-iter-helper lst '())
    ))

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests
(define heads-iter-helper (lambda (lst target)
    (if (empty? lst) target (heads-iter-helper (cdr lst) (append target (list (caar lst)))))))                       

;;;;;;;;;;;;;;;;
;; Question 3 ;;
;;;;;;;;;;;;;;;;

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
(define compose
  (lambda (fun-list x)
    (compose-helper (reverse fun-list) x)
    ))
; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
(define compose-helper
  (lambda (fun-list x)
    (display x) (newline)
    (if (empty? fun-list) x (compose-helper (cdr fun-list) ((car fun-list) x)))
    ))
;;;;;;;;;;;;;;;;
;; Question 4 ;;
;;;;;;;;;;;;;;;;

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
(define iter-tree
  (lambda (tree iter)
    (iter tree)
    ))
; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
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

; Signature:
; Type:
; Purpose:
; Pre-conditions:
; Tests:
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