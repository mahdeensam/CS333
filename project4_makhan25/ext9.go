/*
 * Generic QuickSort Implementation in Go
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 *
 * This Go program demonstrates a generic implementation of the QuickSort algorithm, capable of sorting slices of any type.
 * It utilizes a 'Comparator' type defined as a function that takes two 'interface{}' arguments and returns a 'bool'. This design
 * allows the QuickSort function to be flexible and work with any data type, provided a suitable comparator function is given.
 * The program includes example comparator functions for integers and strings, showcasing how to sort slices of these types using
 * the generic QuickSort function. This example highlights the power of Go's interfaces and type assertions for creating flexible
 * and reusable algorithms that can operate on various data types.
 */


package main

import (
	"fmt"
)

// Comparator defines the type of function for comparing elements
type Comparator func(a, b interface{}) bool

// QuickSort sorts the given slice using the quicksort algorithm
func QuickSort(slice []interface{}, comparator Comparator) {
	if len(slice) <= 1 {
		return
	}

	pivotIndex := len(slice) / 2
	pivot := slice[pivotIndex]

	// Partition step
	var left, right []interface{}
	for i := range slice {
		if i == pivotIndex {
			continue
		}
		if comparator(slice[i], pivot) {
			left = append(left, slice[i])
		} else {
			right = append(right, slice[i])
		}
	}

	// Recursively sort left and right partitions
	QuickSort(left, comparator)
	QuickSort(right, comparator)

	// Combine left, pivot, and right partitions
	copy(slice[:len(left)], left)
	slice[len(left)] = pivot
	copy(slice[len(left)+1:], right)
}

// Example comparators
func intComparator(a, b interface{}) bool {
	return a.(int) < b.(int)
}

func stringComparator(a, b interface{}) bool {
	return a.(string) < b.(string)
}

func main() {
	// Example usage
	integers := []interface{}{5, 3, 9, 1, 7}
	fmt.Println("Original integers:", integers)
	QuickSort(integers, intComparator)
	fmt.Println("Sorted integers:", integers)

	strings := []interface{}{"banana", "apple", "orange", "grape"}
	fmt.Println("Original strings:", strings)
	QuickSort(strings, stringComparator)
	fmt.Println("Sorted strings:", strings)
}
