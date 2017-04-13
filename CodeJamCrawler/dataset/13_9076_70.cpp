#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void determineState(bool &xWins, bool &oWins, bool &incomplete, string s)
{
	bool hasO = s.find("O") != string::npos;
	bool hasX = s.find("X") != string::npos;
	bool emptySpace = s.find(".") != string::npos;

	if(!hasO && !emptySpace)
	{
		xWins = true;
	}
	if(!hasX && !emptySpace)
	{
		oWins = true;
	}
	if(emptySpace)
	{
		incomplete = true;
	}
}

int main()
{
	fstream fin("A-small-attempt0.in", ios_base::in);
	fstream fout("A-small-attempt0.out", ios_base::out);

	int cases = 0;

	fin >> cases;
	cout << cases << " cases follow." << endl;

	for(int caseId = 1; caseId <= cases; caseId++)
	{
		const int columns = 4;
		const int rows = 4;

		char state[columns][rows];

		string horizontals[rows];
		string verticals[columns];
		string diagonal1;
		string diagonal2;

		for(int column = 0; column < columns; column++)
		{
			for(int row = 0; row < rows; row++)
			{
				char cell;
				fin >> cell;
				horizontals[column] += cell;
				verticals[row] += cell;
				if(row == column)
				{
					diagonal1 += cell;
				}
				if(row + column == columns - 1)
				{
					diagonal2 += cell;
				}
			}
		}

		bool incomplete = false;
		bool oWins = false;
		bool xWins = false;

		for(int column = 0; column < columns; column++)
		{
			determineState(xWins, oWins, incomplete, horizontals[column]);
		}

		for(int row = 0; row < rows; row++)
		{
			determineState(xWins, oWins, incomplete, verticals[row]);
		}

		determineState(xWins, oWins, incomplete, diagonal1);
		determineState(xWins, oWins, incomplete, diagonal2);

		string result = "Draw";
		if(incomplete)
		{
			result = "Game has not completed";
		}
		if(oWins)
		{
			result = "O won";
		}
		if(xWins)
		{
			result = "X won";
		}

		cout << "Case #" << caseId << ": " << result << endl;
		fout << "Case #" << caseId << ": " << result << endl;
	}

	fout.close();
	cin.ignore();

	return 0;
}
