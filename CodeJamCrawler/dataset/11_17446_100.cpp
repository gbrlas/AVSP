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

int s, x, t, a, n;

int main()
{
	freopen("c0.in", "r", stdin);
	freopen("c0.txt", "w", stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas)
	{	
		s = 0; t = 12345678; a = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			s ^= x;
			if (x < t) t = x;
			a += x;
		}
		printf("Case #%d: ", cas);
		if (s == 0) printf("%d\n", a - t);
			else puts("NO");
	}
	return 0;
}

