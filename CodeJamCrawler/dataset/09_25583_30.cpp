/*
 * main.cpp
 *
 *  Created on: 03-Sep-2009
 *      Author: samkit
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct coordinate {
	size_t x;
	size_t y;
	int direction;
public:
	coordinate(int x, int y, int direction)
	   :x(x), y(y), direction(direction) { }

	int getX() { return x; }
	int getY() { return y; }
	int getDirection() { return direction; }

	bool operator>(struct coordinate* t2) {
		if(direction > t2->direction)
			return true;
		return false;
	}
};

bool extractMatrix(ifstream &inFile, vector<vector<int> > &matrix)
{
	int H = matrix.size();

	if(H <= 0) return true;

	int W = matrix[0].size();

	for(int j = 0; j < H; ++j) {
		for(int k = 0; k < W; ++k) {
			inFile >> matrix[j][k];
		}
	}
	return true;
}

struct coordinate* getMinNeighbour(const vector<vector<int> > &matrix, size_t x, size_t y)
{
	multimap<int, struct coordinate*> neighbours;

	if(x > 0)			// North
		neighbours.insert(pair<int, struct coordinate*>(matrix[x - 1][y], new coordinate(x - 1, y, 0)));

	if(y > 0)			// West
		neighbours.insert(pair<int, struct coordinate*>(matrix[x][y - 1], new coordinate(x, y - 1, 1)));

	if(y < matrix[0].size() - 1)		// East
		neighbours.insert(pair<int, struct coordinate*>(matrix[x][y + 1], new coordinate(x, y + 1, 2)));

	if(x < matrix.size() - 1)		// South
		neighbours.insert(pair<int, struct coordinate*>(matrix[x + 1][y], new coordinate(x + 1, y, 3)));

//	int maxCounts = neighbours.count((*neighbours.begin()).first);
	struct coordinate* goToColumn = 0;

//	for(map<int, struct coordinate*>::const_iterator i = neighbours.begin(); i != neighbours.end(); ++i) {
//		cout << "Neighbours for " << x << " " << y << " is " << " ." << ((*i).second)->getX() << ". ." << ((*i).second)->getY()
//		     << ". ." << (*i).first << "." << matrix[0].size() << endl;
//	}

	if(neighbours.size() > 0 && matrix[x][y] > neighbours.begin()->first) {
		typedef map<int, struct coordinate*>::const_iterator CI;

		pair<CI, CI> i = neighbours.equal_range((*neighbours.begin()).first);
		goToColumn = (*i.first).second;

		for(CI j = i.first; j != i.second; ++j) {
			if(*goToColumn > (*j).second) {
				delete goToColumn;
				goToColumn = (*j).second;
			}
		}

//		if(i.first == neighbours.end())
//			goToColumn = 0;

//		cout << "Minimum Column for " << x << " " << y << " is " << (*goToColumn).getX() << " " << (*goToColumn).getY()  << " with " << (*goToColumn).getDirection() << endl;
	}
	return goToColumn;
}

void labelMatrix(const vector<vector<int> > &matrix, vector<vector<char> > &labelledMatrix, size_t x, size_t y, char &label, const int recursion)
{
	if(recursion == 0 && labelledMatrix[x][y] != ' ') return;

//	cout << "Here1" << endl;
	struct coordinate* goToColumn = getMinNeighbour(matrix, x, y);

	if(goToColumn != 0) {
		size_t tempX = goToColumn->getX();
		size_t tempY = goToColumn->getY();

//		cout << "Here2 for " << x << " " << y << " is " << tempX << " " << tempY << " " << label << endl;

		labelMatrix(matrix, labelledMatrix, tempX, tempY, label, recursion + 1);

//		cout << "Here1 for " << x << " " << y << " is " << tempX << " " << tempY << " " << label << endl;

		labelledMatrix[x][y] = label;
		delete goToColumn;
		return;
	}


	if(labelledMatrix[x][y] != ' ') {
		label = labelledMatrix[x][y];
	}
	else {
		labelledMatrix[x][y] = ++label;
	}

//	cout << "Minimum Column for " << x << " " << y << " is " << (*goToColumn).getX() << " " << (*goToColumn).getY()  << " with " << (*goToColumn).getDirection() << endl;

	return;
}

bool parseMatrix(const vector<vector<int> > &matrix, ofstream &outFile)
{
	char label = 'a' - 1;
	size_t H = matrix.size();

	if(H <= 0) return true;

	size_t W = matrix[0].size();

//	for(size_t i = 0; i < H; ++i) {
//		for(size_t j = 0; j < W; ++j)
//			cout << matrix[i][j] << ". ";
//		cout << endl;
//	}
//
//	cout << endl;

	vector<vector<char> > labelledMatrix(H, vector<char>(W, ' '));

	for(size_t i = 0; i < H; ++i) {
		for(size_t j = 0; j < W; ++j) {
//			cout << labelledMatrix[i][j] << ". ";
			labelMatrix(matrix, labelledMatrix, i, j, label, 0);

		}
//		cout << endl;
	}

	for(size_t i = 0; i < H; ++i) {
		for(size_t j = 0; j < W; ++j) {
			cout << labelledMatrix[i][j] << " ";
			outFile << labelledMatrix[i][j] << " ";
		}
		cout << endl;
		outFile << endl;
	}

	return true;
}

int main()
{
	ifstream inFile("input");
	ofstream outFile("output");

	int T = 0;
	inFile >> T;

	for(int i = 0; i < T; ++i) {
		int H = 0;
		int W = 0;

		inFile >> H >> W;

		vector<vector<int> > matrix(H, vector<int>(W, 0));

		extractMatrix(inFile, matrix);

		cout << "Case #" << i + 1 << ":" << endl;
		outFile << "Case #" << i + 1 << ":" << endl;
		parseMatrix(matrix, outFile);

	}

	inFile.close();
	return 0;
}
