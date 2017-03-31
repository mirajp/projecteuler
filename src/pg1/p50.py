"""
Consecutive prime sum
Problem 50
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
"""

# O(n^2) time to get all the primes
# Hash map/dictionary (O(n) memory) to hold the primes for constant time access later
def eratosthenes(n, primes):
    lastPrime = 2
    primes[lastPrime] = True
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

# Add consecutive primes until the sum exceeds 1000000 and return last sum that was prime
# O(n^2) time to find i,j pair such that (j-i) is greatest possible,
# but (primeSums[j] - primeSums[i]), the sum from ith prime to jth prime, is a prime
def longestSumOfConsecPrimes(primes, primeSums, limit):
    num_primes = len(primes)
    longestSumLen = 0
    longestSumPrime = -1
    
    for i in xrange(0, num_primes):
        for j in xrange(i+longestSumLen+1, num_primes):
            # The sum of all the primes from the (i+1)th to jth
            sum = primeSums[j]-primeSums[i]
            if (sum > limit):
                break
            if (sum in primes):
                longestSumLen = j-i
                longestSumPrime = sum
    
    return [longestSumPrime, longestSumLen]


limit = 1000000
primes = {}
eratosthenes(limit, primes)
primesList = primes.keys()
# (O(nlogn) probably to sort the keys, else worst case n^2 in quick sort)
primesList.sort()
num_primes = len(primesList)

# O(n) time to fill sums array (O(n) memory)
primeSums = []
primeSums.append(0)
for primeIter in xrange(0, num_primes):
    primeSums.append(primeSums[-1] + primesList[primeIter])


ans = longestSumOfConsecPrimes(primes, primeSums, limit)
print(str(ans[0]) + " is a prime that's the sum of " + str(ans[1]) + " conseq. primes less than " + str(limit))
# Expected:  [997651, 543]
