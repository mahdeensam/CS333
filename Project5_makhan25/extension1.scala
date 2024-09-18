/**
 * This Scala file provides the implementation for a generic linked list. It includes:
 * - Node[T]: A class for the node structure which holds the data and a reference to the next node.
 * - LinkedList[T]: A class for managing the linked list that supports various operations.
 *
 * The operations supported by LinkedList include:
 * - Creation of a new linked list
 * - push(data: T): Adds an element to the front of the list
 * - pop(): Removes and returns the front element from the list
 * - append(data: T): Adds an element to the end of the list
 * - remove(target: T, compfunc: (T, T) => Boolean): Removes a node based on a comparison function
 * - find(target: T, compfunc: (T, T) => Boolean): Finds and returns a node using a comparison function
 * - clear(): Empties the list and resets its size to zero
 * - map(mapfunc: T => Unit): Applies a function to each element in the list
 * - getSize: Returns the number of elements in the list
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

class Node[T](var data: T, var next: Option[Node[T]] = None) {
  // Node class constructor takes a data item of type T and optionally the next Node in the list
}

class LinkedList[T] {
  private var head: Option[Node[T]] = None // Head of the list, initially None
  private var size: Int = 0 // Size of the list, initially 0

  /**
   * Adds a new element to the front of the list.
   * @param data Element to add to the list.
   */
  def push(data: T): Unit = {
    val newNode = new Node(data, head) // Create a new node with the current head as its next node
    head = Some(newNode) // Set new node as the new head of the list
    size += 1 // Increment the size of the list
  }

  /**
   * Removes and returns the element at the front of the list.
   * @return Option[T] The removed element, if the list is not empty.
   */
  def pop(): Option[T] = {
    head match {
      case Some(node) =>
        head = node.next // Set the head to the next node
        size -= 1 // Decrement the list size
        Some(node.data) // Return the data of the removed node
      case None => None // Return None if the list is empty
    }
  }

  /**
   * Adds a new element to the end of the list.
   * @param data Element to add.
   */
  def append(data: T): Unit = {
    val newNode = new Node(data) // Create a new node
    head match {
      case Some(node) =>
        var current = node
        while (current.next.isDefined) { // Traverse to the end of the list
          current = current.next.get
        }
        current.next = Some(newNode) // Set the new node as the next of the last node
      case None => head = Some(newNode) // If the list is empty, set new node as head
    }
    size += 1 // Increment the list size
  }

  /**
   * Removes the node with data matching the target using a comparison function.
   * @param target Data to match for removal.
   * @param compfunc Comparison function to identify the correct node.
   * @return Option[T] The data of the removed node if found.
   */
  def remove(target: T, compfunc: (T, T) => Boolean): Option[T] = {
    var prev: Option[Node[T]] = None // Previous node, initially None
    var current = head // Start with the head

    while (current.isDefined) {
      if (compfunc(current.get.data, target)) { // If the current node's data matches the target
        prev match {
          case Some(prevNode) => prevNode.next = current.get.next // Bypass the current node
          case None => head = current.get.next // If removing head, update head
        }
        size -= 1 // Decrement the list size
        return Some(current.get.data) // Return the data of the removed node
      }
      prev = current // Move prev to current
      current = current.get.next // Move to next node
    }
    None // Return None if no matching node is found
  }

  /**
   * Finds the node with data matching the target using a comparison function.
   * @param target Data to find.
   * @param compfunc Comparison function to identify the correct node.
   * @return Option[T] The data of the found node if present.
   */
  def find(target: T, compfunc: (T, T) => Boolean): Option[T] = {
    var current = head // Start with the head
    while (current.isDefined) {
      if (compfunc(current.get.data, target)) { // If the current node's data matches the target
        return Some(current.get.data) // Return the data of the found node
      }
      current = current.get.next // Move to next node
    }
    None // Return None if no match is found
  }

  /**
   * Clears the list and resets its size to zero.
   */
  def clear(): Unit = {
    head = None // Remove references to nodes
    size = 0 // Reset size
  }

  /**
   * Applies a specified function to each element in the list.
   * @param mapfunc The function to apply to each element.
   */
  def map(mapfunc: T => Unit): Unit = {
    var current = head // Start with the head
    while (current.isDefined) {
      mapfunc(current.get.data) // Apply the function to the current node's data
      current = current.get.next // Move to next node
    }
  }

  /**
   * Returns the current size of the list.
   * @return Int The number of elements in the list.
   */
  def getSize: Int = size
}
