#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

const int dx[4] = { 1, 1, 1, 0};
const int dy[4] = {-1, 0, 1, 1};

string m[5];

inline bool isok(int x, int y)
{
	return x>=0 && y>=0 && x<4 && y<4;
}

void getit(int i, int j, int k, int &x, int &o, int &t)
{
	x = o = t = 0;
	int p = 0;
	while (isok(i, j))
	{
		if (m[i][j] == 'X')
			++x;
		else if (m[i][j] == 'O')
			++o;
		else if (m[i][j] == 'T')
			++t;
		else
			++p;
		i += dx[k];
		j += dy[k];
	}
	if (x+o+t+p != 4)
		x = o = t = 0;
}

string solve()
{
	for (int i = 0; i < 4; ++i)
		cin >> m[i];

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 4; ++k)
			{
				int x, o, t;
				(j ? getit(0, i, k, x, o, t) : getit(i, 0, k, x, o, t));
				if (x+t == 4)
					return "X won";
				if (o+t == 4)
					return "O won";
			}
	for (int i = 0; i < 4; ++i)
		if (count(m[i].begin(), m[i].end(), '.'))
			return "Game has not completed";
	return "Draw";
}

int main()
{
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		cout << "Case #" << i << ": " << solve() << endl;

	return 0;
}
