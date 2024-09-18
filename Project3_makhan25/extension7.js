/**
 * Extension 7: Demonstrating first-class functions in JavaScript.
 * Functions are first-class citizens, allowing them to be assigned to variables.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Professor: Max Bender
 * Date: 03/09/2024
 */

// Function declaration
function greet(name) {
  console.log(`Hello, ${name}!`);
}

// Assigning a function to a variable
const sayHello = greet;

// Calling the function using the variable
sayHello("John"); // Output: Hello, John!

// Assigning an anonymous function to a variable using ES6 arrow function syntax
const multiply = (a, b) => {
  return a * b;
};

// Calling the function using the variable
const num1 = 3;
const num2 = 4;
console.log(`Multiplication of ${num1} and ${num2} is:`, multiply(num1, num2)); // Output: Multiplication of 3 and 4 is: 12

// Assigning an arrow function to a variable
const square = x => {
  return x * x;
};

// Calling the function using the variable
const num = 5;
console.log(`Square of ${num} is:`, square(num)); // Output: Square of 5 is: 25

