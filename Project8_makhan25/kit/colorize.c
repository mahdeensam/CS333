/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Task 2: Colorize)
May 2023

Purpose:
This program processes an image to colorize it based on the brightness of the original pixels.
The image is read from a PPM file, and each pixel's RGB values are adjusted based on their original values.
The program measures and prints the computation time taken to process the image and writes the processed 
image to a new file.

Usage:
To run this program, provide the image filename as a command-line argument:
    ./program_name <image filename>
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For timing
#include "ppmIO.h"

int main(int argc, char *argv[]) {
    Pixel *src;
    int rows, cols, colors;
    struct timeval start, end;
    double elapsedTime;

    // Check usage
    if (argc < 2) {
        printf("Usage: %s <image filename>\n", argv[0]);
        exit(-1);
    }

    // Read image and check for errors
    src = ppm_read(&rows, &cols, &colors, argv[1]);
    if (!src) {
        printf("Unable to read file %s\n", argv[1]);
        exit(-1);
    }

    // Start timing
    gettimeofday(&start, NULL);

    // Process image
    for (int i = 0; i < rows * cols; i++) {
        src[i].r = src[i].r > 128 ? (220 + src[i].r) / 2 : (30 + src[i].r) / 2;
        src[i].g = src[i].g > 128 ? (220 + src[i].g) / 2 : (30 + src[i].g) / 2;
        src[i].b = src[i].b > 128 ? (220 + src[i].b) / 2 : (30 + src[i].b) / 2;
    }

    // End timing
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Write out the processed image
    ppm_write(src, rows, cols, colors, "bold.ppm");

    // Free memory
    free(src);
    printf("Computation time: %.6f seconds\n", elapsedTime);

    return 0;
}
