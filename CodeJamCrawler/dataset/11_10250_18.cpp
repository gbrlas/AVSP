#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T, x, g, r, n, v;
vector < pair < int, int > > a;
int b, e, w;
double ans, s, q, t;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	
	cout.setf(ios::fixed);
	cout.precision(7);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d%d%lf%d", &x, &g, &r, &t, &n);
		
		cout << "Case #" << i + 1 << ": ";
		
		a.clear();
		
		for (int j = 0; j < n; j++)
		{
			scanf("%d%d%d", &b, &e, &w);
			x -= e - b;
			a.push_back(make_pair(w, e - b));
		}
		
		a.push_back(make_pair(0, x));
		
		sort(a.begin(), a.end());
		
		ans = 0;
		
		for (int j = 0; j < a.size(); j++)
		{
			
			v = a[j].first;
			s = a[j].second;
			
			//cout << v << ' ' << s << endl;
			
			q = s / (v + r);
			
			if (q > t)
			{
				s -= t * (v + r);
				ans += t + s/(g + v);				
				t = 0;
			}
			else
			{
				ans += s/(v + r);
				t -= s/(v + r);
			}
			
			//cout << ans << endl;
		}
		
		cout << ans << endl;
	}

	return 0;
}
