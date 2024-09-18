/**
 * This program reads a text file and counts the occurrences of each word.
 * It uses an object (dictionary) to store the words and their counts.
 * The program prints the top 20 words with the highest counts in descending order.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Usage: node task1.js <filename>
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: 21 April 2024
 * Course: CS333 - Programming Languages
 * Instructor: Professor Max Bender
 */

const fs = require('fs');

/**
 * Process the specified file, count occurrences of each word, and print the top 20 words.
 * @param {string} filename - The name of the file to process.
 */
function processFile(filename) {
  try {
    // Read file contents
    const data = fs.readFileSync(filename, 'utf8');
    // Convert text to lowercase, remove punctuation, and split into words
    const words = data.toLowerCase().replace(/[^\w\s]/g, '').split(/\s+/);
    const wordCount = {};

    // Count occurrences of each word
    words.forEach(word => {
      if (word !== '') {
        wordCount[word] = (wordCount[word] || 0) + 1;
      }
    });

    // Sort words by count in descending order
    const sortedWords = Object.entries(wordCount).sort((a, b) => b[1] - a[1]);
    // Get the top 20 words
    const topWords = sortedWords.slice(0, 20);

    // Print the top 20 words
    console.log('Top 20 words:');
    topWords.forEach(([word, count]) => {
      console.log(`${word.padEnd(15)} ${count}`);
    });
  } catch (error) {
    console.error('Error reading file:', error);
  }
}

const filename = process.argv[2];

if (filename) {
  processFile(filename);
} else {
  console.log('Please provide a filename as a command-line argument.');
}
