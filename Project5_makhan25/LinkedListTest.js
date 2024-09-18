/**
 * This file tests the LinkedList class and its methods to ensure correct implementation.
 * Despite Visual Studio identifying an error, the file runs correctly as intended.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */
const LinkedList = require('./LinkedList');

// Helper function to print integers with a label
function printInt(i) {
  console.log(`value: ${i}`);
}

// Helper function to square integers
function squareInt(i) {
  return i * i;
}

// Comparison function for integers
function compInt(i, j) {
  return i === j;
}

// Helper function to print strings with a label
function printString(s) {
  console.log(`value: ${s}`);
}

// Comparison function for strings
function compString(s1, s2) {
  return s1 === s2;
}

// Main function to run tests
function main() {
  const list = new LinkedList();

  console.log('Testing push operation:');
  // Pushing elements onto the list
  for (let i = 0; i < 10; i += 2) {
    list.push(i);
  }
  list.map(printInt);  // Output the list after pushing

  console.log('\nTesting pop operation:');
  console.log(`Popped: ${list.pop()}`); // Popping the head element and printing it

  console.log('\nTesting append operation:');
  list.append(12); // Appending an element at the end
  list.map(printInt);  // Output the list after appending

  console.log('\nTesting remove operation:');
  const targetToRemove = 6;
  console.log(`Removed: ${list.remove(targetToRemove, compInt)}`); // Removing an element
  list.map(printInt);  // Output the list after removal

  console.log('\nTesting find operation:');
  const targetToFind = 4;
  const found = list.find(targetToFind, compInt);
  console.log(found !== null ? `Found: ${found}` : "Item not found");

  console.log('\nTesting clear operation:');
  list.clear(); // Clearing the list
  console.log(`List size after clear: ${list.size}`);

  console.log('\nRepopulating list:');
  for (let i = 0; i < 5; i++) {
    list.append(i);
  }
  list.map(printInt); // Output the list after appending more elements

  console.log('\nTesting size operation:');
  console.log(`List size: ${list.size}`);

  console.log('\nString operations test:');
  const strings = ['Hello', 'world', 'test', 'list'];
  const strList = new LinkedList();
  strings.forEach(str => strList.push(str));
  strList.map(printString);

  console.log('\nRemoving "test" from string list:');
  console.log(`Removed: ${strList.remove('test', compString)}`);
  strList.map(printString);

  console.log('\nFinal clear operation on string list:');
  strList.clear();
  console.log(`List size after final clear: ${strList.size}`);
}

main();
