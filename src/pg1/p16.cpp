/* Power digit sum
Problem 16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <iostream>

#define POWER 1000
#define LENGTH 512
using namespace std;

int main() {
    int number[LENGTH];
    int newDigit = 0, carry = 0;

    for (int i = 0; i < LENGTH; i++) {
        number[i] = 0;
    }
    number[LENGTH-1] = 1;
    
    for (int i = 1; i <= POWER; i++) {
        for (int j = LENGTH-1; j >= 0; j--) {
            newDigit = carry + (number[j]*2);
            if (newDigit >= 10) {
                carry = (int) newDigit/10;
            }
            else {
                carry = 0;
            }
            
            newDigit = newDigit % 10;
            number[j] = newDigit;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < LENGTH; i++)
        sum += number[i];

    cout << "Sum = " << sum << endl;

}
