#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream fin("B-large.in", ios_base::in);
	fstream fout("B-large.out", ios_base::out);

	int cases = 0;

	fin >> cases;
	cout << cases << " cases follow." << endl;

	for(int caseId = 1; caseId <= cases; caseId++)
	{
		int columns;
		int rows;

		fin >> rows;
		fin >> columns;

		int **grid = new int*[rows];

		int *horizontals = new int[rows];
		int *verticals = new int[columns];

		for(int row = 0; row < rows; row++)
		{
			grid[row] = new int[columns];
			for(int column = 0; column < columns; column++)
			{
				int cell;
				fin >> cell;
				grid[row][column] = cell;
				if(cell > horizontals[row])
				{
					horizontals[row] = cell;
				}
				if(cell > verticals[column])
				{
					verticals[column] = cell;
				}
			}
		}

		bool impossible = false;

		for(int row = 0; row < rows; row++)
		{
			for(int column = 0; column < columns; column++)
			{
				int cell = grid[row][column];
				if(cell < horizontals[row] && cell < verticals[column])
				{
					impossible = true;
				}
			}
		}

		string result;
		
		if(impossible)
		{
			result = "NO";
		}
		else
		{
			result = "YES";
		}

		cout << "Case #" << caseId << ": " << result << endl;
		fout << "Case #" << caseId << ": " << result << endl;
	}

	fout.close();
	cin.ignore();

	return 0;
}
