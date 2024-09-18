/*
 * Function Handling Examples in Go
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 *
 * This Go program showcases various aspects of function handling, including defining function types,
 * assigning functions to variables, and passing functions as arguments. It demonstrates the flexibility
 * of Go's type system and its support for functional programming patterns. The 'greeterFunc' type is defined
 * as a function type that takes a string and returns a string. This type is then used to declare function
 * variables and parameters, allowing for dynamic function assignment and execution. The examples include
 * predefined functions 'sayHello' and 'sayHi', and an inline function definition, all of which are used to
 * illustrate how functions can be manipulated and passed around in Go, enabling powerful and flexible
 * programming constructs.
 */


package main

import "fmt"

// Define a function type
type greeterFunc func(string) string

// Function that takes a function as an argument
func greet(greeter greeterFunc, name string) {
	fmt.Println(greeter(name))
}

// Function to say hello
func sayHello(name string) string {
	return "Hello, " + name + "!"
}

// Function to say hi
func sayHi(name string) string {
	return "Hi, " + name + "!"
}

func main() {
	// Assign a function to a variable
	var greetFunc greeterFunc
	greetFunc = sayHello

	// Call the function assigned to the variable
	fmt.Println(greetFunc("John"))

	// Pass a function to another function
	greet(sayHi, "Alice")

	// Define and call a function directly as an argument
	greet(func(name string) string {
		return "Hola, " + name + "!"
	}, "Bob")
}
