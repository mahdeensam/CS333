def rot13_char(c):
    """Shift a character by 13 places with wraparound."""
    if 'a' <= c <= 'z':
        return chr((ord(c) - ord('a') + 13) % 26 + ord('a'))
    elif 'A' <= c <= 'Z':
        return chr((ord(c) - ord('A') + 13) % 26 + ord('A'))
    else:
        return c

def rot13(text):
    """Apply ROT13 encoding to a string."""
    return ''.join(rot13_char(c) for c in text)

def encode_file(file_path):
    """Read file, encode content with ROT13, and print to stdout."""
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()
            encoded_content = rot13(content)
            print(encoded_content)
    except FileNotFoundError:
        print(f"File not found: {file_path}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python encode.py <file>")
    else:
        encode_file(sys.argv[1])
