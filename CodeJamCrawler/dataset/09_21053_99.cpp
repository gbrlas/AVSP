#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

string w = "welcome to code jam";
string s;

int d[600][600];

char ts[1000];


int main()
{
	int tc, t = 0;
	for (cin >> tc, gets(ts); t < tc; t++)
	{
		gets(ts);
		s = string(ts);
		memset(d, 0, sizeof(d));
		int r = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == w[0]) r++;
				d[i][0] = r;
		}
		for (int j = 1; j < w.size(); j++)
		{
			r = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == w[j]) r += d[i][j - 1];
				r %= 10000;
				d[i][j] = r;
			}
		}
		printf("Case #%d: %04d\n", t + 1, d[s.size() - 1][w.size() - 1]);
	}
	return 0;
}