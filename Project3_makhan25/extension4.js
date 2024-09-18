/**
 * Extension 4: Example of using the built-in capability for linear search in JS.
 * 
 * This version introduces a reusable function for linear search that not only finds the first occurrence of the target 
 * but also checks for multiple instances and provides detailed feedback on the search results.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * Date: 03/09/2024
 */

function findTargetInArray(array, target) {
  const indices = [];
  let index = array.indexOf(target);
  while (index !== -1) {
      indices.push(index);
      index = array.indexOf(target, index + 1);
  }

  if (indices.length === 0) {
      console.log(`Target ${target} not found in the array.`);
  } else if (indices.length === 1) {
      console.log(`Target ${target} found at index ${indices[0]}.`);
  } else {
      console.log(`Target ${target} found at indices ${indices.join(', ')}.`);
  }
}

// Example usage
const numbers = [2, 4, 6, 8, 10, 12, 14, 12, 16, 18, 20, 12]; // Modified to include multiple instances of '12'
const target = 12;

findTargetInArray(numbers, target);
