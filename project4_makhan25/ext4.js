/**
 * Function: Display Data Types in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript function, `display`, is designed to illustrate the handling of various data types in JavaScript.
 * It takes a single argument of any type and prints a message to the console based on the argument's type. The function
 * demonstrates conditional checks for strings, numbers, arrays, and falls back to a default case for other data types.
 * This example serves as a showcase for type checking, conditional logic, and the versatility of JavaScript in dealing
 * with different kinds of data inputs, emphasizing the language's dynamic type system and its utility for generic
 * data handling scenarios.
 */


function display(data) {
    if (typeof data === 'string') {
        console.log(`Given string is: ${data}`);
    } else if (typeof data === 'number') {
        console.log(`Given number is: ${data}`);
    } else if (Array.isArray(data)) {
        console.log(`Given array is: ${JSON.stringify(data)}`);
    } else {
        console.log(`Given data is of type: ${typeof data}`);
    }
}

display("Hello, world!");
display(42);
display([1, 2, 3]);
display({ key: "value" });

/* 
Output:
Given string is: Hello, world!
Given number is: 42
Given array is: [1,2,3]
Given data is of type: object
*/