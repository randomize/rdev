;;;;
;;;; linalg.lisp
;;;;


(defpackage #:linalg 
  (:use :cl)
  (:export #:matrix:))

(in-package #:linalg)


(defclass matrix () 
  ((rows
     :initarg :rows
     :initform (error "Rows must be specified")
     :reader matrix-rows)
   (cols
     :initarg :cols
     :initform (error "Cols must be specified")
     :reader matrix-cols)
   (data
     :initarg :data
     :accessor matrix-data)))

(defmethod initialize-instance :after ((m matrix) &key generator )
  (assert (< 0 (matrix-rows m))
          nil 
          "Rows must be > 0")
  (assert (< 0 (matrix-cols m))
          nil 
          "Cols must be > 0")
  (if (slot-boundp m 'data)
    (progn 
      (assert  w)
      
      )
    
    )
  )
