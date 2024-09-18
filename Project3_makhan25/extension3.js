/**
 * Extension 3: Comparing Code in Python and JS
 * 
 * Demonstrates a comprehensive approach to comparing numbers in JavaScript, incorporating 
 * validation, documentation, and extended comparison features.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * Date: 03/09/2024
 */

/**
 * Compares two numbers and logs the relationship between them.
 * 
 * This function validates that the inputs are numbers, compares them, and logs whether
 * the first number is greater than, less than, or equal to the second number.
 * Additionally, it offers the ability to consider numbers equal if they are within a 
 * certain tolerance, accommodating floating point precision issues.
 * 
 * @param {number} a The first number to compare.
 * @param {number} b The second number to compare.
 * @param {number} [tolerance=0] Optional tolerance for considering two numbers as equal.
 */
function compareNumbers(a, b, tolerance = 0) {
  // Validate inputs to ensure they are numbers
  if (typeof a !== 'number' || typeof b !== 'number') {
      console.error('Both inputs must be numbers.');
      return;
  }

  // Adjust for tolerance
  const diff = Math.abs(a - b);
  
  if (diff <= tolerance) {
      console.log(`${a} is approximately equal to ${b}`);
  } else if (a > b) {
      console.log(`${a} is greater than ${b}`);
  } else {
      console.log(`${a} is less than ${b}`);
  }
}

// Example usage
const num1 = 10;
const num2 = 5;
const tolerance = 0.1;

compareNumbers(num1, num2);
compareNumbers(num1, 10.05, tolerance); // Example showing tolerance in action
