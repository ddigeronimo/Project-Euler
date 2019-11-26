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

using namespace std;

// Return a vector containing all divisors of a given number n
vector<int> getDivisors(int n) {
    vector<int> divisors;
    // Check all numbers from 0 to half of x
    // It's pointless to check past the halfway point, as no number is divisible by any number that is greater than 50% of itself
    for (int i = 1; i <= n / 2; i++) {
        // If the number is a divisor, we add it
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    // Finally, we have to add the number itself
    divisors.push_back(n);
    return divisors;
}

// Algorithm to determine primality of a number, based off method I used in https://github.com/ddigeronimo/CS546/blob/master/lab_09/public/js/prime.js 
bool isPrime(int n) {
    // TODO
    return false;
}

// Given a number n, do all n's divisors d follow the property (d + n / d is prime)?
bool areDivisorsValid(int n) {
    // First, get n's divisors
    vector<int> divisors = getDivisors(n);
    // Now check if all divisors fit the given pattern
    for (size_t i = 0; i < divisors.size(); i++) {
        // TODO
    }
    
    return false;
}

int main(int argc, char *argv[]) {
    // Fast I/O trick
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // TODO
    return 0;
}
