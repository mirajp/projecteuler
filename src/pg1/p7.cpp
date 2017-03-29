/* 10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Find one prime and eliminate all the multiples from list of numbers as possible numbers to check if its prime. Count number of primes along the way.

#include <iostream>

#define MAX 200000

using namespace std;

bool check[MAX];

int main() {
    
    int count = 0;
    int target = 10001;
    int lastPrime = 0;
    for (int a = 2; (count < target) && (a < MAX) ; a++) {
        if (!check[a]) {
            for (unsigned int b = a; b < MAX; b += a) {
                check[b] = true;
            }
            
            lastPrime = a;
            count++;
        
            if (count == target)
                break;
        }
    }
    cout << "Last prime (#" << count << ") = " << lastPrime << endl;
    
    return 0;
}
