"""
Permuted multiples
Problem 52
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
"""

def sameDigits(a, b):
    # Assume 0 will never be an input
    digits = [0] * 10
    while(a > 0):
        digit = a % 10
        digits[digit] += 1
        a = int(a/10)
    
    while(b > 0):
        digit = b % 10
        digits[digit] -= 1
        b = int(b/10)
    
    for digit in digits:
        if (digit != 0):
            return False
    return True
    
def solve(maxMultiplier):
    # n = maxMultiplier such that digits(x) = digits(2x) = ... = digits(n*x)
    x = 1
    while(x < 1000000):
        for n in xrange(2, maxMultiplier+1):
            if (sameDigits(x, x*n) == False):
                break
            if (n == maxMultiplier):
                return ([x, n*x])
        x += 1
    return -1

#print(solve(2))
# Expected: [125874, 251748]
print(solve(6))
# Expected: [142857, 857142]
# Answer: 142857