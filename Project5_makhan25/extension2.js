/**
 * This file demonstrates the use of polymorphism in JavaScript through a poetic exploration
 * of shapes using a Haiku. It includes a base class, Shape, and two derived classes, Circle
 * and Square, which override the base class's area method to calculate their respective areas.
 * The haiku function celebrates these shapes' forms and areas, underscoring the concept of 
 * polymorphism.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

// Base class for geometric shapes
class Shape {
  constructor(name) {
      this.name = name;  // Name of the shape
  }

  area() {
      return "No area defined";  // Default area message
  }
}

// Derived class for circles
class Circle extends Shape {
  constructor(name, radius) {
      super(name);  // Call the superclass constructor with the name
      this.radius = radius;  // Radius of the circle
  }

  area() {
      return Math.PI * this.radius ** 2;  // Calculate area of the circle
  }
}

// Derived class for squares
class Square extends Shape {
  constructor(name, side) {
      super(name);  // Call the superclass constructor with the name
      this.side = side;  // Side length of the square
  }

  area() {
      return this.side ** 2;  // Calculate area of the square
  }
}

/**
* Generates a haiku for a given shape, highlighting its name and area, to illustrate
* polymorphism in action.
* @param {Shape} shape - The shape object (Circle or Square)
*/
function haiku(shape) {
  console.log(`${shape.name}, a wonder`);
  console.log(`Its area, a mystery`);
  console.log(`Polymorphism's key`);
  console.log(`Area: ${shape.area()}`);
}

// Example usage:
const circle = new Circle("Round and graceful", 5);  // Create a Circle object
const square = new Square("Strong and steady", 7);   // Create a Square object

// Display the haiku for each shape
haiku(circle);
console.log("---");
haiku(square);

// Expected Output:
// Round and graceful, a wonder
// Its area, a mystery
// Polymorphism's key
// Area: 78.53981633974483
// ---
// Strong and steady, a wonder
// Its area, a mystery
// Polymorphism's key
// Area: 49
