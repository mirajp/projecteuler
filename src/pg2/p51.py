"""
Prime digit replacements
Problem 51
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
"""

import itertools

def eratosthenes(n, primes):
    lastPrime = 2
    nonprimes = set()
    for j in xrange(lastPrime*lastPrime, n+1, lastPrime):
        nonprimes.add(j)
    
    lastPrime = 3
    # Skip by 2 to check if number is prime
    for lastPrime in xrange(lastPrime, n+1, 2):
        if lastPrime not in nonprimes:
            primes[lastPrime] = True
            for j in xrange(lastPrime*lastPrime, n+1, lastPrime):
                nonprimes.add(j)

    return
    
def getSmallestInPrimeFamily(familySize, primes):
    for number in primes:
        indices = range(0, len(str(number))-1)
        for numDigitsToSwap in xrange(1, len(indices)+1):
            for subset in itertools.combinations(indices, numDigitsToSwap):
                minDigit = 0
                if 0 in subset:
                    minDigit = 1
                
                primesInFamily = 0
                digits = [int(x) for x in str(number)]
                family = []
                for digit in xrange(minDigit, 10):
                    for index in subset:
                        digits[index] = digit
                    newNumber = int(''.join(map(str,digits)))
                    if newNumber in primes:
                        family.append(newNumber)
                        primesInFamily += 1
                    
                if primesInFamily >= familySize:
                    return family[0]
                
    return -1

goal = 8
upperLimit = 1000000
primes = {}

eratosthenes(upperLimit, primes)
prime = getSmallestInPrimeFamily(goal, primes)
print("Number " + str(prime) + " has " + str(goal) + " primes in family")
# Expected:  121313
