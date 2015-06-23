/*Special Pythagorean triplet
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

// Since the sum of any two sides of a triangle have to be greater than the third, the side with the greatest length of the triangle measures less than half the sum of all three sides' lengthes.

#include <iostream>
#include <cmath>
#define SUM 1000

using namespace std;

int main() {
    int a, b, c;
    int pythPd = 0;

    for (a = 1; a < (SUM/2); a++) {
        for (b = 1; b < SUM-a-1; b++) {
            c = SUM-a-b;

            if ((a*a) + (b*b) == (c*c)) {
                pythPd = a*b*c;
                break;
            }
        }
        
        if (pythPd > 0)
            break;
    }
    
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "a*b*c = " << pythPd << endl;
    return 0;
}
