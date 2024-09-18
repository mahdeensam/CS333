# Extension 2: Word Frequency Counter in R
#
# This program reads a text file and counts the occurrences of each word.
# It uses a named vector to store the words and their counts.
# The program prints the top 20 words with the highest counts in descending order.
#
# The word counter is case-insensitive and ignores punctuation characters.
#
# Usage: source("extension2.R")
#        word_counter("filename.txt")
#
# Mahdeen Ahmed Khan Sameer
# 21 April 2024

word_counter <- function(filename) {
  # Read the file content
  file_content <- readLines(filename)
  
  # Split the content into words, ignoring punctuation and converting to lowercase
  words <- tolower(unlist(strsplit(gsub("[^[:alnum:][:space:]]", "", file_content), "\\s+")))
  
  # Count the occurrences of each word
  word_count <- table(words)
  
  # Sort the words by count in descending order
  sorted_words <- sort(word_count, decreasing = TRUE)
  
  # Print the top 20 words
  cat("Top 20 words:\n")
  top_words <- head(sorted_words, n = 20)
  cat(sprintf("%-15s %5d\n", names(top_words), top_words), sep = "")
}
