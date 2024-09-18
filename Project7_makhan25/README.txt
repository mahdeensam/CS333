Mahdeen Ahmed Khan Sameer  
Professor Max Bender  
CS333  
May 2024

Project 07: Memory Management in Programming Languages

Google site: [https://sites.google.com/colby.edu/sameer-again/home](https://sites.google.com/colby.edu/sameer-again/home)

Run and Build Configuration for C:
- Operating System: macOS Monterey 12.6
- Compiler: Apple clang version 15.0.0

Directory Layout:

.Project07_makhan25
├── detect_garbage.c
├── extension2.c
├── extension04.c
├── extension06.c
├── extension07.c
├── extension07.py
├── graph.py
├── graph2.py
├── profile.txt
├── README.txt
└── task1.c

Tasks:

Task 01:
Analyzed the efficiency of memory allocation in C by comparing chunk allocation and all-at-once allocation. Experiments with varying memory sizes revealed that allocating all bytes at once is significantly faster and less variable. For instance, at 100,000 integers, chunk allocation averaged 6713.94 ns with a standard deviation of 2522.05 ns, while all-at-once averaged 753.00 ns with a standard deviation of 1851.51 ns. Graphs and detailed analysis further confirm that all-at-once allocation is the more efficient strategy.

Task 02:
Implemented a Mark and Sweep Garbage Collector, tested it with examples showing stack variables and reference cycles. The garbage collector successfully identified and removed unreachable HeapChunks, demonstrating its effectiveness over reference counting, which failed to identify cyclic garbage.

Extensions:

Extension 01:
Provided a detailed explanation of glibc's memory management functions, "malloc" and "free," covering their algorithms, alignment requirements, and coalescing to improve memory utilization.

Extension 02:
Demonstrated reference counting in C interfacing with Python. Created Python integer objects, manipulated their reference counts using "Py_INCREF" and "Py_DECREF," and observed the behavior. This highlighted the importance of understanding Python's internal optimizations in reference counting.

Extension 04:
Combined a haiku on memory management with a practical C program. The haiku emphasizes allocation, pointer management, and avoiding memory leaks. The accompanying code demonstrates these concepts by allocating and freeing memory for an array of integers.

Extension 05:
Used "gprof" to profile the code. After installing and configuring "gprof," compiled the code with the "-pg" flag and generated a profile report. The report showed that 81% of execution time was spent in the "example_usage" function, highlighting it as a target for optimization.

Extension 06:
Ensured C data structures do not leak memory using Valgrind. The program (extension06.c) allocates and frees memory for an array of integers. Valgrind confirmed no memory leaks, validating proper memory management.

Extension 07:
Explored reference counting when interfacing C with Python using the Python C API and ctypes. The C code manipulates Python object reference counts, and the Python code interacts with these C functions, ensuring accurate reference counting and proper memory management.

Collaborators & Acknowledgements:
- Professor Max Bender
- TA Nafis

Their guidance was instrumental in the successful completion of this project.