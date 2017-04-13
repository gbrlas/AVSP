#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

int D[101010], L[101010], F[101010];
int n, Dis;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> D[i] >> L[i];
		cin >> Dis;
		F[0] = D[1];
		D[0] = 0;
		for (int i = 1; i <= n; i ++)
		{
			F[i] = -1000000;
			for (int j = 0; j < i; j ++)
				if (F[j] >= D[i])
					F[i] = max(F[i], min(L[i], D[i] - D[j]) + D[i]);
		}
		int Flag = 0;
		for (int i = 0; i <= n; i ++)
			if (F[i] >= Dis) Flag = 1;	
		if (Flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
