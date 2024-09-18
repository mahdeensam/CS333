/**
 * This JavaScript file illustrates two distinct methods for implementing a generic stack:
 * one using a class-based approach, and the other using a closure-based approach. Each method
 * has its advantages and potential drawbacks.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

{
  // Class-based implementation of a generic stack
  class Stack {
    constructor() {
      this.items = [];  // Internal storage for stack items
    }
    
    // Adds an item to the top of the stack
    push(item) {
      this.items.push(item);
    }
    
    // Removes the item at the top of the stack and returns it
    pop() {
      return this.items.pop();
    }
    
    // Returns true if the stack is empty, false otherwise
    isEmpty() {
      return this.items.length === 0;
    }
    
    // Returns the number of items in the stack
    size() {
      return this.items.length;
    }
  }
  
  // Example usage of the class-based stack
  const stack = new Stack();
  stack.push("Hello");
  stack.push(10);
  stack.push(true);
  console.log("Class-based Stack Test:");
  console.log("Popped item: ", stack.pop()); // Output: true
  console.log("Current size: ", stack.size()); // Output: 2
  console.log("Is empty: ", stack.isEmpty()); // Output: false
  console.log("---");
}

{
  // Closure-based implementation of a generic stack
  function createStack() {
    const items = [];  // Private array to store stack items
  
    return {
      push(item) {
        items.push(item);
      },
      pop() {
        return items.pop();
      },
      peek() {
        return items[items.length - 1];
      },
      isEmpty() {
        return items.length === 0;
      },
      size() {
        return items.length;
      }
    };
  }
  
  // Example usage of the closure-based stack
  const stack = createStack();
  stack.push(1);
  stack.push(2);
  console.log("Closure-based Stack Test:");
  console.log("Peeked item: ", stack.peek()); // Output: 2
  console.log("Popped item: ", stack.pop());  // Output: 2
  console.log("Is empty: ", stack.isEmpty()); // Output: false
  console.log("Current size: ", stack.size()); // Output: 1
}

/**
 * Discussion of Approaches:
 * 
 * The class-based approach provides a clear and familiar syntax for those accustomed to OOP paradigms.
 * It is ideal for situations where multiple stack instances are needed, as each instance is an object
 * with its methods and properties. However, the internal stack data (items) is accessible and can be
 * manipulated directly due to JavaScript's handling of object properties, which might be a security concern.
 * 
 * The closure-based approach offers encapsulation and data privacy. The stack's items are hidden within
 * the scope of the createStack function and are not accessible from the outside, preventing accidental
 * or malicious alterations to the stack's content. This approach is beneficial when data privacy is a
 * priority, but it can be slightly less intuitive to those not familiar with closures and immediately-invoked
 * function expressions (IIFE).
 * 
 * Both implementations are generic and can handle items of any type, making them highly versatile for
 * various applications.
 */
