/**
 * Extension 2: Showcasing Different features of JS.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/09/2024
 */

// Example 1: Template Literals and Destructuring Assignment
// Demonstrates how to extract properties from an object and embed them in a string neatly.
const person = {
  name: "Sameer",
  age: 21,
  city: "Waterville"
};

const { name, age, city } = person;
console.log(`My name is ${name}, I'm ${age} years old, and I live in ${city}.`);

// Example 2: Arrow Functions and Higher-Order Functions
// Shows the use of arrow functions for concise syntax and map, reduce functions for array manipulation.
const numbers = [1, 2, 3, 4, 5];
const squaredNumbers = numbers.map(num => num ** 2);
console.log(squaredNumbers); // Output: [1, 4, 9, 16, 25]

const sum = numbers.reduce((acc, num) => acc + num, 0);
console.log(sum); // Output: 15

// Example 3: Closures and Immediately Invoked Function Expressions (IIFE)
// Utilizes IIFE to create a private count variable that can be modified using the returned object.
const counter = (function() {
let count = 0;

return {
  increment: function() { count++; },
  getCount: function() { return count; }
};
})();
counter.increment();
counter.increment();
console.log(counter.getCount()); // Output: 2

// Example 4: Prototypal Inheritance and Object Literals
// Illustrates JavaScript's prototypal inheritance model using objects and the __proto__ property.
const animal = {
speak: function() { console.log("The animal makes a sound."); }
};
const dog = {
__proto__: animal,
bark: function() { console.log("Woof!"); }
};
dog.speak(); // Output: The animal makes a sound.
dog.bark(); // Output: Woof!

// Example 5: Asynchronous Programming with Promises and Async/Await
// Demonstrates handling asynchronous operations with Promises and the async/await syntax for cleaner code.
function fetchData() {
return new Promise((resolve, reject) => {
  setTimeout(() => {
    const data = "Data from server";
    resolve(data);
  }, 2000);
});
}
async function processData() {
try {
  const data = await fetchData();
  console.log(data); // Output: Data from server
} catch (error) {
  console.error(error);
}
}
processData();
