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

long double x[3], y[3], r[3];


long double D(int i, int j)
{
	long double dc = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	return 0.5 * (dc + r[i] + r[j]);
}

int main()
{
	int tc, t = 0;
	for (cin >> tc; t < tc; t++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> r[i];
		long double res;
		
		if (n == 1)
		{
			res = r[0];
		}
		if (n == 2)
		{
			res = max(r[0], r[1]);
		}
		if (n == 3)
		{
			res = 1000000;
			for (int i = 0; i < 3; i++)
			{
				res = min(res, max(r[i], D((i + 1) % 3, (i + 2) % 3)));
			}
		}
		cout << "Case #" << t + 1 << ": " << res << endl;
	}
	return 0;
}
 