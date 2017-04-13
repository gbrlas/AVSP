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

	int test;
	cin >> test;
	for (int u = 0; u < test; ++u)
	{
		int l, n, c;
		long long t;
		cin >> l >> t >> n >> c;
		
		vector<long long> seg(n);
		vector<long long> a(c); 
		for (int i = 0; i < c; ++i)
			cin >> a[i];
		
		long long total_time = 0;
		for (int i = 0; i < n; ++i)
		{
			seg[i] = a[i % c];
			total_time += seg[i] * 2;
			if (total_time < t)
				seg[i] = 0;
			else if (total_time - seg[i] * 2 < t)
				seg[i] = (total_time - t) / 2;
		}

		sort(seg.rbegin(), seg.rend());

		for (int i = 0; i < l; ++i)
			total_time -= seg[i];

		cout << "Case #" << u + 1 << ": " << total_time << endl;
	}
	
	return 0;
}