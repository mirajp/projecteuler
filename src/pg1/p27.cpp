/*
Quadratic primes
Problem 27
Euler discovered the remarkable quadratic formula:

n^2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40, 40^2+40+41 = 40(40+1)+41 is divisible by 41, and certainly when n=41, 41^2+41+41 is clearly divisible by 41.

The incredible formula n2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:
n2+an+b where |a|<1000 and |b|≤1000
where |n| is the modulus/absolute value of nn
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/

// Since n = 0 must result in a prime number when plugged into the polynomial n^2 + a*n + b, b must be prime
// Since n = 1 must also result in a prime number, but also follow: 1 + a + b >= 2, thus, a >= 1-b

#include <iostream>

#define MAXVALUE 100000
// use sieve of eratosthenes to determine which numbers are prime when counting consecutive prime values
// since global, all array values are automatically initialized to false
bool notPrime[MAXVALUE+1];

using namespace std;

int main() {
    
    notPrime[0] = true;
    notPrime[1] = true;
    for (int i = 2; i <= MAXVALUE; i++) {
        if (notPrime[i] == false) {
            for (int j = 2; j*i <= MAXVALUE; j++) {
                notPrime[j*i] = true;
            }
        }
    }
    
    int maxConsecPrimes = 0, productAB = 0;\
    //int polyA, polyB;
    for (int b = -999; b <= 999; b += 2) {
        if (notPrime[b] == false) {
            for (int a = 1-b; a >= -999 && a <= 999; a++) {
                int numConsecPrimes = 0;
                for (int n = 0; ; n++) {
                    long long value = (n*n) + (a*n) + b;
                    if (value > 0 && value <= MAXVALUE) {
                        if (notPrime[value] == false)
                            numConsecPrimes++;
                        else
                            break;
                    }
                    else {
                        break;
                    }
                }
                if (numConsecPrimes > maxConsecPrimes) {
                    //polyA = a;
                    //polyB = b;
                    productAB = a*b;
                    maxConsecPrimes = numConsecPrimes;
                }
            }
        }
    }
    
    
    //cout << "Max number of consecutive primes: " << maxConsecPrimes << endl;
    cout << "Product of A and B: " << productAB << endl;
    //cout << "A: " << polyA << ", B: " << polyB << endl;
    return 0;
}