/**
 * Task 3: Sample program in JS that demonstrates the basic built-in types,
 * aggregate types, operators, and additional features for a more comprehensive understanding.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/09/2024
 */

// Basic built-in types
let num = 10;                         // Number
let str = "Hello, world!";            // String
let bool = true;                      // Boolean
let undef = undefined;                // Undefined
let nul = null;                       // Null
let bigInt = 9007199254740991n;       // BigInt
let sym = Symbol("a unique value");   // Symbol

// Aggregate types
// Arrays
let arr = [1, 2, 3, 4, 5];
console.log(`First element: ${arr[0]}`);          // Output: First element: 1

// Enhanced Array operations
console.log(`Array length: ${arr.length}`);       // Output: Array length: 5
arr.push(6);                                      // Adding an element
console.log(`Added element: ${arr[5]}`);          // Output: Added element: 6

// Objects (similar to records or structures)
let obj = {
  name: "Sameer",
  age: 30,
  city: "Waterville"
};
console.log(`Name: ${obj.name}, City: ${obj.city}`);        // Output: Name: Sameer, City: Waterville

// Object destructuring
const {name, age, city} = obj;
console.log(`Age of ${name} from ${city}: ${age}`);         // Output: Age of Sameer from Waterville: 30

// Classes
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  sayHello() {
    console.log(`Hello, my name is ${this.name} and I'm ${this.age} years old.`);
  }
}

let person = new Person("Sameer", 21);
person.sayHello();            // Output: Hello, my name is Sameer and I'm 21 years old.

// Operators
// Using template literals for more readable arithmetic operations output
console.log(`5 + 3 = ${5 + 3}`);    // Output: 5 + 3 = 8
console.log(`10 - 4 = ${10 - 4}`);  // Output: 10 - 4 = 6

// String concatenation with template literals
console.log(`Concatenated String: ${"Hello, " + "world!"}`);  // Output: Concatenated String: Hello, world!

// Demonstrating additional operators
console.log(`Typeof operator: ${typeof str}`); // Output: Typeof operator: string
console.log(`Ternary operator: ${num > 5 ? "greater" : "less"}`); // Output: Ternary operator: greater

