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
int isSumOfAbundants[UPPERBOUND+1];
 
unsigned int sumOfDivisors(int n) {
    unsigned int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
 
using namespace std;
 
int main() {
    vector<int> abundantNumbers;
    unsigned int sum = 0;
    int minAbundantNumber = 12;
       
    for (int i = 1; i < minAbundantNumber; i++) {
        //cout << "Adding " << i << " as not a sum of 2 abundant numbers" << endl;
        sum += i;
    }
    
    /* to speed up, can add doubles of the number found as the sum of abundant numbers
    s(d) = x > d,
    s(2*d) >= x + d
    then s(2*d) > 2*d, 2*d is an abundant number that can be written as a sum of 2 abundant numbers
    */
    for (int i = minAbundantNumber; i <= UPPERBOUND; i++) {
        if (isSumOfAbundants[i] < 1) {
            // Upon reaching the value i+1, can conclude it is not the sum of 2 abundant numbers
            //cout << "Adding " << i << " as not a sum of 2 abundant numbers" << endl;
            sum += i;
               
            if (sumOfDivisors(i) > i) {
                //cout << i << " is an abundant number" << endl;
                abundantNumbers.push_back(i);
                for (int j = 0; j < abundantNumbers.size(); j++) {
                    int otherAbundantNumber = abundantNumbers[j];
                    if (otherAbundantNumber+i <= UPPERBOUND) {
                        if (isSumOfAbundants[otherAbundantNumber+i] == 0) {
                            abundantNumbers.push_back(otherAbundantNumber+i);
                            isSumOfAbundants[otherAbundantNumber+i] = 1;
                        }
                    }
                }
                for (int m = 2; ; m++) {
                    // all multiples of the abundant number are sums of abundant numbers
                    int otherAbundantNumber = m*i;
                    if (otherAbundantNumber <= UPPERBOUND) {
                        if (isSumOfAbundants[otherAbundantNumber] == 0) {
                            abundantNumbers.push_back(otherAbundantNumber);
                            isSumOfAbundants[otherAbundantNumber] = 1;
                        }
                    }
                    else
                        break;
                }
            }
        }
    }
    cout << "Number of abundantNumbers = " << abundantNumbers.size() << ", last one = " << abundantNumbers[abundantNumbers.size()-1] << endl;
    cout << "Sum of positive integers that aren't the sum of 2 abundant numbers = " << sum << endl;
    // not 197082603
    // not 153258423
    // 235551
    return 0;
}

