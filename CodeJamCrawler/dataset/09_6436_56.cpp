#include "global.h"

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	For(ttt, 0, tt)
	{
		string s; cin >> s;
		ForD(i, SZ(s), 1)
			if (s[i] > s[i-1]) {
				int nm = i;
				For(j, i, SZ(s))
					if (s[j]<s[nm] && s[j]>s[i-1]) nm=j;
				swap(s[i-1], s[nm]);
				sort(s.begin()+i, s.end());
				goto res;
			}
		int r = 0;
		while (s.find('0') != string::npos)	{
			s.erase(s.find('0'), 1); ++r;
		}
		sort(s.begin(), s.end());
		For(rr, 0, r+1)
			s.insert(s.begin()+1, '0');
res:
		printf("Case #%d: %s\n", ttt+1, s.c_str());
	}
	return 0;
}