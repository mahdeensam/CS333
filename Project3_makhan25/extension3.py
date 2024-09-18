"""
Extension 3: Comparing Code in Python and JS

Demonstrates an advanced approach to comparing numbers in Python, incorporating
input validation, detailed documentation, and optional tolerance for comparisons.

Mahdeen Ahmed Khan Sameer
Professor Max Bender
Date: 03/09/2024
"""

def compare_numbers(a, b, tolerance=0):
    """
    Compares two numbers and prints their relationship.
    
    Validates that the inputs are numbers, compares them, and prints whether the first 
    number is greater than, less than, or equal to the second number. It can also consider 
    numbers as equal if they are within a specified tolerance, useful for floating-point 
    comparisons.
    
    Parameters:
    - a: The first number to compare.
    - b: The second number to compare.
    - tolerance: Optional tolerance for considering two numbers as equal (default is 0).
    """
    # Validate inputs
    if not isinstance(a, (int, float)) or not isinstance(b, (int, float)):
        print('Error: Both inputs must be numbers.')
        return
    
    # Calculate the difference and adjust for tolerance
    diff = abs(a - b)
    
    if diff <= tolerance:
        print(f"{a} is approximately equal to {b} within a tolerance of {tolerance}")
    elif a > b:
        print(f"{a} is greater than {b}")
    else:
        print(f"{a} is less than {b}")

# Example usage
num1 = 10
num2 = 5
tolerance = 0.1

compare_numbers(num1, num2)
compare_numbers(10, 10.05, tolerance)  # Demonstrates tolerance in action
