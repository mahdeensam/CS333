/**
 * This file provides the test for LinkedList class and functions
 *
 * Mahdeen Ahmed Khan Sameer
 * April 10, 2024
 */
object LinkedListTest {
  def main(args: Array[String]): Unit = {
    val l = new LinkedList[Int]()

    // Push data on the list
    for (i <- 0 until 20 by 2) {
      l.push(i)
    }

    // Printing the list and testing map
    println("After initialization")
    l.map(println)
    l.map(i => i * i)
    println("\nAfter squaring")
    l.map(println)

    // Testing removing data
    var target = 16
    var removed = l.remove(target, _ == _)
    removed match {
      case Some(value) => println(s"\nremoved: $value")
      case None => println(s"\nNo instance of $target")
    }

    target = 11
    var found = l.find(target, _ == _)
    found match {
      case Some(value) => println(s"\nFound: $value")
      case None => println(s"\nNo instance of $target")
    }

    removed = l.remove(target, _ == _)
    removed match {
      case Some(value) => println(s"\nremoved: $value")
      case None => println(s"\nNo instance of $target")
    }

    println("\nAfter removals")
    l.map(println)

    // Testing appending data
    l.append(target)
    println("\nAfter append")
    l.map(println)

    // Test clearing
    l.clear()
    println("\nAfter clear")
    l.map(println)

    // Rebuild and test append and pop
    for (i <- 0 until 5) {
      l.append(i)
    }
    println("\nAfter appending")
    l.map(println)

    val popped1 = l.pop()
    popped1 match {
      case Some(value) => println(s"\npopped: $value")
      case None =>
    }

    val popped2 = l.pop()
    popped2 match {
      case Some(value) => println(s"popped: $value")
      case None =>
    }

    println("\nAfter popping")
    l.map(println)
    println(s"\nList size: ${l.getSize}")

    // Clear the integer list
    l.clear()

    // Test with strings
    val strList = new LinkedList[String]()
    val str1 = "Hello"
    val str2 = "World"
    val str3 = "CS333 Project 5 in Scala now!"
    val strTarget = "World"

    strList.push(str1)
    strList.push(str2)
    strList.push(str3)

    println("\nString list after initialization")
    strList.map(println)

    val foundStr = strList.find(strTarget, _ == _)
    foundStr match {
      case Some(value) => println(s"\nFound: $value")
      case None => println(s"\nNo instance of $strTarget")
    }

    val removedStr = strList.remove(strTarget, _ == _)
    removedStr match {
      case Some(value) => println(s"\nRemoved: $value")
      case None => println(s"\nNo instance of $strTarget")
    }

    println("\nString list after removal")
    strList.map(println)

    // Clear the string list
    strList.clear()
  }
}

// After initialization
// value: 18
// value: 16
// value: 14
// value: 12
// value: 10
// value: 8
// value: 6
// value: 4
// value: 2
// value: 0

// After squaring
// value: 18
// value: 16
// value: 14
// value: 12
// value: 10
// value: 8
// value: 6
// value: 4
// value: 2
// value: 0

// removed: 16

// No instance of 11

// No instance of 11

// After removals
// value: 18
// value: 14
// value: 12
// value: 10
// value: 8
// value: 6
// value: 4
// value: 2
// value: 0

// After append
// value: 18
// value: 14
// value: 12
// value: 10
// value: 8
// value: 6
// value: 4
// value: 2
// value: 0
// value: 11

// After clear

// After appending
// value: 0
// value: 1
// value: 2
// value: 3
// value: 4

// popped: 0
// popped: 1

// After popping
// value: 2
// value: 3
// value: 4

// List size: 3

// String list after initialization
// value: CS333 Project 5 in Scala now!
// value: World
// value: Hello

// Found: World

// Removed: World

// String list after removal
// value: CS333 Project 5 in Scala now!
// value: Hello

