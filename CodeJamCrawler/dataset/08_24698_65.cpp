#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

long long a[1000], b[1000];

int main()
{
	int T;
	cin >> T;
	int cases = 0;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+n, greater<long long>());
		long long res = 0;
		for (int i=0; i<n; i++) res += a[i] * b[i];
		cout << "Case #" << ++cases << ": " << res << endl;
	}
	return 0;
}