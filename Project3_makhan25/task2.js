/**
 * Task 2: Sample JavaScript program implementing a binary search function 
 * on an array of numbers.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Professor: Max Bender
 * Date: 03/09/2024
 */

function binarySearch(arr, target) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    if (arr[mid] === target) {
      return mid; // Target found, return the index
    } else if (arr[mid] < target) {
      left = mid + 1; // Target is in the right half
    } else {
      right = mid - 1; // Target is in the left half
    }
  }

  return -1; // Target not found
}

// Modified example usage
const numbers = [3, 5, 7, 9, 11, 13, 15, 17, 19, 21]; // New set of numbers
const target = 15; // New target

const result = binarySearch(numbers, target);

if (result !== -1) {
  console.log(`Target ${target} found at index ${result}`);
} else {
  console.log(`Target ${target} not found in the array`);
}
