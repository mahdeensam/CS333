;; Mahdeen Ahmed Khan Sameer
;; Professor Max Bender
;; Date: 03/09/2024
;; Task 1

;; Valid identifier names
(def myVariable 10)       ; Defining a variable with a lowercase name
(def MY_CONSTANT 20)      ; Defining a constant with an uppercase name
(def _privateVar 30)      ; Defining a variable with an underscore prefix
(def $specialVar 40)      ; Defining a variable with a dollar sign prefix

;; Variable declarations
(def x 5)                 ; Defining a variable 'x' with the value 5
(def y 10.5)              ; Defining a variable 'y' with the value 10.5
(def z "Hello, LISP!")   ; Defining a variable 'z' with a string value

;; Block scoping
(if t
    (let ((blockVar 100)) ; Declaring a variable 'blockVar' within a block
      (print blockVar)))  ; Printing the value of 'blockVar'

;; Function scoping
(defun myFunction ()      ; Defining a function 'myFunction'
  (let ((functionVar 200)) ; Declaring a variable 'functionVar' within the function scope
    (print functionVar))) ; Printing the value of 'functionVar'

(myFunction)              ; Calling the function 'myFunction'

;; Class scoping
(defclass MyClass ()                   ; Defining a class 'MyClass'
  ((classVar :initform 300))           ; Defining a class variable 'classVar' with an initial value
  (:method printClassVar ()            ; Defining a method 'printClassVar' for 'MyClass'
    (print classVar)))                 ; Printing the value of 'classVar'

(def obj (make-instance 'MyClass))     ; Creating an instance 'obj' of 'MyClass'
(send obj 'printClassVar)             ; Invoking the 'printClassVar' method on 'obj'

;; Global scoping
(defparameter *globalVar* 400)        ; Defining a global parameter '*globalVar*' with the value 400
(print *globalVar*)                    ; Printing the value of '*globalVar*'

;; Task 2

;; Binary search function
(defun binarySearch (arr target)       ; Defining a binary search function 'binarySearch'
  (let ((left 0)                       ; Declaring a variable 'left'
        (right (- (length arr) 1)))    ; Declaring a variable 'right' and initializing it with the length of 'arr'
    (loop while (<= left right)        ; Looping while 'left' is less than or equal to 'right'
          do (let ((mid (+ left (floor (/ (- right left) 2)))))) ; Calculating the mid-point index
               (cond ((= (aref arr mid) target) (return mid))    ; Checking if the target is found at mid
                     ((< (aref arr mid) target) (setq left (1+ mid))) ; Adjusting 'left' if target is on the right
                     (t (setq right (1- mid)))))          ; Adjusting 'right' if target is on the left
    -1))                                   ; Returning -1 if target is not found

;; Example usage
(def numbers #(2 4 6 8 10 12 14 16 18 20)) ; Defining an array 'numbers'
(def target 12)                            ; Defining the target value
(let ((result (binarySearch numbers target))) ; Searching for 'target' in 'numbers'
  (if (not (= result -1))                    ; Checking if 'target' is found
      (format t "Target ~a found at index ~a" target result)
      (format t "Target ~a not found in the array" target)))

;; Task 3

;; Basic built-in types
(def num 10)           ; Defining an integer variable 'num'
(def dbl 3.14)         ; Defining a floating-point variable 'dbl'
(def bool t)           ; Defining a boolean variable 'bool'
(def chr #\A)          ; Defining a character variable 'chr'
(def str "Hello, LISP!") ; Defining a string variable 'str'

;; Aggregate types

;; Tuples
(def tuple '(1 "LISP" t))     ; Defining a tuple 'tuple'
(print (first tuple))         ; Printing the first element of 'tuple'
(print (second tuple))        ; Printing the second element of 'tuple'
(print (third tuple))         ; Printing the third element of 'tuple'

;; Arrays
(def arr #(1 2 3 4 5))        ; Defining an array 'arr'
(print (aref arr 0))          ; Printing the first element of 'arr'

;; Lists
(def list '(apple banana orange)) ; Defining a list 'list'
(print (first list))             ; Printing the first element of 'list'
(print (rest list))              ; Printing the rest of the elements of 'list'

;; Association Lists (Maps)
(def map '((a . 1) (b . 2) (c . 3))) ; Defining an association list 'map'
(print (cdr (assoc 'a map)))         ; Printing the value associated with 'a' in 'map'

;; Classes
(defclass Person ()                  ; Defining a class 'Person'
  ((name :initarg :name)             ; Defining a slot 'name'
   (age :initarg :age :accessor age))) ; Defining a slot 'age'

(def person (make-instance 'Person :name "Vamshi" :age 35)) ; Creating an instance of 'Person'
(print (slot-value person 'name))     ; Printing the value of 'name' slot
(print (age person))                  ; Printing the value of 'age' slot

;; Operators
(def a 10)                      ; Defining a variable 'a' with value 10
(def b 3)                       ; Defining a variable 'b' with value 3

(print (+ a b))                 ; Printing the sum of 'a' and 'b'
(print (- a b))                 ; Printing the difference of 'a' and 'b'
(print (* a b))                 ; Printing the product of 'a' and 'b'
(print (/ a b))                 ; Printing the quotient of 'a' and 'b'
(print (% a b))                 ; Printing the remainder of 'a' divided by 'b'

(def c 10.5)                    ; Defining a variable 'c' with value 10.5
(def d 3.2)                     ; Defining a variable 'd' with value 3.2

(print (+ c d))                 ; Printing the sum of 'c' and 'd'
(print (- c d))                 ; Printing the difference of 'c' and 'd'
(print (* c d))                 ; Printing the product of 'c' and 'd'
(print (/ c d))                 ; Printing the quotient of 'c' and 'd'

(def e "Hello")                 ; Defining a string variable 'e'
(def f "World")                 ; Defining a string variable 'f'

(print (concatenate 'string e ", " f)) ; Printing the concatenation of 'e', ", ", and 'f'
