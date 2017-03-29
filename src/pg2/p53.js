/*
Combinatoric selections
Problem 53
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general, nCr =	n!/r!(n-r)!, where r <= n, n! = n x (n-1) x ... x 3 x 2 x 1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 <= n < 100, are greater than one-million?
*/

// Tf nCr* > 1000000, where r* < n/2 is first r to work, so will (n-r)Cr since it is symmetric
// Thus total of (n-2r)+1 values for each n
// start n at 23, and r at 10 for this specific n

// Compute product from i to n
function pi(i, n) {
    var product = 1;
    for (var x = i; x <= n; x++)
        product *= x;
    return product;
}

function combinations(n, r, factorials) {
    var denom = 1;
    var numer = 1;
    // Determine which is smaller to compute: r! or (n-r)!
    if (r > (n-r)) {
        denom = factorials[n-r];
        numer = pi(r+1, n);
    }
    else {
        denom = factorials[r];
        numer = pi(n-r+1, n);
    }
    return (numer/denom);
}

var n = 15;
var factorials = {};
factorials[0] = 1;
for (var i = 1; i <= n; i++)
    factorials[i] = factorials[i-1]*i;

// the first r has to be initialized to 1 less than what was required to reach 1mil (subtraction in for loop)
// the r for n+1 will either be r or r-1, and so on, since the combinations will increase as n increases
var start_r = 10;
var threshold = 1000000;
var start_n = 23;
var last_n = 100;
var count = 0;
for (var n = start_n; n <= last_n; n++) {
    r = start_r - 1;
    // r estimate was too low, increment r
    if (combinations(n, r, factorials) < threshold)
        r++;
    start_r = r;
    count += (n-(2*r)+1);
}

//console.log("Total count from n=" + (start_n).toString() + " to " + (last_n).toString() + ": " + (count).toString());
// Expected: 4075
// Takes an avg of 209ms