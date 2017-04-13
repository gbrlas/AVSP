#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define pub(x) push_back(x)
#define x first
#define y second
#define MP make_pair
typedef long long ll;


int main()
{
	freopen("d0.in", "r", stdin);
	freopen("d0.txt", "w",stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas)
	{
		printf("Case #%d: ", cas);
		int n; scanf("%d", &n);
		double ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int x; scanf("%d", &x);
			if (x != i) ans += 1;
		}
		printf("%.6lf\n", ans);
	}
}

