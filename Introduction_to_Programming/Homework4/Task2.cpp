/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <vector>

using namespace std;

bool isInputValid(int rows, int cols, int p, int q, int p1, int q1, int moves) {
	if ((rows <= 3 || rows > 200) || (cols <= 3 || cols > 200)) {
		return false;
	}

	if ((p < 0 || p > 200) || (q < 0 || q > 200) || (p1 < 0 || p1 > 200) || (q1 < 0 || q1 > 200)) {
		return false;
	}

	if (moves <= 0 || moves > 30) {
		return false;
	}

	return true;
}
bool areCoordinatesValid(int rows, int cols, int p, int q) {
	if (p < 0 || q < 0 || p >= rows || q >= cols) {
		return false;
	}

	return true;
}

bool contains(vector<vector<int>> coordinates,int p, int q) {
	for (int i = 0; i < coordinates.size(); i++) {
		if (coordinates[i][0] == p && coordinates[i][1] == q) {
			return true;
		}
	}

	return false;
}


bool isCoordinateReachable(int rows, int cols, int p1, int q1, int moves, vector<vector<int>>& coordinates, int index, int size) {

	if (moves == 0) {
		return false;
	}

	for (int i = index; i < size; i++) {
		++index;
		int p = coordinates[i][0];
		int q = coordinates[i][1];

		if (areCoordinatesValid(rows, cols, p + 2, q - 1) && !contains(coordinates, p + 2, q -1)){
			vector<int> currCoordinates{ p + 2, q - 1 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p + 2, q + 1) && !contains(coordinates, p + 2, q + 1)) {
			vector<int> currCoordinates{ p + 2, q + 1 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p - 2, q - 1) && !contains(coordinates, p - 2, q - 1)) {
			vector<int> currCoordinates{ p - 2, q - 1 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p - 2, q + 1) && !contains(coordinates, p - 2, q + 1)) {
			vector<int> currCoordinates{ p - 2, q + 1 };
			coordinates.push_back(currCoordinates);
		}

		if (areCoordinatesValid(rows, cols, p - 1, q + 2) && !contains(coordinates, p - 1, q + 2)) {
			vector<int> currCoordinates{ p - 1, q + 2 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p + 1, q + 2) && !contains(coordinates, p + 1, q + 2)) {
			vector<int> currCoordinates{ p + 1, q + 2 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p - 1, q - 2) && !contains(coordinates, p - 1, q - 2)) {
			vector<int> currCoordinates{ p - 1, q - 2 };
			coordinates.push_back(currCoordinates);
		}
		if (areCoordinatesValid(rows, cols, p + 1, q - 2) && !contains(coordinates, p + 1, q - 2)) {
			vector<int> currCoordinates{ p + 1, q - 2 };
			coordinates.push_back(currCoordinates);
		}
	}

	for (int i = 0; i < coordinates.size(); i++) {
		if (coordinates[i][0] == p1 && coordinates[i][1] == q1) {
			return true;
		}
	}

	return isCoordinateReachable(rows, cols, p1, q1, --moves, coordinates, index, coordinates.size());
}

int main()
{
	int rows, cols, p, q, p1, q1, moves;
	cin >> rows >> cols;
	cin >> p >> q;
	cin >> p1 >> q1;
	cin >> moves;
	
	if (!isInputValid(rows,cols,p,q,p1,q1,moves)) {
		cout << -1;
		return 0;
	}

	vector<vector<int>> coordinates;
	vector<int> startingCoordinates{ p,q };
	coordinates.push_back(startingCoordinates);

	if (isCoordinateReachable(rows, cols, p1, q1, moves, coordinates, 0, 1)) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	return 0;
}


