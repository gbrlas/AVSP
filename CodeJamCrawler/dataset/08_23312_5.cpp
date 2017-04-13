#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int tests;

	cin >> tests;
	for (int t=1; t<=tests; t++)
	{
		int width, height, rocks;
		cin >> height >> width >> rocks;

		long long poss[101][101];
		for (int i=0; i<height; i++)
			for (int j=0; j<width; j++)
				poss[i][j] = 0;

		int x, y;
		for (int i=0; i<rocks; i++)
		{
			cin >> y >> x;
			poss[y-1][x-1] = -1;
		}

		poss[0][0] = 1;
		for (int i=0; i<height; i++)
			for (int j=0; j<width; j++)
			{
				if (poss[i][j] != -1 && j > 0 && i > 1 && poss[i-2][j-1] != -1)
					poss[i][j] = (poss[i][j] + poss[i-2][j-1]) % 10007;
				if (poss[i][j] != -1 && j > 1 && i > 0 && poss[i-1][j-2] != -1)
					poss[i][j] = (poss[i][j] + poss[i-1][j-2]) % 10007;
			}

		cout << "Case #" << t << ": " << poss[height-1][width-1] << endl;
	}

	return 0;
}