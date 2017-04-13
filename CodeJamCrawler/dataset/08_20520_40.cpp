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

int main()
{
	freopen("large.in", "rt", stdin);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n;
		cin >> n;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long res = 0;
		for (int i = 0; i < n; i++)
			res += a[i] * b[n - i - 1];
		cout << "Case #" << t + 1 << ": " << res << endl;
	}

	return 0;
}