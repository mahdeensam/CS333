Mahdeen Ahmed Khan Sameer  
Professor Max Bender  
CS333  
May 2024

Project 08: Parallel Programming in Programming Languages

Google site: https://sites.google.com/colby.edu/sameer-again/home

Run and Build Configuration for C:
- Operating System: macOS Monterey 12.6
- Compiler: Apple clang version 15.0.0

Directory Layout:

.Project08_makhan25
├── CS333 Project 08.pdf
├── README.txt
├── benford
│   ├── benford
│   ├── benford.c
│   ├── benford_sequential
│   ├── benford_sequential.c
│   ├── longer.bin
│   ├── longer_nonBenford.bin
│   ├── medium.bin
│   ├── my_timing.c
│   ├── my_timing.h
│   └── super_short.bin
├── ext2
├── ext2.c
├── ext3
├── ext3.c
├── ext4.py
├── ext5.py
├── ext6.py
└── kit
    ├── bold.ppm
    ├── bold_parallel.ppm
    ├── colorize.c
    ├── colorize_par
    ├── colorize_par.c
    ├── default.ppm
    ├── ext1
    ├── ext1.c
    ├── ppmIO.c
    └── ppmIO.h

Project 08 Report:

Task 01:
After running all six parallelized versions of the Benford program with the longer.bin file ten times, dropping the min and max, and calculating the average times, we summarized the results in the following table:

- Sequential Version (benford_sequential): 0.0211 seconds
- Global Counter Array Protected by Single Mutex: 0.0701 seconds
- Global Counter Array Protected by Array of Mutexes: 0.0217 seconds
- Local Counter Array, with Final Update Protected by Single Mutex: 0.0081 seconds
- Local Counter Array, with Final Update Protected by Array of Mutexes: 0.0070 seconds
- Global Counter Array of Arrays, Grouped by Thread, no Mutex: 0.0064 seconds
- Global Counter Array of Arrays, Grouped by Digit, no Mutex: 0.0050 seconds

The graph shows that almost all parallel versions outperform the sequential one, except for the first parallel version using a single mutex. This is due to significant synchronization overhead as threads compete for the mutex. Using an array of mutexes improves performance but still has some overhead. Versions using local counter arrays with a single mutex or array of mutexes show better performance by minimizing contention. The last two versions are the fastest, using smart work organization without mutexes, allowing threads to work independently.

Task 02:
We used pthreads to implement a pixel-wise operator for images. Average computation times, determined by recording five trials, discarding the min and max, and averaging the remaining three, are as follows:

- 1 Thread: 0.027310 seconds
- 2 Threads: 0.011911 seconds
- 4 Threads: 0.010185 seconds
- 8 Threads: 0.00779 seconds
- Sequential Version: 0.029333 seconds

Increasing the number of threads decreases the average computation time, with diminishing returns beyond 8 threads.

Extension 1:
We modified "colorize_par.c" to accept the number of threads as a command-line argument, removing the "NUM_THREADS" macro. The number of threads is read from "argv[2]". This streamlines adding or removing threads without recompilation. Testing confirmed consistent results, with more than 8 threads yielding diminishing returns. Computation times were: 4 threads (0.013480 seconds), 8 threads (0.011843 seconds), 16 threads (0.012370 seconds), 32 threads (0.011747 seconds), and 64 threads (0.012213 seconds).

Extension 2:
We developed a parallel matrix multiplication program. The task is divided into chunks (chunk_size = M / NUM_THREADS) and assigned to separate threads. Each thread processes a segment of the resulting matrix, combining the results to produce the final matrix.

Extension 3:
We explored semaphores in C parallel programming. Semaphores manage access to critical sections by multiple threads, allowing a specified number to access a resource simultaneously. We wrote a parallel program where four threads increment a shared counter, using semaphores to control access. This ensures threads increment the counter in a specific order, demonstrating proper synchronization.

Extension 4:
We created a program to illustrate parallel programming through a poem. Each line is processed by a separate thread, with a slight delay to simulate task completion time. Threads are started for each line and joined to ensure the main program waits for all to finish, demonstrating concurrent execution.

Extension 5:
We used multiple threads to increment a shared counter, with a mutex lock ensuring only one thread can access the critical section at a time. Each thread increments the counter three times, acquiring and releasing the mutex lock. The main program starts four threads, waits for all to finish, and prints the final counter value, demonstrating race condition prevention.

Extension 6:
We demonstrated parallel matrix multiplication using the "threading" module. Matrices "A" and "B" are initialized with random values, and matrix "C" is computed in parallel by dividing the rows of "A" among multiple threads. Each thread calculates its assigned subset of rows, and the results are combined to produce the final matrix.

Collaborators & Acknowledgements:  
Professor Max Bender, TA Nafis
