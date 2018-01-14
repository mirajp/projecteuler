"""
Powerful digit sum
Problem 56 
A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
"""

def sumOfDigits(integer):
    numStr = str(integer)
    digitSum = 0
    for c in numStr:
        digitSum += int(c)
    return digitSum

maxSum = 0
for a in xrange(2, 100):
    for b in xrange(1, 100):
        number = a**b
        digitSum = sumOfDigits(number)
        if digitSum > maxSum:
            maxSum = digitSum

print(maxSum)
# Expected: 927
