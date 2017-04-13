// CodeJam2014.cpp : Defines the entry point for the console application.
//

#include <fstream>
using namespace std;

ifstream cin("in.txt");
ofstream fout("out.txt");

int cases, g1, g2;
int grid1[4][4], grid2[4][4];

int main()
{
	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		cin >> g1;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> grid1[j][k];

		cin >> g2;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> grid2[j][k];

		int count = 0, res;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				if (grid1[g1 - 1][j] == grid2[g2 - 1][k])
				{
					res = grid1[g1 - 1][j];
					count++;
					break;
				}
		if (count == 0)
			fout << "Case #" << i + 1 << ": Volunteer cheated!" << endl;
		else if (count == 1)
			fout << "Case #" << i + 1 << ": " << res << endl;
		else fout << "Case #" << i + 1 << ": Bad magician!" << endl;
	}

	fout.close();
	return 0;
}

