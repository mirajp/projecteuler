/*
Factorial digit sum
Problem 20
n! means n*(n-1)*...*3*2*1

For example, 10! = 10*9*...*3*2*1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <iostream>
#define MAXNUMDIGITS 256
#define LASTFACTORIAL 100
 
using namespace std;
 
 
int bigNum[MAXNUMDIGITS];
 
 
int sum(long long n) {
    int sum = 0;

    for ( ; n > 0; ) {
                    sum += (n%10);
                    n /= 10;
    }
    return sum;
}
 
int main() {
    //0! = 1! = 1;
    bigNum[MAXNUMDIGITS-1] = 1;

    for (int i = 2; i <= LASTFACTORIAL; i++) {
        int carry, newValue, newDigit;
        carry = newValue = newDigit = 0;
        for (int j = MAXNUMDIGITS-1; j >= 0; j--) {
            newValue = (bigNum[j] * i) + carry;
            newDigit = newValue % 10;
            carry = newValue/10;
            bigNum[j] = newDigit;
        }
    }
    int sumOfDigits = 0;
    for (int i = 0; i < MAXNUMDIGITS; i++) {
        cout << bigNum[i];
        sumOfDigits += bigNum[i];
    }
    cout << endl;
    cout << "Sum of " << LASTFACTORIAL << "! = " << sumOfDigits << endl;

    /*
    real    0m1.070s
    user    0m0.512s
    sys     0m0.529s
    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000093326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
    Sum of 100! = 648
    */

    return 0;
}
