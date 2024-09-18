/**
 * This Scala file demonstrates two different approaches to implementing a generic stack data structure: 
 * using a trait-based approach and a class-based direct implementation. These methods showcase how 
 * polymorphism and encapsulation can be achieved in Scala while adhering to the principles of object-oriented 
 * and functional programming.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

// Define a Stack trait with generic type T
trait Stack[T] {
  def push(item: T): Unit
  def pop(): Option[T]
  def peek(): Option[T]
  def isEmpty(): Boolean
  def size(): Int
}

// Implement the Stack trait using a class that utilizes a List to store elements
class ListStack[T] extends Stack[T] {
  private var items: List[T] = List.empty[T]

  override def push(item: T): Unit = {
    items = item :: items  // Prepend item to the front of the list
  }

  override def pop(): Option[T] = items match {
    case head :: tail => {
      items = tail  // Remove the head element
      Some(head)  // Return the head element
    }
    case _ => None  // Return None if the list is empty
  }

  override def peek(): Option[T] = items.headOption

  override def isEmpty(): Boolean = items.isEmpty

  override def size(): Int = items.length
}

// Implement the Stack trait using a class that directly manipulates an internal List
class DirectStack[T] extends Stack[T] {
  private var items: List[T] = Nil  // Initialize items to an empty list

  override def push(item: T): Unit = {
    items = item :: items
  }

  override def pop(): Option[T] = {
    val result = items.headOption
    items = items.drop(1)
    result
  }

  override def peek(): Option[T] = items.headOption

  override def isEmpty(): Boolean = items.isEmpty

  override def size(): Int = items.length
}

/**
 * Example usage and output demonstration
 */

object StackExample extends App {
  val listStack = new ListStack[Int]
  listStack.push(1)
  listStack.push(2)
  println("ListStack Peek: " + listStack.peek())  // Output: Some(2)
  println("ListStack Pop: " + listStack.pop())   // Output: Some(2)
  println("ListStack Is Empty: " + listStack.isEmpty())  // Output: false
  println("ListStack Size: " + listStack.size())  // Output: 1

  val directStack = new DirectStack[Int]
  directStack.push(3)
  directStack.push(4)
  println("DirectStack Peek: " + directStack.peek())  // Output: Some(4)
  println("DirectStack Pop: " + directStack.pop())   // Output: Some(4)
  println("DirectStack Is Empty: " + directStack.isEmpty())  // Output: false
  println("DirectStack Size: " + directStack.size())  // Output: 1
}

/**
 * Discussion of Approaches:
 * 
 * The ListStack class uses Scala's List data structure to implement the Stack functionality.
 * This approach is clean and leverages Scala's powerful list operations but could have performance
 * implications due to the overhead of List operations such as head and tail.
 *
 * The DirectStack class also uses a List but demonstrates a slightly different approach by
 * manipulating the list directly for pop operations. This could potentially offer a more 
 * straightforward stack manipulation at the slight cost of clarity due to direct list manipulation.
 *
 * Both implementations provide the benefits of immutability and state encapsulation, typical of Scala,
 * ensuring that stack operations are predictable and safe from external modifications.
 */
