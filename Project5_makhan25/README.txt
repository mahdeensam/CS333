CS333 - Project 5 - README
Mahdeen Ahmed Khan Sameer
Professor Max Bender
10 April 2024

Google Site: https://sites.google.com/colby.edu/sameer-again/home

Abstract:
In this project, we explored the concepts of polymorphism and generic data structures across multiple programming languages including C, JavaScript, and Scala. I found it particularly enlightening to apply these concepts distinctly in each language. The project covers the implementation of generic linked lists, stacks, and shapes using polymorphic constructs that underline the versatile application of object-oriented programming principles and memory management practices across different programming ecosystems.

Run and Build Configuration for C:
- Apple Clang Version: 14.0.0 (clang-1400.0.29.202)
- Target: arm64-apple-darwin21.6.0
- Thread Model: posix

Directory Layout:

.Project5_mahdeensk
├── .vscode
│   ├── settings.json
│   ├── tasks.json
├── LinkedList.c
├── linkedlist.h
├── lltest.c
├── extension1.scala
├── extension2.js
├── extension3.c
├── extension4.js
├── extension5.scala
├── extension6.scala
├── extension7.c
├── LinkedList.js
├── LinkedListTest.js
├── CS333 Project 5 - Report.pdf
└── README.txt

Extensions:
I undertook 7 extensions, each documented thoroughly in the project report, showcasing diverse implementations and enhancements to the data structures.

Detailed Results and Explanations:

Part 1 – Polymorphism in C:
- Files: LinkedList.c, linkedlist.h, lltest.c
- Overview: Implemented a generic linked list in C capable of handling various data types through function pointers enabling specialized data handling, crucial for operations like dynamic memory management for complex data types such as strings.

Results:
- Initialization and Squaring Operations:

After initialization:
value: 18 value: 16 value: 14 value: 12 value: 10 value: 8 value: 6 value: 4 value: 2 value: 0

After squaring:
value: 324 value: 256 value: 196 value: 144 value: 100 value: 64 value: 36 value: 16 value: 4 value: 0

- Removal Operations:

removed: 16
No instance of 11 found twice.

After removals:
value: 324 value: 256 value: 196 value: 144 value: 100 value: 64 value: 36 value: 4 value: 0

- Append and Clear Operations:

After append:
value: 324 value: 256 value: 196 value: 144 value: 100 value: 64 value: 36 value: 4 value: 0 value: 11

After clear:
[List is empty]

After appending (0-4):
value: 0 value: 1 value: 2 value: 3 value: 4

After popping:
value: 2 value: 3 value: 4
List size: 3

Part 2 – Polymorphism in JS:
- Files: LinkedList.js, LinkedListTest.js
- Overview: Showcased polymorphism in JavaScript through dynamic linked lists and shape objects, demonstrating universal application of methods like push, pop, and map with careful attention to error handling and memory leak prevention.

String Operations Results:
- Initialization and Removals:

String list after initialization:
value: CS333 Project 5 in JavaScript now! value: World value: Hello

Found and removed 'World':
Found: World
Removed: World

String list after removal:
value: CS333 Project 5 in JavaScript now! value: Hello

Acknowledgements:
I would like to thank Professor Bender and TA Nafis for their guidance and insights which were invaluable during the execution of this project. Their expertise helped me navigate through complex challenges and enhanced my learning experience.