#include <iostream>

using namespace std;

int main()
{
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);
	int t, T;
	cin >> t;
	for (int T = 0; T < t; ++T)
	{
		string s;
		cin >> s;
		int c[256] = {0};
		for (int i = 0; i < s.length(); ++i)
			c[s[i]]++;
		int k = 0;
		for (int i = 0; i < 256; ++i)
			k += !!c[i];
		if (k == 1) k++;
		long long ans = 0;
		long long b = 1;
		for (int i = 0; i+1 < s.length(); ++i)
			b *= k;
		int cc[256];
		for (int i = 0; i < 256; ++i)
			cc[i] = -1;
		int cur = 0;
		ans += b;
		b /= k;
		cc[s[0]] = 1;
		for (int i = 1; i < s.length(); ++i)
		{
			if (cc[s[i]] < 0)
				cc[s[i]] = cur++;
			if (cur == 1)
				cur++;
			ans += b * cc[s[i]];
			b /= k;
		}
		cout << "Case #" << T+1 << ": " << ans << '\n';
	}
	return 0;
}
