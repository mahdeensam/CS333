import ctypes

# Load the shared library
lib = ctypes.CDLL('./extension07.so')

# Define the argument and return types for the C functions
lib.increment_ref.argtypes = [ctypes.py_object]
lib.decrement_ref.argtypes = [ctypes.py_object]
lib.create_int_obj.restype = ctypes.py_object

# Example usage
if __name__ == "__main__":
    # Create a Python integer object
    py_int = lib.create_int_obj(42)
    
    # Increment reference count
    lib.increment_ref(py_int)
    print(f"Reference count after increment: {py_int.ob_refcnt}")
    
    # Decrement reference count
    lib.decrement_ref(py_int)
    print(f"Reference count after decrement: {py_int.ob_refcnt}")

    # Decrement reference count to trigger garbage collection
    lib.decrement_ref(py_int)
