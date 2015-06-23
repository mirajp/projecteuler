/* Summation of primes
 Problem 10
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 Find the sum of all the primes below two million.
 */

// Same approach as problem 7, just set max to 2000000

#include <iostream>

#define MAX 2000000

using namespace std;

bool check[MAX];

int main() {
    long sum = 0;
    for (int a = 2; a < MAX; a++) {
        if (!check[a]) {
            for (int b = a; b < MAX; b += a) {
                check[b] = true;
            }
            sum += a;
        }
    }

    cout << "Sum of all the primes less than " << MAX << " = " << sum << endl;

    return 0;
}
