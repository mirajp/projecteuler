/*
PROBLEM 21
Amicable numbers
 
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/
 
#include <iostream>
 
#define MAXNUM 10000
 
using namespace std;
 
long long sumOfDivisors(long long n) {
    long long sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
 
 
// Global initializes them to 0 indicating sum not checked yet
long long divisorSums[MAXNUM*2+1];
 
int main() {

    long long sumOfAmicables = 0;
       
    for (long long i = 1; i < MAXNUM; i++) {
        if (divisorSums[i] == 0)
            divisorSums[i] = sumOfDivisors(i);
           
        long long sd_i = divisorSums[i];
        if (sd_i <= MAXNUM*2 && sd_i > i) {
            if (divisorSums[sd_i] == 0)
                divisorSums[sd_i] = sumOfDivisors(sd_i);
               
            if (divisorSums[sd_i] == i) {
                // if d(d(i)) = i, then sd_i(= d(i)) and i are an amicable pair
                if (sd_i < MAXNUM && sd_i != i) {
                    sumOfAmicables += sd_i + i;
                }
            }
        }
    }
       
    cout << "Sum of amicable numbers = " << sumOfAmicables << endl;
       
    return 0;
}

