#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int c=1; c<=t; c++)
	{
		long long res = 0;
		int n;

		cin >> n;
		vector<long long> a(n), b(n);
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		for (int i=0; i<n; i++) res += a[i]*b[i];
		
		printf("Case #%d: %lld\n", c, res);
	}
	return 0;
}
