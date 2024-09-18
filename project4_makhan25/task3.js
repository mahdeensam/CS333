/**
 * Function: QuickSort Implementation in JavaScript
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This JavaScript program implements the QuickSort algorithm with a customizable comparator function,
 * allowing for sorting arrays of any type as per the defined comparison logic. The program includes
 * example comparators for sorting numbers and strings in ascending order. The versatility of the
 * QuickSort function is demonstrated through sorting both numerical and string arrays, showcasing
 * the flexibility and power of JavaScript for algorithm implementation and data manipulation.
 */

function quickSort(arr, comparator) {
    if (arr.length <= 1) {
        return arr;
    }

    const pivot = arr[Math.floor(arr.length / 2)];
    const left = [];
    const right = [];

    for (let i = 0; i < arr.length; i++) {
        if (comparator(arr[i], pivot) < 0) {
            left.push(arr[i]);
        } else if (comparator(arr[i], pivot) > 0) {
            right.push(arr[i]);
        }
    }

    return quickSort(left, comparator).concat(pivot, quickSort(right, comparator));
}

// Example comparator for sorting numbers in ascending order
function numberComparator(a, b) {
    return a - b;
}

// Example comparator for sorting strings in ascending order
function stringComparator(a, b) {
    return a.localeCompare(b);
}

// Example usage
let numbers = [5, 3, 9, 1, 7];
console.log("Original numbers:", numbers);
console.log("Sorted numbers:", quickSort(numbers, numberComparator));

let strings = ["banana", "apple", "orange", "grape"];
console.log("Original strings:", strings);
console.log("Sorted strings:", quickSort(strings, stringComparator));
