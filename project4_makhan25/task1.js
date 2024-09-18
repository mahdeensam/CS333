/**
 * Function: Control Flow Demonstrations in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript program demonstrates various control flow statements including if, if...else, 
 * if...else if...else, switch, for loop, while loop, do...while loop, continue, and try...catch...finally. 
 * It shows the syntax and usage of each control statement by implementing simple logic to describe 
 * the behavior and flow of control in the code.
 */

// if statement
let x = 5;
if (x > 0) {
    console.log("x is positive");
}

// if...else statement
let y = -5;
if (y > 0) {
    console.log("y is positive");
} else {
    console.log("y is not positive");
}

// if...else if...else statement
let z = 0;
if (z > 0) {
    console.log("z is positive");
} else if (z < 0) {
    console.log("z is negative");
} else {
    console.log("z is zero");
}

// switch statement
let grade = "B";
switch (grade) {
    case "A":
        console.log("Excellent!");
        break;
    case "B":
        console.log("Good job!");
        break;
    case "C":
        console.log("Well done!");
        break;
    default:
        console.log("Invalid grade");
}

// for loop
for (let i = 0; i < 5; i++) {
    console.log("Iteration:", i);
}

// while loop
let count = 0;
while (count < 3) {
    console.log("Count:", count);
    count++;
}

// do...while loop
let j = 10;
do {
    console.log("j:", j);
    j++;
} while (j < 15);

// 7. continue statement
for (let i = 0; i < 5; i++) {
    if (i === 2) {
        continue;
    }
    console.log("Continue example:", i);
}

// 8. try...catch...finally statement
try {
    throw new Error("An error occurred.");
} catch (error) {
    console.log("Caught an error:", error.message);
} finally {
    console.log("Finally block executed.");
}

