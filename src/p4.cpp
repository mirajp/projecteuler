/*
Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Iterate through half the string and compare character-wise
bool isPalindrome(int n) {
    ostringstream ss;
    ss << n;
    string number = ss.str();
    int length = number.length();

    for (int i = 0; i < ceil(length/2); i++) {
        if (number[i] != number[length-(i+1)])
            return false;
    }

    return true;
}

// Nested loop, iterating down from largest possible n-digit number
int palindrome(int numdigA, int numdigB) {
    int minA = pow(10, numdigA-1);
    int maxA = pow(10, numdigA) - 1;
    int minB = pow(10, numdigB-1);
    int maxB = pow(10, numdigB) - 1;
    
    //cout << "minA = " << minA << ", maxA = " << maxA << endl;
    //cout << "minB = " << minB << ", maxB = " << maxB << endl;

    int largest = 0;

    for (int a = maxA; a >= minA; a--) {
        for (int b = maxB; b >= minB; b--) {
            if (largest < b*a) {
                if (isPalindrome(b*a))
                    largest = b*a;
            }
        }
        if (a*maxB < largest)
            break;
    }
    
    return largest;

}

int main() {
    cout << "Largest palindrome from a 2 and 2 digit number: " << palindrome(2, 2) << endl;
    
    cout << "Largest palindrome from a 2 and 3 digit number: " << palindrome(2, 3) << endl;

    cout << "Largest palindrome from a 3 and 3 digit number: " << palindrome(3, 3) << endl;

}
