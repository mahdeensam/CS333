;;; Function: QuickSort Implementation in Lisp
;;; Mahdeen Ahmed Khan Sameer
;;; Professor Max Bender
;;; 03/23/2024
;;;
;;; This Lisp program implements the QuickSort algorithm, utilizing a custom comparator function
;;; to allow for sorting of lists of any type according to the provided comparison logic. It includes
;;; example comparator functions for sorting both numbers and strings in ascending order. The demonstration
;;; of sorting numeric and string lists exemplifies the power and flexibility of Lisp for algorithmic
;;; implementation and data manipulation, showcasing the language's capabilities in handling functional
;;; programming paradigms and list processing.


(defun quick-sort (lst comparator)
  (if (<= (length lst) 1)
      lst
      (let* ((pivot (nth (floor (/ (length lst) 2)) lst))
             (left (remove pivot lst :test (lambda (a b) (funcall comparator a b))))
             (right (remove-if-not (lambda (x) (funcall comparator x pivot)) lst)))
        (append (quick-sort left comparator) (list pivot) (quick-sort right comparator)))))

;; Example comparators
(defun number-comparator (a b)
  (< a b))

(defun string-comparator (a b)
  (string< a b))

;; Example usage
(let ((numbers '(5 3 9 1 7)))
  (format t "Original numbers: ~A~%" numbers)
  (format t "Sorted numbers: ~A~%" (quick-sort numbers #'number-comparator)))

(let ((strings '("banana" "apple" "orange" "grape")))
  (format t "Original strings: ~A~%" strings)
  (format t "Sorted strings: ~A~%" (quick-sort strings #'string-comparator)))
