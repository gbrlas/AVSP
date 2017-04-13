#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const char *inf = "input.txt";
const char *ouf = "output.txt";

const int maxm = 6000;
const int maxn = 600;

int l, m, n;

char words[maxm][20];
char s[maxn][50000];
int ans[maxn];

bool comp(char *w, char *s)
{
	for (int i = 0; i < l; ++i)
	{
		bool ok = false;
		if (*s=='(')
		{
			while (*s!=')')
			{
				if (*s==*w)
					ok = true;
				++s;
			}
		} else
			ok = *s == *w;
		if (!ok)
			return false;
		++s;
		++w;
	}
	return true;
}

void decide(int a, int b)
{
	for (int i = a; i < b; ++i)
	{
		int ret = 0;
		for (int j = 0; j < m; ++j)
			if (comp(words[j], s[i]))
				++ret;
		ans[i] = ret;
	}
}

int main()
{
	freopen(inf, "rt", stdin);
	freopen(ouf, "wt", stdout);
	cin >> l >> m >> n;
	for (int i = 0; i < m; ++i)
		cin >> words[i];
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	decide(0, n);
	for (int i = 0; i < n; ++i)
		printf("Case #%d: %d\n", i+1, ans[i]);
	return 0;
}
