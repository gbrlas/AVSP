#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX_N = 800 + 100;
// max result: 10^10 * 800
int n;
long long x[MAX_N], y[MAX_N];

int main()
{
	int cases;
	cin >> cases;
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
			cin >> y[i];
		sort(x, x + n);
		sort(y, y + n);
		reverse(y, y + n);

		long long ans = 0;
		for (int i = 0; i < n; ++i)
			ans += x[i] * y[i];
		cout << "Case #" << caseNo + 1 << ": " << ans << endl;
	}
	return 0;
}

