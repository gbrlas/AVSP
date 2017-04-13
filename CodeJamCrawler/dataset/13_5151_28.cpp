#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

const int MaxN = 105;

long long n, p;
char s[MaxN];
long long m;

void DFS(long long n, long long p)
{
    if (! n)
        return;
	if (p <= (1ll << n))
	{
		s[m++] = 'W';
		DFS(n-1, p);
	}
	else
	{
		s[m++] = 'L';
		DFS(n-1, p-(1ll << n));
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("B-small-attempt1.out.txt", "w", stdout);
	#endif
    int TestCase;
    cin >> TestCase;
	for (int Test = 1; Test <= TestCase; ++Test)
	{
		cout << "Case #" << Test << ": ";
        m = 0;
        cin >> n >> p;
		DFS(n, p);
        long long l = 0, r = (1ll << n)-1;
		for (long long mid, j, k, t, Total; l < r; Total > p ? r = mid-1 : l = mid)
			for (mid = l+r+1 >> 1, j = 1, k = -1, t = 1ll << n-1, Total = 1; k+j < mid; k += j, j <<= 1, Total += t, t >>= 1);
        cout << l << " ";
        l = 0, r = (1ll << n)-1;
		for (long long mid, j, k, t, Total; l < r; Total > p ? r = mid-1 : l = mid)
			for (mid = l+r+1 >> 1, j = 1, k = 1ll << n, t = 1ll << n-1, Total = 1ll << n; k-j > mid; k -= j, j <<= 1, Total -= t, t >>= 1);
        cout << l << endl;
	}
	return 0;
}
