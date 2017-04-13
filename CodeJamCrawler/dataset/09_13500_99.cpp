#include <iostream>
#include <string>

using namespace std;

const string def = "welcome to code jam";

int main()
{
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);
	int q;
	cin >> q;
	string s;
	getline(cin, s);
	for (int qq = 0; qq < q; ++qq)
	{
		getline(cin, s);
		int a[501][20] = {0};
		a[0][0] = 1;
		for (int i = 1; i <= s.length(); ++i)
		{
			a[i][0] = a[i-1][0];
			for (int j = 1; j <= def.length(); ++j)
			{
				a[i][j] = a[i-1][j];
				if (s[i-1] == def[j-1]) a[i][j] = (a[i][j] + a[i-1][j-1]) % 10000;
			}	
		}
		cout << "Case #" << qq+1 << ": ";
		if (a[s.length()][def.length()] < 1000) cout << 0;
		if (a[s.length()][def.length()] < 100) cout << 0;
		if (a[s.length()][def.length()] < 10) cout << 0;
		cout << a[s.length()][def.length()] << '\n';
	}
	return 0;
}
