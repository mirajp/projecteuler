/*
Non-abundant sums
Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <vector>
 
#define UPPERBOUND 28123
//#define UPPERBOUND 100
 
// 1 = it is sum of 2 abundant numbers
//int isSumOfAbundants[UPPERBOUND+1];
 
unsigned int sumOfDivisors(int n) {
    unsigned int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
 
using namespace std;

bool isSumOfAbundants[UPPERBOUND+1];

int main() {
    vector<int> abundantNumbers;
    int sum = 0;
    for (int i = 12; i <= UPPERBOUND; i++) {
        if (sumOfDivisors(i) > i)
            abundantNumbers.push_back(i);
    }
    
    for (int i = 0; i < abundantNumbers.size(); i++) {
        for (int j = i; j < abundantNumbers.size(); j++) {
            int sumOfAbundantNumbers = abundantNumbers[i] + abundantNumbers[j];
            if (sumOfAbundantNumbers <= UPPERBOUND)
                isSumOfAbundants[sumOfAbundantNumbers] = true;
        }
    }
    
    for (int i = 1; i <= UPPERBOUND; i++) {
        if (!isSumOfAbundants[i])
            sum += i;
    }
    
    cout << "Sum of numbers that are not a sum of 2 abundantNumbers = " << sum << endl;
    
    return 0;
}
