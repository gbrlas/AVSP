#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0, _n = n; i < _n; ++i)
#define REP(i, a, b) for (int i = a, _n = b; i < _n; ++i)

int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small-attempt0.out");

	int tc;
	cin >> tc;
	rep(t, tc)
	{
		string s;
		cin >> s;
		map<char, int> m;

		vector<bool> du(100);
		du[1] = true;
		m[s[0]] = 1;
		int b = 2;
		REP(i, 1, s.size())
		{
			int j = 0;
			if (m.find(s[i]) == m.end())
			{
				while (du[j])
					++j;
				du[j] = true;
				if (j >= b)
					b = j + 1;
				m[s[i]] = j;
			}
		}

		long long r = 0;
		rep(i, s.size())
		{
			r = b * r + m[s[i]];
		}

		cout << "Case #" << (t + 1) << ": " << r << '\n';

	}

	return 0;
}