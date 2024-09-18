/**
 * Function: Function Types and Operations in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript program explores the concept of functions as first-class citizens in JavaScript.
 * It demonstrates assigning functions to variables, passing functions as arguments to other functions,
 * returning functions from other functions, and using anonymous functions. The program illustrates
 * the flexibility of JavaScript functions and how they can be manipulated and utilized in various ways,
 * showcasing their use as data types.
 */

// Assigning a function to a variable
let add = function(x, y) {
    return x + y;
};

// Calling the function assigned to the variable
console.log("Result of add function:", add(3, 5));

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
