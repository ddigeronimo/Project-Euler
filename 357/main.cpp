/* 
    Project Euler Problem 357 - Prime generating integers: https://projecteuler.net/problem=357
    ===========================================================================================
    Consider the divisors of 30: 1,2,3,5,6,10,15,30.
    It can be seen that for every divisor d of 30, d+30/d is prime.

    Find the sum of all positive integers n not exceeding 100 000 000
    such that for every divisor d of n, d+n/d is prime. 
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Algorithm to determine primality of a number, based off method I used in https://github.com/ddigeronimo/CS546/blob/master/lab_09/public/js/prime.js 
// Source: https://stackoverflow.com/questions/1801391/what-is-the-best-algorithm-for-checking-if-a-number-is-prime
bool isPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    int w = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += w;
        w = 6 - w;
    }
    return true;
}

// Given a number n, do all n's divisors d follow the property (d + n / d is prime)?
bool areDivisorsValid(int n) {
    // First, loop through every number i up to half of n to check if it is a divisor
    // It's pointless to check past the halfway point, as no number is divisible by any number that is greater than 50% of itself
    for (int i = 1; i <= n / 2; i++) {
        // If i is a divisor, we must check its validity
        if (n % i == 0) {
            if (!isPrime(i + n / i)) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    // Fast I/O trick
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Setup system timer, based on https://stackoverflow.com/a/3220503
    clock_t start;
    double duration;
    start = clock();

    // Check the sutibility of all numbers through 100000000 and add them onto a sum value
    int sumOfValidNumbers = 0;
    for (int i = 1; i < 100000000; i++) {
        if (areDivisorsValid(i)) {
            printf("%d is valid\n", i);
            sumOfValidNumbers += i;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    printf("Sum of all valid numbers: %d\n", sumOfValidNumbers);
    printf("Total time: %f seconds\n", duration);

    return 0;
}
