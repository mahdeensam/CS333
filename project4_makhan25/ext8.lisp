;;; Dynamic Function Handling in Lisp
;;; Mahdeen Ahmed Khan Sameer
;;; Professor Max Bender
;;; 03/23/2024
;;;
;;; This Lisp code snippet demonstrates the flexibility of functions in Lisp, showcasing the dynamic assignment 
;;; of functions to variables, passing functions as arguments to other functions, and calling them. It includes 
;;; examples of defining a greeting function, assigning it to a variable, and using it in various contexts, including 
;;; passing it to another function to execute. This illustrates Lisp's powerful capabilities for functional programming, 
;;; treating functions as first-class citizens that can be manipulated and used in diverse ways, emphasizing the language's 
;;; adaptability and expressive power in handling functions dynamically.

;; Assigning a function to a variable
(defvar greet (lambda (name) (format t "Hello, ~A!~%" name)))

;; Calling the function assigned to the variable
(funcall greet "John")

;; Passing a function to another function
(defun say-something (func name)
  (funcall func name))

(say-something greet "Alice")

;; Defining and calling a function directly as an argument
(say-something (lambda (name) (format t "Hi, ~A!~%" name)) "Bob")
