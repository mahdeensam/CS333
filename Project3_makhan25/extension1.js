/**
 * Implementation of a Stack in JavaScript, inspired by a C-style stack implementation.
 * This class provides a flexible stack data structure with dynamic resizing capability
 * to manage elements in a last-in, first-out (LIFO) manner.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Professor: Max Bender
 * Date: 03/09/2024
 */
class Stack {
  /**
   * Creates an instance of Stack with a specified initial capacity.
   * @param {number} capacity Initial capacity of the stack.
   */
  constructor(capacity) {
    this.data = new Array(capacity); // Stores the stack's elements.
    this.top = -1; // Points to the top element in the stack.
    this.capacity = capacity; // Current maximum capacity of the stack.
  }

  /**
   * Checks if the stack is empty.
   * @returns {boolean} True if the stack is empty, false otherwise.
   */
  isEmpty() {
    return this.top === -1;
  }

  /**
   * Checks if the stack is full.
   * @returns {boolean} True if the stack has reached its capacity, false otherwise.
   */
  isFull() {
    return this.top === this.capacity - 1;
  }

  /**
   * Adds a new element to the top of the stack.
   * @param {*} value The value to be pushed onto the stack.
   */
  push(value) {
    if (this.isFull()) {
      this.resize(); // Resize the stack if it's full.
    }
    this.top++;
    this.data[this.top] = value;
  }

  /**
   * Returns the top element of the stack without removing it.
   * @returns {*} The top element of the stack or undefined if the stack is empty.
   */
  peek() {
    if (this.isEmpty()) {
      console.log("Warning: Stack is empty. Returning undefined.");
      return undefined;
    }
    return this.data[this.top];
  }

  /**
   * Removes and returns the top element of the stack.
   * @returns {*} The removed top element of the stack or undefined if the stack is empty.
   */
  pop() {
    if (this.isEmpty()) {
      console.log("Warning: Stack is empty. Returning undefined.");
      return undefined;
    }
    const value = this.data[this.top];
    this.top--;
    return value;
  }

  /**
   * Prints the elements of the stack.
   * @param {boolean} reverse If true, prints the stack in reverse order.
   */
  display(reverse = false) {
    if (reverse) {
      for (let i = this.top; i >= 0; i--) {
        console.log(this.data[i]);
      }
    } else {
      for (let i = 0; i <= this.top; i++) {
        console.log(this.data[i]);
      }
    }
  }

  /**
   * Creates a copy of the current stack.
   * @returns {Stack} A new Stack instance with the same elements.
   */
  copy() {
    const newStack = new Stack(this.capacity);
    for (let i = 0; i <= this.top; i++) {
      newStack.push(this.data[i]);
    }
    return newStack;
  }

  /**
   * Doubles the stack's capacity.
   */
  resize() {
    const newCapacity = this.capacity * 2;
    const newData = new Array(newCapacity);
    for (let i = 0; i <= this.top; i++) {
      newData[i] = this.data[i];
    }
    this.data = newData;
    this.capacity = newCapacity;
  }

  /**
   * Returns the number of elements in the stack.
   * @returns {number} The size of the stack.
   */
  size() {
    return this.top + 1;
  }

  /**
   * Returns the current capacity of the stack.
   * @returns {number} The capacity of the stack.
   */
  getCapacity() {
    return this.capacity;
  }

  /**
   * Clears the stack, removing all elements.
   */
  clear() {
    this.top = -1;
  }
}
