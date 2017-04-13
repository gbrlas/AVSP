#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("A.in","r",stdin);
    freopen("output.txt","w",stdout);
}


const int MAX = 100;
int a[MAX][MAX];
char str[MAX];

int main()
{
    initialize();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", str);
			for (int j = 0; j < n; ++j)
				a[i][j] = str[j] - '0';
		}

		int res = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			int r = i;
			for (; r < n; ++r)
			{
				bool ok = true;
				for (int j = i + 1; j < n && ok; ++j)
				{
					if (a[r][j] == 1) 
						ok = false;
				}
				if (ok) break;
			}
			res += r - i;
			for (int j = r; j > i; --j)
			{
				for (int k = 0; k < n; ++k)
					swap(a[j][k], a[j - 1][k]);
			}
		}
		printf("Case #%d: %d\n", t, res);
	}

    return 0;
}