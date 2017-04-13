#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int d[200][200];
int map[200][200];
int W, H, R;
int r, c;
int N;

int main()
{
	int cases = 0;
	cin >> N;
	while (N--)
	{
		cin >> H >> W >> R;
		memset(map, 0, sizeof map);
		for (int i=0; i<R; i++)
		{
			cin >> r >> c;
			map[r-1][c-1] = -1;
		}
		memset(d, 0, sizeof d);
		d[0][0] = 1;
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++)
			{
				int ni = i + 2;
				int nj = j+1;

				if (ni < H && nj < W && map[ni][nj] == 0)
				{
					d[ni][nj] = (d[ni][nj] + d[i][j]) % 10007;
				}

				ni = i+1;
				nj = j + 2;
				if (ni < H && nj < W && map[ni][nj] == 0)
				{
					d[ni][nj] = (d[ni][nj] + d[i][j]) % 10007;
				}
			}
			cout << "Case #" << ++cases << ": " << d[H-1][W-1] << endl;
	}
	return 0;
}