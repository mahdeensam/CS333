/**
 * Extension 5: Demonstrating a more readable and maintainable binary search program in JavaScript.
 * This version aims to enhance clarity by using descriptive variable names, adding comments,
 * and avoiding overly condensed expressions.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * Date: 03/09/2024
 */

/**
 * Performs a binary search on a sorted array to find the index of a target value.
 * @param {Array} sortedArray - The sorted array to search.
 * @param {number} target - The value to search for.
 * @return {number} The index of the target if found, otherwise -1.
 */
function binarySearch(sortedArray, target) {
    let leftIndex = 0;
    let rightIndex = sortedArray.length - 1;

    while (leftIndex <= rightIndex) {
        const middleIndex = Math.floor((leftIndex + rightIndex) / 2);
        const middleValue = sortedArray[middleIndex];

        if (middleValue === target) {
            return middleIndex; // Target found
        } else if (middleValue < target) {
            leftIndex = middleIndex + 1; // Search in the right half
        } else {
            rightIndex = middleIndex - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

// Example usage
const numbers = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20];
const target = 12;

const resultIndex = binarySearch(numbers, target);

if (resultIndex !== -1) {
    console.log(`Target ${target} found at index ${resultIndex}.`);
} else {
    console.log(`Target ${target} not found in the array.`);
}
