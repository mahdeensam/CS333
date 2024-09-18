CS333 - Project 1 - README
Mahdeen Ahmed Khan Sameer
02/22/2024
Google Sites URL: https://sites.google.com/colby.edu/sameer-again/home

Directory Layout:
Project1_makhan25/
|
│   ├── ex1.c
│   ├── ex2.c
│   ├── ex3.c
│   ├── ex4.c
│   ├── ex5.c
│   ├── task01.c
│   ├── task02.c
│   ├── task03.c
│   ├── task04.c
│   ├── task05.c
|
├── README.txt
├── CS333 Project01.pdf

Run and build configuration for C:
Operating System: macOS Monterey 12.6
Compiler: Apple clang version 15.0.0

To compile and run tasks, use VSCode with the C/C++ Extension, streamlining the development process.

Extensions:
Extension 01:

When we compile and execute the given C program, our system might encounter a bus error while writing to a misaligned char pointer, as the specified address (0x1) does not meet the memory alignment requirements for larger data types. On the other hand, a segmentation fault may occur while writing to an int pointer targeting an invalid or inaccessible memory address (0xFFFFFFFF). The distinction lies in the fact that bus errors result from violations of the hardware's alignment constraints, whereas segmentation faults arise from unauthorized memory access, which is restricted by the operating system's protective measures. It's important to note that such a program is prone to crash and deliberately triggering these errors is generally discouraged in software development. The actual outcome—whether a bus error, a segmentation fault, or neither—varies depending on the operating system and hardware, as they have different methods of managing such erroneous operations.

Extension 02:

In our exploration of floating-point numbers in C, we discovered a phenomenon regarding the precision limits of `float` and `double` data types. By incrementally doubling a starting value of 1.0, we searched for the smallest number where adding one no longer alters its value, highlighting the limits of floating-point precision. For the `float` type, this threshold was reached at 16777216.000000, and for `double`, the limit was found to be approximately 9.0072e+15. This experiment underscores the finite precision with which these data types can represent numbers, a consequence of their underlying binary representation and storage in computer memory. It illustrates a practical example of numerical analysis principles, specifically the concept of machine epsilon, which is the smallest difference between two representable numbers, beyond which additional precision is lost.

Extension 03:


In our revised version of the program, we have opted to take the account name directly from the command line arguments, specifically argv[1], to populate the name field of the Account struct. We use strncpy to safely copy the provided name into the struct, ensuring it fits within the designated space and avoiding buffer overflow by explicitly null-terminating the string. This method enhances the program's flexibility and user-friendliness, as it eliminates the need for interactive input and potential errors associated with scanf, streamlining the process for the user to establish a new bank account directly from the command line when running the program.

Extension 04:

	What we have to do is comment out when we are trying to compile. In C programming, we can generate a variety of run-time errors that each teach us about the importance of proper memory and error management. A division by zero error occurs when we attempt to divide an integer by zero, which is undefined behavior and can cause a program to crash. Null pointer dereference errors are the result of attempting to read or write to a memory location pointed to by a null pointer, indicative of uninitialized or improperly managed memory. Dangling pointer errors, or invalid pointer accesses, happen when we try to use a pointer that has been freed, leading to undefined behavior or crashes due to corruption of memory. Stack overflow errors are typically caused by uncontrolled recursion, where function calls accumulate on the stack without end, eventually exceeding the stack's limit. Heap overflow errors occur when we repeatedly allocate large blocks of memory without freeing them, which can exhaust available memory resources. These run-time errors underscore the critical need for careful checking and handling of inputs, diligent memory allocation and deallocation, and robust error checking in C programs to prevent crashes and undefined behavior.

Extension 05:
(Also found in google site)
	R is a programming language and environment specifically designed for statistical computing and graphics. It was created by Ross Ihaka and Robert Gentleman in August 1993 at the University of Auckland and was conceived as an implementation similar to the S language developed at Bell Laboratories. R's primary purpose is to provide an open-source route to statistical methodology and data analysis, with the ability to produce publication-quality graphics. The main uses of R span across various statistical domains, including linear and nonlinear modeling, time-series analysis, classification, clustering, and more. It is highly extensible, allowing users to add new functions and features. R is particularly favored for producing well-designed, publication-quality plots with great control over design choices. As an interpreted language, R facilitates immediate execution of code without the need for compilation, which makes it suitable for interactive work in statistics. It also supports procedural, object-oriented, functional, reflective, and imperative programming paradigms. R is open-source software, licensed under the GNU General Public License, which means it's freely available for anyone to use, modify, and distribute. It runs on various UNIX platforms, Windows, and macOS, ensuring wide accessibility and utility.

