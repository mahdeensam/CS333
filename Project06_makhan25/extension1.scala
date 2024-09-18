/**
 * Extension 1: Word Frequency Counter in Scala
 *
 * This program reads a text file and counts the occurrences of each word.
 * It uses a Map to store the words and their counts.
 * The program prints the top 20 words with the highest counts in descending order.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Usage: scala WordCounter <filename>
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */

import scala.io.Source
import scala.util.{Failure, Success, Try}

object WordCounter {
  def main(args: Array[String]): Unit = {
    if (args.length != 1) {
      println("Usage: WordCounter <filename>")
      System.exit(1)
    }

    val filename = args(0)
    processFile(filename)
  }

  def processFile(filename: String): Unit = {
    Try(Source.fromFile(filename)) match {
      case Success(file) =>
        val wordCount = file
          .getLines()
          .flatMap(_.toLowerCase.replaceAll("[^a-zA-Z0-9\\s]", "").split("\\s+"))
          .foldLeft(Map.empty[String, Int]) { (count, word) =>
            count + (word -> (count.getOrElse(word, 0) + 1))
          }

        val topWords = wordCount.toSeq.sortBy(-_._2).take(20)

        println("Top 20 words:")
        topWords.foreach { case (word, count) =>
          println(f"$word%15s $count%5d")
        }

        file.close()

      case Failure(ex) =>
        println(s"Error reading file: $ex")
    }
  }
}
