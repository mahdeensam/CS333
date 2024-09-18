/**
 * This file provides the implementation for a generic linked list in JavaScript:
 * - Node structure definition which includes a data pointer and a pointer to the next node.
 * - LinkedList structure definition which includes a head pointer to the first node.
 * 
 * It also includes operations such as:
 * - Creation of a new linked list
 * - Push operation to add an element to the front of the list
 * - Pop operation to remove and return the front element from the list
 * - Append operation to add an element to the end of the list
 * - Remove operation to delete a node based on a provided comparison function and target data
 * - Size operation to get the number of elements in the list
 * - Clear operation to empty the list and reset its size
 * - Map operation to apply a function to each element in the list
 *
 * These operations enable the linked list to handle various types of data flexibly and efficiently.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

class Node {
  constructor(data) {
      this.data = data; // holds the data of the node
      this.next = null; // pointer to the next node in the list
  }
}

class LinkedList {
  constructor() {
      this.head = null; // the first node of the list
      this.size = 0;    // number of nodes in the list
  }

  // Adds an element at the front of the list
  push(data) {
      const newNode = new Node(data);
      newNode.next = this.head;  // point the new node to the current head
      this.head = newNode;       // update the head to be the new node
      this.size++;
  }

  // Removes the front element and returns its data
  pop() {
      if (!this.head) return null; // if the list is empty, return null
      const data = this.head.data; // capture the data of the head
      this.head = this.head.next;  // update the head to the next node
      this.size--;
      return data;
  }

  // Adds an element at the end of the list
  append(data) {
      const newNode = new Node(data);
      if (!this.head) {
          this.head = newNode; // if the list is empty, new node becomes the head
      } else {
          let current = this.head;
          while (current.next) {
              current = current.next; // traverse to the end of the list
          }
          current.next = newNode; // link the last node to the new node
      }
      this.size++;
  }

  // Removes the node with data matching the target
  remove(target, compfunc) {
      let current = this.head;
      let prev = null;

      while (current) {
          if (compfunc(current.data, target)) { // comparison function returns true if match
              if (!prev) {
                  this.head = current.next; // remove head if it's a match
              } else {
                  prev.next = current.next; // unlink the current node from the list
              }
              this.size--;
              return current.data; // return the data of the removed node
          }
          prev = current; // move prev and current pointers forward
          current = current.next;
      }
      return null; // if no match found, return null
  }

  // Finds and returns data based on a match with the target
  find(target, compfunc) {
      let current = this.head;

      while (current) {
          if (compfunc(current.data, target)) {
              return current.data; // return the data if a match is found
          }
          current = current.next;
      }
      return null; // if no match found, return null
  }

  // Clears the linked list
  clear() {
      this.head = null; // reset the head pointer
      this.size = 0;    // reset the size of the list
  }

  // Applies a function to each element in the list
  map(mapfunc) {
      let current = this.head;

      while (current) {
          mapfunc(current.data); // apply the function to each node's data
          current = current.next;
      }
  }
}

module.exports = LinkedList; // allows the LinkedList class to be imported in other files
