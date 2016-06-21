/*
Counting Sundays
Problem 19
You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
    How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>

using namespace std;

int main() {
    
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int numSundays = 0;
    int dayOfWeek = 1; // Jan 1, 1900 = Monday (call 0 = Sunday, 6 = Saturday)
    // if dayOfWeek + numDaysInMonth % 7 == 0, then the first day of the next month is a Sunday    

    for (int year = 1900; year <= 2000; year++) {
        if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0))) {
            daysInMonth[1] = 29;
        }
        else {
            daysInMonth[1] = 28;
        }
        for (int month = 0; month < 12; month++) {
            if (month == 11 && year == 2000)
                break;
            
            dayOfWeek = (dayOfWeek + daysInMonth[month]) % 7;
            if (dayOfWeek == 0 && year > 1900) {
                numSundays++;
            }
        }
        
    }

    cout << "Number of Sundays on the first of the month in the 20th century = " << numSundays << endl;


    return 0;
}

