#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("d-small-attempt1.in");
//ifstream fin("d.in");
ofstream fout("d.out");

int R, C;
int kx, ky;
int dx[8] = {0, 1, 0, -1,1,1,-1,-1};
int dy[8] = {1, 0, -1, 0,-1,1,-1,1};
int now;
int d[200000][4][4];

int search(int state, int x, int y)
{
	if (d[state][x][y] != 0) return d[state][x][y];

	for (int i=0; i<8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0) continue;
		if (nx > 3) continue;
		if (ny <0 )continue;
		if (ny > 3) continue;
		if (((state >> 4*(3-nx)) & (1 << (3-ny))) != 0) continue;

		if (search(state ^ ((1 << (4 * (3-x) + 3-y))), nx, ny) == 2)
		{
			d[state][x][y] = 1;
			return 1;
		}
	}
	d[state][x][y] = 2;
	return 2;
}

int main()
{
	int N;
	fin >> N;
	int cases = 0;
	while (N--)
	{
		fin >> R >> C;
		now = 0;
		memset(d, 0, sizeof d);
		for (int i=0; i<R; i++)
		{
			string s;
			fin >> s;
			for (int j=0; j<C; j++)
			{
				if (s[j] == 'K')
				{
					kx = i;
					ky = j;
				}
				if (s[j] == '#')
				{
					now = (now<<1) + 1;
				}
				else now = (now<<1);
			}
			for (int j=0; j<4-C; j++)
				now = (now<<1)+1;
		}
		for (int i=0; i<4-R; i++)
			for (int j=0; j<4; j++)
				now = (now<<1)+1;

		if (search(now, kx, ky) == 1)
		{
			fout << "Case #" << ++cases << ": A" << endl;
		}
		else fout << "Case #" << ++cases << ": B" << endl;
	}
	return 0;
}