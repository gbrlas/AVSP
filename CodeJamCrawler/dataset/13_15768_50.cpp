#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int minNum = INT_MAX;
vector<pair<int, int>> minIndecies;
int pattern[100][100];
int rows, columns;

bool CheckRow(int row)
{
	for (int i = 0; i < columns; i++)
	{
		if (pattern[row][i] != minNum)
			return false;
	}

	return true;
}

bool CheckColumn(int column)
{
	for (int i = 0; i < rows; i++)
	{
		if (pattern[i][column] != minNum)
			return false;
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int cases;
	bool IsValid;

	cin >> cases;

	for (int t = 1; t <= cases; t++)
	{
		cin >> rows >> columns;
		IsValid = true;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> pattern[i][j];

				if (pattern[i][j] < minNum)
				{
					minNum = pattern[i][j];
					minIndecies.clear();
					minIndecies.push_back(make_pair(i, j));
				}
				else if (pattern[i][j] == minNum)
					minIndecies.push_back(make_pair(i, j));
			}
		}

		int prevRow = -1;

		for (int i = 0; i < minIndecies.size(); i++)
		{
			if ((minIndecies[i].first == prevRow || !CheckRow(minIndecies[i].first)) && !CheckColumn(minIndecies[i].second))
			{
				IsValid = false;
				break;
			}
		}

		cout << "Case #" << t << ": ";

		if (IsValid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		minIndecies.clear();
	}
}