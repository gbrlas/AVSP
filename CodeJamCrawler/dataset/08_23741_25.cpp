#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
long T, k, p[10];
char ch[1024], ch2[1024];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for (long z = 0; z < T; z ++)
	{
		long le, te, mn=10000;
		scanf("%d\n", &k);
		scanf("%s", ch);
		le = (long)strlen(ch);
		te = le/k;

		for (long a = 0; a < k; a ++) p[a]=a;

		while(1)
		{
			for (long a = 0; a < te; a ++)
				for (long b = 0; b < k; b ++)
					ch2[a*k+b]=ch[a*k+p[b]];
			long kk = 0;
			for (long a = 0; a < le; a ++)
				if (ch2[a] != ch2[a+1]) kk++;
			mn = min(mn, kk);
			if (!next_permutation(&p[0], &p[k])) break;
		}
		printf("Case #%d: %d\n", z+1, mn);
	}

	return 0;
}