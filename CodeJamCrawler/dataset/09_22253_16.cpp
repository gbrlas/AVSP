#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define r(i, n) for(int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);
	int t, n, m[50];
	scanf("%d", &t);
	r(tc, t)
	{
		scanf("%d", &n);
		r(i, n)
		{
			char line[100];
			scanf("%s", line);
			m[i] = -1;
			r(j, n)
				if (line[j] == '1')
				{
					m[i] = j;
				}
		}
		int a = 0;
		r(i, n)
		{
			if (m[i] > i)
			{
				for(int j = i + 1; j < n; ++j)
				{
					if (m[j] <= i)
					{
						int temp = m[j];
						for(int k = j; k > i; --k)
						{
							m[k] = m[k - 1];
						}
						m[i] = temp;
						a += j - i;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", tc + 1, a);
	}
}
