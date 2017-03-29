/*
 Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

#define FACTOR1 3
#define FACTOR2 5
#define MAX 1000 

using namespace std;

int main() {
	long sum = 0;
	
	for(int i = 1; i < MAX; i++) {
		if ((i%FACTOR1 == 0) || (i%FACTOR2 == 0))
			sum = sum + i;
	}
	cout << "Sum of multiples of " << FACTOR1 << " and " << FACTOR2 << " less than " << MAX << " is equal to: " << sum << endl;
	return 0;
}
