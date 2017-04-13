#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int p, v, n, d, t;
vector < pair < int, int > > a;
double l, r, m;

const double eps = 0.00000001;


bool can(double t)
{
	double board = -1e10;
	double p, v;
	
	for (int i = 0; i < a.size(); i++)
	{
		p = double(a[i].first);
		v = double(a[i].second);
		
		board = max(board, p - t);
		if (board > p + t + eps)
			return false;
			
		board += v*d;
		
		if (board - d > p + t + eps)
			return false;
	}
	
	return true;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(8);
	
	
	for (int i = 0; i < t; i++)
	{
		cin >> n >> d;
		
		cout << "Case #" << i + 1 << ": ";
		
		a.clear();
		
		for (int j = 0; j < n; j++)
		{
			cin >> p >> v;
			a.push_back(make_pair(p, v));
		}
		
		
		l = 0;
		r = 2000000000;
		
		while (l + eps < r)
		{
			m = (l + r)/2;
			
			if (can(m))
				r = m;
			else
				l = m;
		}
		
		cout << r << endl;
	}
	
	return 0;
}
