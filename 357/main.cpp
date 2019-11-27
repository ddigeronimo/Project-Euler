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

// Memoize primes
bool primeMemo[50000000] = {false}; // Primes are true, not checked/not prime are false
bool notPrimeMemo[50000000] = {false}; // Only not prime are true, not checked/prime are false

// Algorithm to determine primality of a number, based off method I used in https://github.com/ddigeronimo/CS546/blob/master/lab_09/public/js/prime.js 
// As opposed to my source, this method uses memoization to increase efficiency as the program runs
bool isPrime(int n) {
    // Check memo array
    if (primeMemo[n]) {
        return true;
    }
    if (notPrimeMemo[n]) {
        return false;
    }
    if (n == 2 || n == 3) {
        primeMemo[n] = true;
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        notPrimeMemo[n] = true;
        return false;
    }
    int i = 5;
    int w = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            notPrimeMemo[n] = true;
            return false;
        }
        i += w;
        w = 6 - w;
    }
    primeMemo[n] = true;
    return true;
}

// Given a number n, do all n's divisors d follow the property (d + n / d is prime)?
// TODO: Optimize this
bool areDivisorsValid(int n) {
    // First, loop through every number i up to half of n to check if it is a divisor
    // It's pointless to check past the halfway point, as no number is divisible by any number that is greater than 50% of itself

    // If n is odd, we can check only odd numbers for its divisors
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i+=2) {
            // If i is a divisor, we must check its validity
            if (n % i == 0) {
                if (!isPrime(i + n / i)) {
                    return false;
                }
            }
        }
    } else {
        for (int i = 1; i <= n / 2; i++) {
            // If i is a divisor, we must check its validity
            if (n % i == 0) {
                if (!isPrime(i + n / i)) {
                    return false;
                }
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

    // Check the sutibility of all even numbers through 100000000 and add them onto a sum value
    // No odd numbers other than 1 are valid, so we can skip them and start the sum value at one
    double sumOfValidNumbers = 1;
    for (int i = 2; i < 100000000; i+=2) {
        if (areDivisorsValid(i)) {
            printf("%d is valid\n", i);
            sumOfValidNumbers += (double) i;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    printf("Sum of all valid numbers: %f\n", sumOfValidNumbers);
    printf("Total time: %f seconds\n", duration);

    return 0;
}
