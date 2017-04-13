#include "global.h"

vector< set<char> > curr;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int l, d, n;
	//scanf("%d", &l, &d, &n);
	cin >> l >> d >> n;
	vector<string> words(d);
	For(i, 0, d)
		cin >> words[i];
	For(i, 0, n)
	{
		string s; cin >> s;
		curr.clear(); curr.resize(l);
		For(j, 0, l)
		{
			if (s[0] != '(')
				curr[j].insert(s[0]);
			else
			{
				s = s.substr(1);
				while (s[0] != ')') { curr[j].insert(s[0]); s = s.substr(1); }
			}
			s = s.substr(1);
		}
		int res = 0;
		For(j, 0, d)
		{
			res++;
			For(k, 0, l)
				if (curr[k].find(words[j][k]) == curr[k].end()) { res--; break; }
		}
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}