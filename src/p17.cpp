/*Number letter counts
Problem 17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115
(one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>

int lengths[1001];
int tensLengths[10];

using namespace std;

// Returns the length of the number of just the 10s place (1X, 2X, 3X, ..., 9X)
int tensPlaceLength(int number) {
	int tensNumber = number % 100;
	if (tensNumber % 100 < 20) {
		return lengths[tensNumber];
	}
	else {
		int onesDigit = tensNumber % 10;
		int tensDigit = (tensNumber - onesDigit)/10;
		return (tensLengths[tensDigit] + lengths[onesDigit]);
	}
}

// Adds length of the hundreds place and calls function to add on tens and ones place
int numberLength (int number) {
	// "one thousand"
	if (number == 1000) {
		return 11;
	}
	
	int hundredsDigit = (number - (number % 100))/100;
	if (hundredsDigit) {
		// if not a multiple of 100
		if (number % 100 > 0) {
			// length of "hundred and" = 10
			if (number == 132) {
			cout << "Len100 = " << lengths[hundredsDigit] << endl;
			cout << "Len10 = " << tensPlaceLength(number) << endl;
			}
			return (lengths[hundredsDigit] + 10 + tensPlaceLength(number));
		}
		else {
			// length of "hundred" = 7
			return (lengths[hundredsDigit] + 7);
		}
	}
	else {
		return (tensPlaceLength(number));
	}	
}

int main() {
	int number;
	cout << "Enter an integer as the end number:" << endl;
	// Assuming on valid (integer) input will be entered
	cin >> number;
	if (number > 1000)
		number = 1000;
	
	lengths[0] = 0; // used to add 0 for numbers like twenty-zero, thirty-zero (since counting from 1, 0's length doesn't matter)
	lengths[1] = 3;
	lengths[2] = 3;
	lengths[3] = 5;
	lengths[4] = 4;
	lengths[5] = 4;
	lengths[6] = 3;
	lengths[7] = 5;
	lengths[8] = 5;
	lengths[9] = 4;
	lengths[10] = 3;
	lengths[11] = 6;
	lengths[12] = 6;
	lengths[13] = 8;
	lengths[14] = 8;
	lengths[15] = 7;
	lengths[16] = 7;
	lengths[17] = 9;
	lengths[18] = 8;
	lengths[19] = 8;
	lengths[20] = 6;
	tensLengths[2] = 6; //twenty
	tensLengths[3] = 6; //thirty
	tensLengths[4] = 5; //forty
	tensLengths[5] = 5; //fifty
	tensLengths[6] = 5; //sixty
	tensLengths[7] = 7; //seventy
	tensLengths[8] = 6; //eighty
	tensLengths[9] = 6; //ninety
	
	int sum = 0;
	for (int i = 1; i <= number; i++) {
		sum += numberLength(i);
	}
	cout << "Length of " << number << " = " << numberLength(number) << endl;
	cout << "Length of all the numbers from 1 to " << number << " = " << sum << endl;
}