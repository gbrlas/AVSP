#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>

using namespace std;

enum{
	COMPLETE,
	INCOMPLETE,
	DRAW,
	WIN,
	NONE
};

int solveHoriz(ofstream &cout, int testCase, string row[4])
{
	for(int num = 0; num < 4; num++)
	{
		bool isT = false;
		char player;
		int numX = 0;
		int numY = 0;
		for(int index = 0; index < 4; index++)
		{
			char currChar = row[num][index];
			switch(currChar)
			{
			case '.': 
				continue;
			case 'T':
				isT = true;
				break;
			case 'X':
				player = currChar;
				numX++;
				break;
			case 'O':
				player = currChar;
				numY++;
				break;
			default:
				cout << "missing characters";
			}
		}

		if( (isT && (numX == 3 || numY == 3)) || (!isT && (numX == 4 || numY == 4)) )
		{
			cout << "Case #" << testCase + 1 << ": " << player << " won" << endl;
			return WIN;
		}

	}
	return NONE;
}

int solveVert(ofstream &cout, int testCase, string row[4])
{
	string column[4];
	for(int x = 0; x < 4; x++)
	{
		string temp;
		for(int z = 0; z < 4; z++)
			temp += row[z][x];
		column[x] = temp;
	}

	for(int num = 0; num < 4; num++)
	{
		bool isT = false;
		char player;
		int numX = 0;
		int numY = 0;
		for(int index = 0; index < 4; index++)
		{
			char currChar = column[num][index];
			switch(currChar)
			{
			case '.': 
				continue;
			case 'T':
				isT = true;
				break;
			case 'X':
				player = currChar;
				numX++;
				break;
			case 'O':
				player = currChar;
				numY++;
				break;
			default:
				cout << "missing characters";
			}
		}

		if( (isT && (numX == 3 || numY == 3)) || (!isT && (numX == 4 || numY == 4)) )
		{
			cout << "Case #" << testCase + 1 << ": " << player << " won" << endl;
			return WIN;
		}

	}
	return NONE;
}

int solveDiag(ofstream &cout, int testCase, string row[4])
{
	string diag[2];
	for(int i = 0; i < 4; i++)
	{
		diag[0] += row[i][i];
		diag[1] += row[i][3-i];
	}
		

	for(int num = 0; num < 2; num++)
	{
		bool isT = false;
		char player;
		int numX = 0;
		int numY = 0;
		for(int index = 0; index < 4; index++)
		{
			char currChar = diag[num][index];
			switch(currChar)
			{
			case '.': 
				continue;
			case 'T':
				isT = true;
				break;
			case 'X':
				player = currChar;
				numX++;
				break;
			case 'O':
				player = currChar;
				numY++;
				break;
			default:
				cout << "missing characters";
			}
		}

		if( (isT && (numX == 3 || numY == 3)) || (!isT && (numX == 4 || numY == 4)) )
		{
			cout << "Case #" << testCase + 1 << ": " << player << " won" << endl;
			return WIN;
		}

	}
	return NONE;
}
int solveCompletion(ofstream &cout, int testCase, string row[4])
{
	int numPeriods = 0;
	for(int num = 0; num < 4; num++)
	{
		for(int index = 0; index < 4; index++)
		{
			if(row[num][index] == '.')
			{
				cout << "Case #" << testCase + 1 << ": Game has not completed" << endl;
				return INCOMPLETE;
			}
		}
	}
	return COMPLETE;
}
int solveDraw(ofstream &cout, int testCase, string row[4])
{
	cout << "Case #" << testCase + 1 << ": Draw" << endl;
	return DRAW;
}
int main()
{
	ifstream cin("A-small-attempt1.in", ios::in);
	ofstream cout("out.out", ios::out);
	int testCases = 0;
	cin >> testCases;
	
	string (*grid)[4];
	grid = new string[testCases][4];

	for(int i = 0; i < testCases; i++)
	{
		for(int line = 0; line < 4; line++)
		{
			cin >> grid[i][line];
		}
	}

	for(int i = 0; i < testCases; i++)
	{
		if(solveHoriz(cout, i, grid[i]) == WIN)
			continue;
		if(solveVert(cout, i, grid[i]) == WIN)
			continue;
		if(solveDiag(cout, i, grid[i]) == WIN)
			continue;
		if(solveCompletion(cout, i, grid[i]) == INCOMPLETE)
			continue;
		if(solveDraw(cout, i, grid[i]) == DRAW)
			continue;
	}
	delete[] grid;
	cout.flush();
	cin.close();
	cout.close();
	return 0;
}