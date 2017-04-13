#include <iostream>

using namespace std;

int main()
{
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);
	int l, d, n;
	cin >> l >> d >> n;
	string s[5000];
	for (int q = 0; q < d; ++q)
		cin >> s[q];
	for (int i = 0; i < n; ++i)
	{
		string t;
		cin >> t;
		int ans = 0;
		for (int k = 0; k < d; ++k)
		{
			int j = 0;
			int f = 1;
			for (int w = 0; w < l; ++w)
			{
					if (t[j] != '(')
					{
						f &= s[k][w] == t[j];
						j++;
					}
					else
					{
						int ff = 0;
						j++;
						for (; t[j] != ')'; ++j)
							ff |= t[j] == s[k][w];
						f &= ff;
						j++;
					}
			}
			ans += f;
		}
		cout << "Case #" << i + 1 << ": " << ans << '\n';
	}
	return 0;
}
