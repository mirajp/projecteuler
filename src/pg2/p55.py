"""
Lychrel numbers
Problem 55
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?
"""

def reverseInt(n):
    return (int(str(n)[::-1]))

# Turn number into string, and reverse it and compare it against itself
def isIntPalindrome(n):
    digits = str(n)
    if (digits == digits[::-1]):
        return True
    return False

count = 0
start = 0
end = 10000

# NOTE: Want to try to add memoization/caching to reduce # of iterations that need to be checked
for x in xrange(start, end):
    for iter in xrange(0, 50):
        x_rev = reverseInt(x)
        sum = x + x_rev
        if (isIntPalindrome(sum)):
            break
        if (iter == 49):
            count += 1
        x = sum

print("There are " + str(count) + " Lychrel #s between " + str(start) + " and " + str(end))
# Expected: 249