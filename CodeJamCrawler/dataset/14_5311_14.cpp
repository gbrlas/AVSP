#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("A-small-attempt2.in");
	ofstream fout("A-small-attempt2.out");

	int T = 0;
	fin >> T;
	
	const int SIZE = 4;
	int ans1, ans2;
	int cards1[SIZE][SIZE];
	int cards2[SIZE][SIZE];
	for (int t = 1; t <= T; t++)
	{
		fin >> ans1;
		ans1--;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				fin >> cards1[i][j];
			}
		}
		fin >> ans2;
		ans2--;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				fin >> cards2[i][j];
			}
		}

		vector<int> result;

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (cards1[ans1][i] == cards2[ans2][j])
				{
					result.push_back(cards1[ans1][i]);
				}
			}
		}

		fout << "Case #";
		fout << t;
		fout << ": ";
		if (result.size() == 0)
		{
			fout << "Volunteer cheated!" << endl;
		}
		else if (result.size() == 1)
		{
			fout << result[0] << endl;
		}
		else
		{
			fout << "Bad magician!" << endl;
		}
	}
}