'''
Project Euler Problem 112 - Bouncy numbers: https://projecteuler.net/problem=112
================================================================================
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy.
In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
Find the least number for which the proportion of bouncy numbers is exactly 99%.
'''

import time

# Convert a string representation of a number to a list of its digits as ints
def number_string_to_list(num):
    return list(str(num))

# Determine if a number is increasing
def is_increasing(x):
    x_digits = number_string_to_list(x)
    for i in range(0, len(x_digits)-1):
        if x_digits[i] > x_digits[i + 1]:
            return False
    return True

# Determine if a number is decreasing
def is_decreasing(x):
    x_digits = number_string_to_list(x)
    for i in range(0, len(x_digits)-1):
        if x_digits[i] < x_digits[i + 1]:
            return False
    return True

# Helper function to determine if a number is bouncy
def is_bouncy(x):
    if is_increasing(x) or is_decreasing(x):
        return False
    else:
        return True

def main():
    start_time = time.time()
    num = 0
    ninety_nine_found = False
    amount_bouncy = 0
    # Check upwards through numbers, keeping a running total of bouncy numbers and checking the percentage with each new number
    while (ninety_nine_found == False):
        num += 1
        print(str(num))
        # Instead of calling a seperate function, let's do the bounciness and percentage checks here
        if is_bouncy(num):
            amount_bouncy += 1
            if amount_bouncy / num == .99:
                ninety_nine_found = True
    end_time = time.time()
    print("99% Bouncy below ", str(num))
    print("Time elapsed: ", end_time - start_time)

if __name__ == "__main__":
    main()