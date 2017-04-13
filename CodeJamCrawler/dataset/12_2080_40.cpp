#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	vector < vector <int> > v(2000001);
	for (int i = 1; i <= 2000000; ++i)
	{
		if (i % 1000 == 0)
			printf("%.1lf %%\n", double(i) / 2000000 * 100);
		vector <int> d;
		int x = i;
		while (x)
		{
			d.push_back(x % 10);
			x /= 10;
		}
		reverse(d.begin(), d.end());
		for (int j = 1; j < d.size(); ++j)
		{
			int r = 0;
			if (d[j] == 0)
				continue;
			for (int k = j; k < d.size(); ++k)
			{
				r *= 10;
				r += d[k];
			}
			for (int k = 0; k < j; ++k)
			{
				r *= 10;
				r += d[k];
			}
			if (r >= 1 && r <= 2000000 && i < r)
				v[i].push_back(r);
		}
		sort(v[i].begin(), v[i].end());
		v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
	}
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int it = 1; it <= t; ++it)
	{
		int a, b;
		cin >> a >> b;
		long long ans = 0;
		for (int i = a; i <= b; ++i)
			for (int j = 0; j < v[i].size(); ++j)
				if (v[i][j] >= a && v[i][j] <= b)
					++ans;
		printf("Case #%d: %lld\n", it, ans);
	}
}