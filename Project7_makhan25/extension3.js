/*
 * File: garbage_collector.js
 * Author: Mahdeen Ahmed Khan Sameer
 * Course: CS333
 * Task: Project 7 - Extension 3
 * Purpose: This script demonstrates the concept of garbage collection in JavaScript.
 *          It creates an array, modifies its length to remove elements, and triggers garbage collection.
 */

/*
 * Function: garbage_c
 * Purpose: Demonstrates memory allocation and deallocation in JavaScript.
 *          Creates an array, modifies its length to remove elements, and leaves the memory for garbage collection.
 */
function garbage_c() {
  // Create an array and fill it with some elements
  let memory = ['filled', 'now'];

  // Print the array to verify its content
  console.log("Array before modification:", memory);

  // Modify the length of the array to remove elements
  memory.length = 2;

  // Print the array after modification
  console.log("Array after modification:", memory);
}

// Call the function to demonstrate garbage collection
garbage_c();
