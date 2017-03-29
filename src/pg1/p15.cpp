/*Lattice paths
Problem 15
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/

// Noticing number of routes for 1x1 = 2, 1x2 (and 2x1) = 3, 1x3 (and 3x1) = 4, 2x2 = 6, and 2x3 (and 3x2) = 10
// the number of routes in [i,j] = sum([i-1,j], [i,j-1])

#include <iostream>

using namespace std;

long routes[20][20];

int main() {
	for (int i = 0; i < 20; i++) {
		routes[i][0] = i+2;
		routes[0][i] = i+2;
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			routes[i][j] = routes[i-1][j] + routes[i][j-1];
		}
	}
	
	cout << "Number of routes in a 20x20 = " << routes[19][19] << endl;
}