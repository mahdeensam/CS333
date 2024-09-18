/**
 * This Scala file showcases two distinct methodologies for implementing a generic stack data structure:
 * one using a mutable state within a class, and another utilizing immutable state principles typically
 * followed in functional programming.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

// Class-based implementation using mutable state
class MutableStack[T] {
  private var items: List[T] = List.empty[T]

  def push(item: T): Unit = {
    items = item :: items  // Pushes item onto the stack by prepending to the list
  }

  def pop(): Option[T] = {
    items match {
      case head :: tail => {
        items = tail  // Removes the head, effectively popping the stack
        Some(head)
      }
      case Nil => None  // If the stack is empty, return None
    }
  }

  def peek(): Option[T] = items.headOption  // Returns the head without removing it

  def isEmpty(): Boolean = items.isEmpty  // Checks if the stack is empty

  def size(): Int = items.length  // Returns the number of items in the stack
}

// Class-based implementation using immutable state
class ImmutableStack[T](private val items: List[T] = List.empty[T]) {
  def push(item: T): ImmutableStack[T] = {
    new ImmutableStack(item :: items)  // Returns a new stack with the item pushed
  }

  def pop(): (Option[T], ImmutableStack[T]) = {
    items match {
      case head :: tail => (Some(head), new ImmutableStack(tail))
      case Nil => (None, this)  // If empty, return None and the current stack unchanged
    }
  }

  def peek(): Option[T] = items.headOption

  def isEmpty(): Boolean = items.isEmpty

  def size(): Int = items.length
}

/**
 * Example usage:
 */
object StackDemo extends App {
  val mutableStack = new MutableStack[Int]
  mutableStack.push(1)
  mutableStack.push(2)
  println("MutableStack Peek: " + mutableStack.peek()) // Output: Some(2)
  println("MutableStack Pop: " + mutableStack.pop())   // Output: Some(2)
  println("MutableStack Is Empty: " + mutableStack.isEmpty()) // Output: false
  println("MutableStack Size: " + mutableStack.size()) // Output: 1

  val immutableStack = new ImmutableStack[Int]
  val pushedStack = immutableStack.push(1).push(2)
  val (item, newStack) = pushedStack.pop()
  println("ImmutableStack Peek: " + pushedStack.peek()) // Output: Some(2)
  println("ImmutableStack Pop: " + item)               // Output: Some(2)
  println("ImmutableStack New Peek: " + newStack.peek()) // Output: Some(1)
  println("ImmutableStack Is Empty: " + newStack.isEmpty()) // Output: false
  println("ImmutableStack Size: " + newStack.size())  // Output: 1
}

/**
 * Discussion:
 *
 * The MutableStack class uses a private mutable List to manage the stack's state, allowing in-place
 * modification (push and pop operations directly change the state). This approach is straightforward
 * and efficient in terms of operation time; however, it sacrifices the immutability principles commonly
 * applied in functional programming, which can lead to side effects and make the code harder to reason about
 * in complex applications.
 *
 * The ImmutableStack class, on the other hand, maintains the immutability of the stack by returning a new
 * stack instance with every push or pop operation, preserving the original stack's state. This method aligns
 * with functional programming paradigms, promoting safer code and easier reasoning but may involve higher
 * memory usage and potentially slower performance due to frequent object creation.
 *
 * These examples illustrate different approaches tailored to specific needs and demonstrate Scala's flexibility
 * in balancing object-oriented and functional programming techniques.
 */
