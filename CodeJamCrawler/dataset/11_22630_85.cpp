#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cc[26][26];
int dd[26][26];
int combined[26];
char a[1000];
char b[1000];

int c, d, n;


int main()
{
	int t, cases = 0;
	scanf("%d", &t);
	while (t--)
	{
		fill(cc[0], cc[26], -1);
		fill(dd[0], dd[26], -1);
		fill(combined, combined + 26, 0);
		scanf("%d", &c);
		for (int i = 0; i < c; ++i)
		{
			char s[10];
			scanf("%s", s);
			int x = s[0] - 'A', y = s[1] - 'A', z = s[2] - 'A';
			cc[x][y] = cc[y][x] = z;
			combined[z] = 1;
		}
		scanf("%d", &d);
		for (int i = 0; i < d; ++i)
		{
			char s[10];
			scanf("%s", s);
			int x = s[0] - 'A', y = s[1] - 'A';
			dd[x][y] = dd[y][x] = 1;
		}
		scanf("%d%s", &n, a);
		for (int i = 0; i < n; ++i)
			a[i] -= 'A';

		int ln = 0;
		{
			for (int i = 0; i < n; ++i)
			{
				b[ln++] = a[i];

				if (ln > 1)
				{
					if (cc[b[ln - 1]][b[ln - 2]] != -1)
					{
						b[ln - 2] = cc[b[ln - 1]][b[ln - 2]];
						--ln;
					}
					else
					{
						for (int j = ln - 2; j >= 0; --j)
						{
							if (dd[b[ln - 1]][b[j]] != -1)
							{
								ln = 0;
								break;
							}
						}
					}
				}
			}
		}

		printf("Case #%d: [", ++cases);
		for (int i = 0; i < ln; ++i)
		{
			if (i != 0) printf(", ");
			printf("%c", b[i] + 'A');
		}
		printf("]\n");
	}
}