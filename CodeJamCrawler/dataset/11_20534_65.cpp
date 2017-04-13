# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
# include <utility>
# include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int u = 0; u < t; ++u)
	{
		int n, l, h;
		cin >> n >> l >> h;

		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i] ;

		bool fl;
		for (int i = l; i <= h; ++i)
		{
			fl = false;
			for (int j = 0; j < n; ++j)
			{
				if (!(a[j] % i == 0 || i % a[j] == 0))
					fl = true;
			}
			if (!fl)
			{
				cout << "Case #" << u + 1 << ": " << i << endl;
				goto l1;
			}
		}
		cout << "Case #" << u + 1 << ": " << "NO" << endl;
		l1: n = 0;
	}
	
	return 0;
}