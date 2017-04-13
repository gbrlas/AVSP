#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define EPS 1e-6

int n;
double a[10], b[10];
int dp1[1<<10][1<<10][2][10];
int dp2[1<<10][1<<10][2][10][2];

int f1(int b1, int b2, int p, int lb)
{
	if (b2 == (1<<n)-1)
		return 0;
	if (dp1[b1][b2][p][lb] != -1)
		return dp1[b1][b2][p][lb];
	int ret;
	if (p == 0)
	{
		ret = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((b1 & (1<<i)) == 0)
				ret = max(ret, f1(b1|(1<<i), b2, 1, i));
		}
	}
	else
	{
		double w = a[lb];
		int bi = -1;
		int mi = -1;
		for (int i = 0; i < n; ++i)
		{
			if ((b2 & (1<<i)) != 0)
				continue;
			if (mi == -1 || b[i] < b[mi])
				mi = i;
			if (b[i] > w && (bi == -1 || b[i] < b[bi]))
				bi = i;
		}
		if (bi == -1)
			ret = 1+f1(b1, b2|(1<<mi), 0, 0);
		else
			ret = f1(b1, b2|(1<<bi), 0, 0);
	}
	return dp1[b1][b2][p][lb] = ret;
}

int f2(int b1, int b2, int p, int lb, int l)
{
	if (b2 == (1<<n)-1)
		return 0;
	if (dp2[b1][b2][p][lb][l] != -1)
		return dp2[b1][b2][p][lb][l];
	int ret;
	if (p == 0)
	{
		ret = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((b1 & (1<<i)) == 0)
			{
				ret = max(ret, f2(b1|(1<<i), b2, 1, i, 0));
				int mi = -1;
				for (int j = 0; j < n; ++j)
				{
					if ((b2 & (1<<j)) != 0)
						continue;
					if (mi == -1 || b[mi] > b[j])
						mi = j;
				}
				if (mi != -1 && a[i] > b[mi])
					ret = max(ret, f2(b1|(1<<i), b2, 1, 0, 1)); 
			}
		}
	}
	else
	{
		double w = l == 0 ? a[lb] : 1000;
		int bi = -1;
		int mi = -1;
		for (int i = 0; i < n; ++i)
		{
			if ((b2 & (1<<i)) != 0)
				continue;
			if (mi == -1 || b[i] < b[mi])
				mi = i;
			if (b[i] > w && (bi == -1 || b[i] < b[bi]))
				bi = i;
		}
		if (bi == -1)
			ret = 1+f2(b1, b2|(1<<mi), 0, 0, 0);
		else
			ret = f2(b1, b2|(1<<bi), 0, 0, 0);
	}
	return dp2[b1][b2][p][lb][l] = ret;
}

int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		cout << "Case #" << tt << ": " << f2(0, 0, 0, 0, 0) << " " << f1(0, 0, 0, 0) << "\n";
	}
	return 0;
}
