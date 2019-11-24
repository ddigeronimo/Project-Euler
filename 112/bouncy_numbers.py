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

# Determine the percentage of bouncy numbers below a limit
def bouncy_percentage(limit):
    if limit == 0:
        return 0
    bouncy = 0
    total = 0
    for i in range(0, limit):
        if is_bouncy(i):
            bouncy += 1
        total += 1
    return bouncy / total

def main():
    start_time = time.time()
    num = 100000000
    ninety_nine_found = False
    while (ninety_nine_found == False):
        print(str(num))
        if bouncy_percentage(num) == 99:
            ninety_nine_found = True
            # Check if previous number is the answer
            if bouncy_percentage(num - 1) == 99:
                num -= 1
        else:
            num += 2
    end_time = time.time()
    print("99% Bouncy found at ", str(num))
    print("Time elapsed: ", end_time - start_time)

if __name__ == "__main__":
    main()