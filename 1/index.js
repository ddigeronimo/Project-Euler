/*
    Project Euler Problem 1: https://projecteuler.net/problem=1
    ===========================================================
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000.
*/

// Function to compute all multiples of 2 numbers up to a specified limit
function generateMultiples(x, y, limit) {
    let multiples = [];
    for (let i = 0; i < limit; i++) {
        if (i % x == 0 || i % y == 0) {
            multiples.push(i);
        }
    }
    return multiples;
}

// Print the sum of all the multiples of 3 and 5 
console.log(generateMultiples(3, 5, 1000).reduce((a, b) => a + b, 0));