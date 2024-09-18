CS333 - Project 3 - README
Author: Mahdeen Ahmed Khan Sameer
Date: 03/09/2024
Google Sites URL: https://sites.google.com/colby.edu/sameer-again/home

Run and Build Configuration for C:  
- Operating System: macOS Monterey 12.6  
- Compiler: Apple clang version 15.0.0  


Directory Layout:

.Project3_makhan25
├── cstk.c
├── cstk.h
├── cstktest.c
├── extension1.js
├── extension2.js
├── extension3.js
├── extension3.py
├── extension4.js
├── extension5.js
├── extension6.js
├── extension7.js
├── extension8.c
├── extension9.lisp
├── extension10.vhd
├── video.mov
├── README.txt
├── toDraw.c
├── task1.js
├── task2.js
└── task3.js

Part 01:
We start by implementing a stack data structure using arrays in C. We define the structure of our stack in the cstk.h header file, containing declarations for essential stack operations such as creation, checking if it's empty or full, adding and removing elements, displaying the stack, destroying the stack, and copying the stack. These functions are implemented in the cstk.c file. We utilize the cstktest.c file to test our stack implementation, ensuring it passes all tests successfully. Additionally, we explore memory management, demonstrating the prevention of memory leaks with our stack implementation. A video (video.mov) showcases the efficient memory usage of our program.

Part 02:

Task 1:

File: cstk.h  
Description: The cstk.h file contains the declarations for essential operations related to the stack data structure implemented in C. These declarations include functions for creating a stack, checking if it's empty or full, adding and removing elements, displaying the stack, destroying the stack, and copying the stack.  
Output: No output generated directly from this file. It serves as a header file providing prototypes for functions defined elsewhere.

Task 2:

File: cstk.c  
Description: The cstk.c file contains the implementations of functions declared in cstk.h for managing a stack data structure using arrays in C. These implementations include creating, checking if the stack is empty or full, adding and removing elements, displaying the stack, destroying the stack, and copying the stack.  
Output: No output generated directly from this file. It serves as the source file providing definitions for functions declared in cstk.h.

Task 3:

File: cstktest.c  
Description: The cstktest.c file contains a test program to verify the functionality of the stack implementation in cstk.c. It includes various test cases to ensure that stack operations behave as expected, such as creating a stack, adding and removing elements, and verifying stack properties.  
Output: Output generated from running this file includes messages indicating the success or failure of each test case, confirming whether the stack operations are functioning correctly.


Extensions:

Extension 01: We implement a Stack data structure in JavaScript, enhancing it with dynamic resizing to overcome fixed-size limitations.

Extension 02: We explore JavaScript's features, including template literals, arrow functions, and async/await syntax, highlighting its expressive capabilities.

Extension 03: Python and JavaScript comparisons emphasize differences in syntax and language characteristics, covering variable declaration, string manipulation, and output methods.

Extension 04: We demonstrate linear search using JavaScript's indexOf() method, showcasing efficient array element search operations.

Extension 05: Complex JavaScript code illustrates the importance of readability and clarity in programming, highlighting the consequences of obscure coding practices.

Extension 06: An artistic blend of JavaScript code and poetry showcases dynamic poem generation, reflecting the beauty of nature through program execution.

Extension 07: JavaScript's treatment of functions as first-class citizens is explored, emphasizing their flexibility and utility in programming.

Extension 08: We enhance the robustness of our C stack implementation by implementing dynamic resizing and additional functions for improved functionality.

Extension 09: We translate tasks 1, 2, and 3 into Lisp, covering identifier naming, scoping, basic types, and aggregate data structures.

Extension 10: Tasks 1, 2, and 3 are converted into VHDL, illustrating naming conventions, scoping, and data types in a hardware description language.

