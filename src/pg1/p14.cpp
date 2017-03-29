/*Longest Collatz sequence
Problem 14
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#define MAX 1000000

using namespace std;

unsigned int nextTerm(unsigned int n) {
    if (n % 2 == 0)
        n = n >> 1;
    else if (n > 1)
        n = 3*n + 1;

    return n;
}

int main() {
    int collatzNum = 0;
    int lengthCollatz = 0;
    for (unsigned int i = MAX; i > 0; i--) {
        int numTerms = 1;
        int n = nextTerm(i);
        while(n != 1) {
            numTerms++;
            n = nextTerm(n);
        }
        if (i != 1)
            numTerms++;

        if (numTerms > lengthCollatz) {
            collatzNum = i;
            lengthCollatz = numTerms;
        }
    }
    

    cout << "Number with longest Collatz sequence: " << collatzNum << ", with " << lengthCollatz << " terms." << endl;
    return 0;
}
