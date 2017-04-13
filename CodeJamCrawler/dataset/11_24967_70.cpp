#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

int solve ()
{
	int n;
	
	cin >> n;
	
	vector < int > a(n);
	
	int sum = 0, sum_normal = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum ^= a[i];
		sum_normal += a[i];
	}
	
	sort(a.begin(), a.end());
		
	int l = 0, r = sum;
	
	for (int i = 0; i < a.size(); ++i)
	{
		sum_normal -= a[i];
		r ^= a[i];
		l ^= a[i];
		
		if (l == r)
			return sum_normal;
	}
	
	return 0;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		int t = solve();
		
		cout << "Case #" << (i + 1) << ": ";

		if (t)
			cout << t << endl;
		else
			cout << "NO" << endl;
	}		
	return 0;
}
