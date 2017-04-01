/*
Prime digit replacements
Problem 51
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/

function eratosthenes(n, primes) {
    var lastPrime = 2;
    primes[lastPrime] = true;
    var nonprimes = new Set();
    for (var j = lastPrime*lastPrime; j < n+1; j += lastPrime)
        nonprimes.add(j);
    
    lastPrime = 3;
    // Skip by 2 to check if number is prime
    for (; lastPrime < n+1; lastPrime += 2) {
        if(nonprimes.has(lastPrime) == false) {
            primes[lastPrime] = true;
            for (var j = lastPrime*lastPrime; j < n+1; j += lastPrime)
                nonprimes.add(j);
        }
    }
    return;
}

function combinations(set, size) {
    //2^n possible elements in powerset, 2^n-1 possible combinations (excludes empty set)
    var combinations = new Set(), result, mask, total = Math.pow(2, set.length);
    for(mask = 1; mask < total; mask++) {
        result = [];
        for (var i = 0; i < set.length; i++) {
            if((mask & (1 << i)) !== 0) {
                result.push(set[i]);
            }
        }
        if( result.length == size){
            combinations.add(result);
        }
    }
    return combinations; 
};

function getSmallestInPrimeFamily(familySize, primes) {
    for (var number in primes) {
        var indices = new Array();
        for (var digitIndex = 0; digitIndex < ((number).toString()).length-1; digitIndex++)
            indices.push(digitIndex);
        
        for (var numDigitsToSwap = 1; numDigitsToSwap < indices.length+1; numDigitsToSwap++) {
            var subsets = combinations(indices, numDigitsToSwap);
            for (let subset of subsets) {
                var minDigit = 0;
                if (subset.includes(0)) {
                    minDigit = 1;
                }
                var primesInFamily = 0;
                var digits = ((number).toString()).split("").map(function(x){return parseInt(x, 10);});
                var family = new Array();
                for (var digit = minDigit; digit < 10; digit++) {
                    subset.forEach(function(index) {
                        digits[index] = digit;
                    });
                    var newNumber = parseInt(digits.join(''), 10);
                    if (newNumber in primes) {
                        family.push(newNumber);
                        primesInFamily++;
                    }
                }
                if (primesInFamily >= familySize) {
                    return family[0];
                }
            }
        }
    }
    return -1;
}

var goal = 8
var upperLimit = 1000000
var primes = {}

eratosthenes(upperLimit, primes);
prime = getSmallestInPrimeFamily(goal, primes);
console.log("Number " + (prime).toString() + " has " + (goal).toString() + " primes in family");
// Expected:  121313
