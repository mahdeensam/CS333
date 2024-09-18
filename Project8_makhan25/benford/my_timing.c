/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Benford - Task 1)
May 2023

Purpose:
This file contains the implementation of a function that returns the current time in seconds.
The function utilizes the `gettimeofday` system call to obtain the time and converts it to a double.
This function is used to measure the execution time of the Benford's Law analysis program.
*/

#include <sys/time.h> // for get_time_sec
#include <time.h>

// Return the time in seconds
double get_time_sec()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
} // end get_time_sec

