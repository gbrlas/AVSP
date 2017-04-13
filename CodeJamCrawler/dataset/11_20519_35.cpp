# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <utility>

using namespace std;

const double eps = 1e-6;

int c;
double d;
vector< pair<double, int> > h;

bool Possible(double m)
{
	double q = -1e5 - m;
	for (int i = 0; i < c; ++i)
	{
		double qq = max(q, h[i].first - m );
		if (qq + (h[i].second - 1)* d > h[i].first + m)
			return false;
		else
			q = qq + h[i].second * d;
	}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int u = 0; u < t; ++u)
	{
		cin >> c >> d;
		h = vector< pair<double, int> >();

		int vsum = 0;
		for (int i = 0; i < c; ++i)
		{
			double p;
			int v;
			cin >> p >> v;
			h.push_back(make_pair(p, v));
			vsum += v;
		}

		sort(h.begin(), h.end());

		double l = 0, r = d * vsum;
		while (r - l > eps)
		{
			double mid = (l + r) / 2.0;
			if (Possible(mid))
				r = mid;
			else
				l = mid;
		}

		
		cout << "Case #" << u + 1 << ": " << r << endl;
		
	}
	
	return 0;
}