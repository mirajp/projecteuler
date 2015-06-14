#include "prime.h"

// Set up an function to determine if input number is prime.
bool isPrime(long long n) {
    if (n == 1)
        return true;
    else {
        for (long long i = 2; i < n; i++) {
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
    for(long long i = 2; i <= quotient; i++) {
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

