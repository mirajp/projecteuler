/*
Largest prime factor
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

// Iterate through from 1 to the max possible factor, itself, dividing away from the number if it is a prime. For example: for a number such as 24: keep dividing by until the quotient remaining is 3. Then divide by 3 -> largest prime number is thus 3.

#include <iostream>
#include "../lib/prime.h"
using namespace std;

int main() {
    long long quotient = 600851475143;
    vector<long>factors = primeFactors(quotient); 
    cout << "Largest prime factor = " << factors.back() << endl;
    
    return 0;
}
