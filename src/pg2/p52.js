/*
Permuted multiples
Problem 52
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

function sameDigits(a, b) {
    // Assume 0 will never be an input
    var digits = new Array(10).fill(0);
    while(a > 0) {
        digit = a % 10;
        digits[digit]++;
        a = Math.floor(a/10);
    }
    while(b > 0) {
        digit = b % 10;
        digits[digit]--;
        b = Math.floor(b/10);
    }
    for (var digit = 0; digit < 10; digit++) {
        if (digits[digit] != 0)
            return false;
    }
    return true;
}

function solve(maxMultiplier) {
    // n = maxMultiplier such that digits(x) = digits(2x) = ... = digits(n*x)
    var x = 1;
    while(x < 1000000) {
        for (var n = 2; n <= maxMultiplier; n++) {
            if (sameDigits(x, x*n) == false)
                break;
            if (n == maxMultiplier)
                return ([x, n*x]);
        }
        x += 1;
    }
    return -1;
}

//console.log(solve(2));
// Expected: [125874, 251748]
console.log(solve(6));
// Expected: [142857, 857142]
// Answer: 142857