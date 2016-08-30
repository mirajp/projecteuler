/*
Maximum path sum I
Problem 18
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

/*
Yodle triangle problem:
http://www.yodlecareers.com/puzzles/triangle.html

By starting at the top of the triangle and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 27.

        5
      9  6
    4   6  8
  0   7  1   5

I.e. 5 + 9 + 6 + 7 = 27.

Write a program in a language of your choice to find the maximum total from top to bottom
in triangle.txt, a text file containing a triangle with 100 rows. Send your solution and
resume to [123456 AT yodle dot com], replacing 123456 with the maximum sum for the triangle. 
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
    string inputFile = "";
    string lineRead = "";
    vector<int> topRow;
    vector<int> bottomRow;
    vector<int> maxSum;
    
    int num, errno, numRows;
    
    //p18triangle.txt
    //cout << "Enter input file's path (that holds the triangle, space delimited):" << endl;
    //cin >> inputFile;
    //ifstream infile;
    //infile.open(inputFile.c_str());
    ifstream infile("../lib/p18triangle.txt");
    if (!infile.is_open()) {
        cout << "Error opening file: " << strerror(errno) << endl;
        return 1;
    }
    
    getline(infile, lineRead);
    numRows = 1;
    stringstream ssTop(lineRead);
    // Read the numbers from top row
    while (ssTop >> num) {
        topRow.push_back(num);
        maxSum.push_back(num);
    }
    
    // Read the next row
    while (getline(infile, lineRead)) {    
        stringstream ssBottom(lineRead);
        while (ssBottom >> num)
            bottomRow.push_back(num);
        
        int end = bottomRow.size();
        if (end == 0)
            break;
        
        numRows++;
        while(bottomRow.size() > maxSum.size())
            maxSum.push_back(0);
			
		/* Top down approach:
         First index in row that represents sum of kth row and (k+1)th row can only come from 1st element in both rows (hence the line right before the for loop)
		 Similarly, the last element can only be the sum of the last element in both rows (hence the line right after the for loop)
		*/
		maxSum[0] = topRow[0] + bottomRow[0];
        for (int i = 1; i < end-1; i++) {
			// For any other index, i, in the bottom row, the max sum possible is either from looking at exactly index i in the previous row, or index (i-1)
            if (topRow[i-1] > topRow[i])
				maxSum[i] = topRow[i-1] + bottomRow[i];
			else
				maxSum[i] = topRow[i] + bottomRow[i];
        }
		maxSum[end-1] = topRow[end-2] + bottomRow[end-1];
        
        topRow = maxSum;
        bottomRow.clear();
    }
    
    infile.close();
    
    int max = 0;
    for (int i = 0; i < maxSum.size(); i++) {
        // Find the max value from the resulting row which currently shows the max possible sum attainable while trickling down the triangle to that position in the base of the triangle
        if (maxSum[i] > max)
            max = maxSum[i];
    }
    
    cout << "The max sum is (out of " << numRows << " rows): " << max << endl;
    return 0;
}

