/**
 * Function: Dynamic Function Definitions in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript file demonstrates dynamic function definitions and manipulation in JavaScript. 
 * It showcases how to define functions that can dynamically create other functions based on parameters, 
 * and how function names can be stored and called dynamically using string variables. This includes 
 * examples of calling a predefined function by name stored in a variable and creating a custom greeting 
 * function that can generate greetings with different messages. These examples highlight JavaScript's 
 * flexibility in handling functions and its capability to create more adaptable and dynamic code.
 */


// Dynamic function definition example
function greet(name) {
    console.log("Hello, " + name + "!");
}

// Function name stored in a variable
let dynamicFunctionName = "greet";
window[dynamicFunctionName]("John"); // Output: Hello, John!

// Dynamically creating a function
function createGreetingFunction(greeting) {
    return function(name) {
        console.log(greeting + ", " + name + "!");
    };
}

let customGreet = createGreetingFunction("Hola");
customGreet("Maria"); // Output: Hola, Maria!
