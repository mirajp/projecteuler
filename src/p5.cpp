/*
Smallest multiple
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/


#include <iostream>
#include <cmath>
#include "../lib/prime.h"


using namespace std;
int lcmcount[21];
int localcount[21];

int main() {
    long lcm = 1;
    for (int a = 11; a < 21; a++) {
        vector<long> factors = primeFactors(a);
        
        //cout << "Prime factorization of " << a << " is: " ;
        for (int b = 0; b < factors.size(); b++) {
            //cout << factors[b] << " " ;
            localcount[factors[b]]++;
        }
        //cout << "." << endl;

        for (int b = 2; b < 21; b++) {
            if (localcount[b] > lcmcount[b])
                lcmcount[b] = localcount[b];
            localcount[b] = 0;
        }
    }

   
    lcm = 1;
    for (int c = 2; c < 21; c++) {
        //cout << "Multiplying on " << pow(c, lcmcount[c]) << endl;
        lcm *= pow(c, lcmcount[c]);
    }
    
    cout << "LCM = " << lcm << endl;

    return 0;
}
