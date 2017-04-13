#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;


ll t, n, m, ans, s, p;
const ll N_MAX = 2000000000;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> t;
	
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		
		m = N_MAX;
		ans = 0;
		s = 0;
		
		
		for (int j = 0; j < n; j++)
		{
			cin >> p;
			ans ^= p;
			
			s += p;
			
			m = min(m, p);
		}
		
		
		cout << "Case #" << i + 1 << ": ";
		
		if (ans)
		{
			cout << "NO\n";
			continue;
		}
		
		cout << s - m << endl;
	}
	
	
	return 0;
}
