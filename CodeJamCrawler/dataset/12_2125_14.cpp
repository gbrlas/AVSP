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

using namespace std;

int main()
{
#ifdef DEBUG_OUTPUT
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int it = 1; it <= t; ++it)
	{
		int n, f;
		cin >> n;
		vector <int> d(n), l(n);
		for (int i = 0; i < n; ++i)
			cin >> d[i] >> l[i];
		cin >> f;
		vector <int> h(n, 0);
		h[0] = d[0];
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (d[j] + h[j] >= d[i])
					h[i] = max(h[i], min(d[i] - d[j], l[i]));
		bool p = 0;
		for (int i = 0; i < n; ++i)
			if (d[i] + h[i] >= f)
				p = 1;
		cout << "Case #" << it << ": ";
		if (p)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}