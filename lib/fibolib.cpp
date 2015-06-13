#include "fibolib.h"

// Make a function that returns the fibonacci sequence ending at a term less than 
std::vector<int> fiboMaxVal(int maxVal) {
	std::vector<int> fibo;
	if (maxVal < 1)
		return fibo;
	int fibterm = 1;
	int prev = 1;
	int temp;
	while(fibterm <= maxVal) {
		fibo.push_back(fibterm);
		int temp = fibterm;
		fibterm += prev;
		prev = temp;
	}
	
	return fibo;
}

