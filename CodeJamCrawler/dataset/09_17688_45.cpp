#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxl = 20 + 10;

char s[maxl];
int l;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%s", s);
		l = strlen(s);
		if (!next_permutation(s, s + l))
		{
			sort(s, s + l);
			int x = 0;
			while (s[x] == '0') ++x;
			swap(s[0], s[x]);
			for (int i = l; i > 1; --i) s[i] = s[i - 1];
			s[1] = '0';
			s[++l] = 0;
			sort(s + 1, s + l);
		}
		printf("Case #%d: %s\n", tst, s);
	}

	return 0;
}
