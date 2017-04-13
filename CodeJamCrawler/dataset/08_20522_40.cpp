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

int bc(int e)
{
	int r = 0;
	while  (e) 
	{
		r += (e & 1);
		e >>= 1;
	}
	return r;
}

int main()
{
	freopen("small.in", "rt", stdin);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> like[30][2];

		for (int i = 0; i < m; i++) {
			int tt;
			cin >> tt;
			for (int j = 0; j < tt; j++)
			{
				int aa, bb;
				cin >> aa >> bb;
				like[aa - 1][bb].push_back(i);
			}
		}

		int best = 2 * (1 << n) - 1;
		for (int i = 0; i < (1 << n); i++)
		{
			if (bc(best) > bc(i)) {
				map<int, int> w;
				int left = m;
				for (int j = 0; j < n; j++)
					for (int k = 0; k < like[j][(i >> j) & 1].size(); k++)
						if (w.find(like[j][(i >> j) & 1][k]) == w.end())
						{
							w[like[j][(i >> j) & 1][k]] = 1;
							left--;
						}
				if (left == 0) best = i;
			}
		}
		if (best != 2 * (1 << n) - 1) {
			cout << "Case #" << t + 1 << ":";
			for (int i = 0; i < n; i++) {
				if (best & ( 1 << i ) ) 
					cout << " 1";
				else 
					cout << " 0";
			}
			cout << endl;
		}
		else {
			cout << "Case #" << t + 1 << ": " << "IMPOSSIBLE" << endl;
		}

	}
	return 0;
}