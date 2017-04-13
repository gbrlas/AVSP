#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int MAXN = 100005;

int main ()
{
	//freopen ("C-small-attempt0.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	int Test, N, a, min_val;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		scanf ("%d", &N);
		min_val = INF;
		int ans = 0, tot = 0;
		for (int i = 0; i < N; i ++)
		{
			scanf ("%d", &a);
			if (a < min_val)
				min_val = a;
			ans ^= a;
			tot += a;
		}
		if (ans == 0)
			printf  ("Case #%d: %d\n", Cas, tot - min_val);
		else
			printf  ("Case #%d: NO\n", Cas);
	}
	return 0;
}
