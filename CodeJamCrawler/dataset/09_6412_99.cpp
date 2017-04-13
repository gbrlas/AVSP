#include "global.h"

const string s("welcome to code jam");

int d[501][20];
string curr;

int Rec(int p, int let)
{
	if (let >= 19) return 1;
	if (p >= SZ(curr)) return 0;
	if (d[p][let] == -1)
	{
		d[p][let] = Rec(p+1, let);
		if (curr[p] == s[let])
			d[p][let] += Rec(p+1, let+1);
		d[p][let] %= 10000;
	}
	return d[p][let];

}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tt;
	cin >> tt; getline(cin, curr);
	For(ttt, 0, tt) {
		getline(cin, curr);
		Fill(d, -1); int res = Rec(0, 0);
		printf("Case #%d: %d%d%d%d\n", ttt+1, res/1000, (res/100)%10, (res/10)%10, res%10);
	}
	return 0;
}