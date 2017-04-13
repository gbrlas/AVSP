# include <stdio.h>
# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin >> test;
	for (int tst = 0; tst < test; ++tst)
	{
		double ans = 0.0;
		double x, s, r, t, n;
		cin >> x >> s >> r >> t >> n;

		vector<pair<double, double> > way;
		for (int i = 0; i < n; ++i)
		{
			double b, e, w;
			cin >> b >> e >> w;
			way.push_back(make_pair(w, e - b));
			x -= e - b;
		}
		sort(way.begin(), way.end());

		double tmp = x / r;
		if (t > tmp)
		{
			ans += tmp;
			t -= tmp;
		}
		else
		{
			ans += t;
			ans += (x - t * r) / s;
			t = 0;
		}

		for (int i = 0; i < n; ++i)
		{
			double tmp = way[i].second / (r + way[i].first);
			if (t > tmp)
			{
				ans += tmp;
				t -= tmp;
			}
			else
			{
				ans += t;
				ans += (way[i].second - t * (r + way[i].first)) / (way[i].first + s);
				t = 0;
			}
		}
		
		printf("Case #%d: %0.7lf\n", tst + 1, ans);
		//cout << "Case #" << tst << ": " << ans << endl;
	}
}