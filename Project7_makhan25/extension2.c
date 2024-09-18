/*
 * File: python_refcount.c
 * Author: Mahdeen Ahmed Khan Sameer
 * Course: CS333
 * Task: Project 7
 * Purpose: This program demonstrates reference counting in Python using the Python C API.
 *          It includes functions to increment and decrement the reference count of Python objects
 *          and to create a new Python integer object.
 */

#include <Python.h>

/*
 * Function: increment_ref
 * Purpose: Increments the reference count of a given Python object.
 * Parameters:
 *     obj - the Python object whose reference count is to be incremented
 */
void increment_ref(PyObject *obj) {
    Py_INCREF(obj);
}

/*
 * Function: decrement_ref
 * Purpose: Decrements the reference count of a given Python object.
 * Parameters:
 *     obj - the Python object whose reference count is to be decremented
 */
void decrement_ref(PyObject *obj) {
    Py_DECREF(obj);
}

/*
 * Function: create_int_obj
 * Purpose: Creates a new Python integer object with the given value.
 * Parameters:
 *     value - the integer value to be used for the new Python integer object
 * Returns: A pointer to the newly created Python integer object.
 */
PyObject* create_int_obj(int value) {
    return PyLong_FromLong(value);
}

/*
 * Function: main
 * Purpose: Entry point of the program. Demonstrates reference counting with Python objects.
 */
int main() {
    // Initialize the Python interpreter
    Py_Initialize();

    // Create a new Python integer object
    PyObject *py_int = create_int_obj(42);
    printf("Created Python integer object with value: %ld\n", PyLong_AsLong(py_int));

    // Increment the reference count
    increment_ref(py_int);
    printf("Reference count after increment: %ld\n", py_int->ob_refcnt);

    // Decrement the reference count
    decrement_ref(py_int);
    printf("Reference count after decrement: %ld\n", py_int->ob_refcnt);

    // Decrement the reference count to trigger garbage collection
    decrement_ref(py_int);

    // Finalize the Python interpreter
    Py_Finalize();

    return 0;
}
