/*
1000-digit Fibonacci number
Problem 25

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn1 + Fn2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>

#define MAXDIGITS 1000

using namespace std;

int FnBigNum[MAXDIGITS], FnPrevBigNum[MAXDIGITS];

int main() {
    int numDigits = 1;
    FnBigNum[MAXDIGITS-1] = 1;
    FnPrevBigNum[MAXDIGITS-1] = 1;
    
    int i = 3;
    // Fn = Fn-1 + Fn-2
    // When computing next Fn, let: Fn-1 <= Fn, and Fn-2 <= Fn-1 = FnPrev
    for (; numDigits < MAXDIGITS; i++) {
    //for (; i < 143; i++) {
        int carry = 0, newValue, newDigit;
        
        // start adding digits from right to left
        for (int j = MAXDIGITS-1; j >= MAXDIGITS-numDigits; j--) {
            newValue = (FnBigNum[j] + FnPrevBigNum[j]) + carry;
            newDigit = newValue % 10;
            carry = newValue/10;
            FnPrevBigNum[j] = FnBigNum[j];
            FnBigNum[j] = newDigit;
            
            // Increment the number of digits if carry > 0 and iterator is at the previously known number of digits
            if (carry && j == MAXDIGITS-numDigits) {
                numDigits++;
            }
        }
    }
    
    i--;
    cout << "F(" << i << ") = ";
    for (int k = 0; k < MAXDIGITS; k++) {
        cout << FnBigNum[k];
    }
    
    cout << endl;
    return 0;
}
