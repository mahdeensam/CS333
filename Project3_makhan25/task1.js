/**
 * Task 1: Sample JavaScript program demonstrating identifier naming rules, variable declarations, and scoping.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Professor: Max Bender
 * Date: 03/09/2024
 */

// Valid identifier names
let myVariable = 10;      // camelCase variable name
const MY_CONSTANT = 20;   // Uppercase constant name
var _privateVar = 30;     // Variable name starting with an underscore
let $specialVar = 40;     // Variable name starting with a dollar sign

// Invalid identifier names
// let 1stVariable = 50;   // Invalid: Cannot start with a number
// let my-variable = 60;   // Invalid: Cannot contain hyphens
// const for = 70;         // Invalid: Cannot use reserved keywords

// Variable declarations
let x = 5;                // Declaration of a variable using 'let'
const y = 10;             // Declaration of a constant using 'const'
var z = 15;               // Declaration of a variable using 'var'

// Block scoping
if (true) {
  let blockVar = 100;     // Variable scoped within the block
  console.log(blockVar); // Output: 100
}
// console.log(blockVar); // Error: 'blockVar' is not defined outside the block

// Function scoping
function myFunction() {
  var functionVar = 200;  // Variable scoped within the function
  console.log(functionVar); // Output: 200
}
myFunction();
// console.log(functionVar); // Error: 'functionVar' is not defined outside the function

// Global scoping
globalVar = 300;          // Declaration of a global variable (not recommended)
console.log(globalVar);   // Output: 300

// Variable hoisting
console.log(hoistedVar);  // Output: undefined (variable hoisted but not initialized)
var hoistedVar = 400;     // Declaration and initialization of variable hoisted

// Const and let variables are not hoisted
// console.log(letVar);   // Error: Cannot access 'letVar' before initialization
let letVar = 500;         // Declaration and initialization of 'let' variable
