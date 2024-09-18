# Mahdeen Ahmed Khan Sameer
# 25 April 2024
# Extension 08
# Data Structure Implementation in Python
 
import re
import sys

class BSTNode:
    def __init__(self, key, val=1):
        self.left = None
        self.right = None
        self.key = key
        self.val = val

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root:
            self._insert(self.root, key)
        else:
            self.root = BSTNode(key)

    def _insert(self, node, key):
        if key < node.key:
            if node.left:
                self._insert(node.left, key)
            else:
                node.left = BSTNode(key)
        elif key > node.key:
            if node.right:
                self._insert(node.right, key)
            else:
                node.right = BSTNode(key)
        else:
            node.val += 1

    def inorder(self):
        return self._inorder(self.root)

    def _inorder(self, node):
        result = []
        if node:
            result = self._inorder(node.left)
            result.append((node.key, node.val))
            result += self._inorder(node.right)
        return result

def process_file(filename):
    tree = BinarySearchTree()
    try:
        with open(filename, 'r') as file:
            for line in file:
                # Normalize to lowercase and remove punctuation
                words = re.findall(r'\b\w+\b', line.lower())
                for word in words:
                    tree.insert(word)
        return tree.inorder()
    except FileNotFoundError:
        print(f"Error: The file {filename} does not exist.")
        sys.exit(1)


def test_word_counter():
    sample_text = "Hello world! Hello everyone. Test the test, text the text."
    expected_counts = [('everyone', 1), ('hello', 2), ('test', 2), ('text', 2), ('the', 2), ('world', 1)]
    results = process_text(sample_text)
    sorted_results = sorted(results, key=lambda x: x[0])

    print("Test Results:")
    print("Expected:", expected_counts)
    print("Got:", sorted_results)

    assert sorted_results == expected_counts, "The test failed!"

def main():
    if len(sys.argv) == 2:
        filename = sys.argv[1]
        word_counts = process_file(filename)
        top_words = sorted(word_counts, key=lambda x: -x[1])[:20]
        for word, count in top_words:
            print(f"{word}: {count}")
    else:
        # Run a manual test if no filename is provided
        test_word_counter()

if __name__ == "__main__":
    main()
