#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int MAXN = 100005;

int main ()
{
	//freopen ("D-small-attempt0.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	int Test, N, num;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		scanf ("%d", &N);
		int cnt = 0;
		for (int i = 1; i <= N; i ++)
		{
			scanf ("%d", &num);
			if (num != i)
				cnt ++;
		}
		printf ("Case #%d: %.6f\n", Cas, cnt * 1.0);
	}
	return 0;
}