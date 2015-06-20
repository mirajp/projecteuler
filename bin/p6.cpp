/*
Sum square difference
Problem 6
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long sumOfSquares = 0;
    long squareOfSum = 0;
    int first = 1;
    int last = 100;

    squareOfSum = pow((first+last)*((last-first+1)/2), 2);
    for (int a = first; a <= last; a++) {
        sumOfSquares += pow(a, 2);
    }

    cout << "Sum of squares = " << sumOfSquares << endl;
    cout << "Square of the sum = " << squareOfSum << endl;

    cout << " Difference = " << (squareOfSum - sumOfSquares) << endl;
    return 0;
}
