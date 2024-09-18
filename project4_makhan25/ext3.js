/**
 * Exploration of Data Structures in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript snippet demonstrates the use of basic data structures including arrays and objects, 
 * with an emphasis on how to declare, populate, and access their elements. The examples cover a simple 
 * array of numbers to illustrate ordered collections, a straightforward object to represent structured 
 * data with key-value pairs, and a more complex nested object to show how data can be structured hierarchically.
 * Through these examples, the flexibility and power of JavaScript for managing and manipulating various types 
 * of data structures are highlighted, showcasing the language's capabilities for both simple and complex data handling.
 */


// Array example
let numbers = [1, 2, 3, 4, 5];
console.log("Array:", numbers);

// Object example
let person = {
    name: "John",
    age: 30,
    city: "New York"
};
console.log("Object:", person);

// Nested object example
let employee = {
    name: "Alice",
    department: {
        name: "Engineering",
        location: "San Francisco"
    },
    skills: ["JavaScript", "Python", "SQL"]
};
console.log("Nested Object:", employee);


// Passing a function to another function
function operate(operation, x, y) {
    return operation(x, y);
}
let result = operate(add, 7, 2);
console.log("Result of operate function:", result);

// Returning a function from another function
function createMultiplier(factor) {
    return function(num) {
      return num * factor;
    };
}
let double = createMultiplier(2);
console.log("Result of double function:", double(5)); // Output: 10
let triple = createMultiplier(3);
console.log("Result of triple function:", triple(5)); // Output: 15

// Anonymous function
let square = createMultiplier(2);
console.log("Result of square function:", square(4)); // Output: 16

// Function expression with a name (only accessible within its scope)
let divide = function divide(x, y) {
return x / y;
};
console.log("Result of divide function:", divide(10, 2)); // Output: 5