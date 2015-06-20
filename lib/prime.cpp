#include "prime.h"
#include <cmath>

// Set up an function to determine if input number is prime.
bool isPrime(long long n) {
    if (n == 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    else {
        for (long long i = 3; i <= pow(n, 0.5); i+=2) {
            if (n%i == 0)
                return false;
        }
        return true;
    }
}

// create vector of prime factors
std::vector<long> primeFactors(long long n) {
    std::vector<long> factors;
    long long quotient = n;
    
    while(quotient%2 == 0) {
        quotient /= 2;
        factors.push_back(2);
    }

    for(long long i = 3; i <= quotient; i+=2) {
        if (isPrime(i)) {
            while(quotient%i == 0) {
                //cout << "Dividing by " << i << endl;
                quotient /= i;
                factors.push_back(i);
                //cout << "\tQuotient now: " << quotient << endl;
            }
        }
    }
    
    return factors;
}

