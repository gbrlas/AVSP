#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int n, k;

long long v[200][200];
int d[200][200];


bool mok[1000000];
int _f[1000000];

int next(int mask, int m)
{
	bool ok = false;
	for (int i = 0; i < 20; i++)
	{
		if ((mask & (1 << i)) != 0 && ((m & (1 << i)) == 0))
		{
			int res = m;
			res |= (1 << i);
			for (int j = 0; j < i; j++)
				if ((mask & (1 << j)) != 0 && ((m & (1 << j)) != 0))
				{
					res ^= (1 << j);
				}
			return res;
		}
	}
	return -1;
}

int f(int mask)
{
	if (_f[mask] == -1)
	{
		if (mask == 0)
			return _f[mask] = 0;
		_f[mask] = n;
		int m = 0;
		while ((m = next(mask, m)) != -1)
		{
			if ((m | mask) == mask)
			{
				if (!mok[m])
				{
					int m1 = 0;
					for (int i = 0; i < n; i++)
						if ((m & (1 << i)) == 0 && ((mask & (1 << i)) != 0))
						{
							//cout << i << endl;
							m1 |= (1 << i);
						}
					//cout << m1 << endl;
					_f[mask] = min(_f[mask], 1 + f(m1));
				}
			}
		}
	}
	return _f[mask];
}

int main()
{
	int tc, t = 0;
	for (cin >> tc; t < tc; t++)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				cin >> v[i][j];
		
		memset(d, 0, sizeof(d));
		memset(mok, 0, sizeof(mok));
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int l = 0; l + 1 < k; l++)
				{
					if ((v[i][l] - v[j][l]) * (v[i][l + 1] - v[j][l + 1]) <= 0)
					{
						d[i][j] = d[j][i] = 1;
						
						break;
					}
				}
			}
		}

		for (int m = 0; m < (1 << n) ; m++)
		{
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if ((m & (1 << i)) != 0 && ((m & (1 << j)) != 0) && d[i][j] == 1)
						mok[m] = 1;
		}
		memset(_f, -1, sizeof(_f));
		cout << "Case #" << t + 1 << ": " << f((1 << n) - 1) << endl;
	}
	return 0;
}
