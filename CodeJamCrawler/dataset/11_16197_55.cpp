#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	
	int T, R, C;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> R >> C;
		char grid[R][C];
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				fin >> grid[i][j];
		
		bool poss = true;
		for (int k = 0; k <= R + C - 2; k++)
		{
			for (int y = 0; (y < C) && (y <= k); y++)
			{
				int x = k - y;
				if (x >= R)
					continue;
				if(grid[x][y] == '#')
				{
					if ((x == R - 1) || (y == C - 1))
					{
						poss = false;
						break;
					}
					grid[x][y] = '/';
					grid[x+1][y] = '\\';
					grid[x][y+1] = '\\';
					grid[x+1][y+1] = '/';
				}
			}
		}	
		fout << "Case #" << casenum << ": " << endl;
		if (!poss)
		{
			fout << "Impossible" << endl;	
		}
		else
		{
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
					fout << grid[i][j];
				fout << endl;
			}
		}
	}
}
