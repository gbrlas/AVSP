#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC)

const int maxn = 22;

int a[maxn], b[maxn], p[maxn];
int used[maxn];
int n;

bool gen(int st)
{
	if (st == n)
	{
		for (int i = n-1; i >= 0; --i)
		{
			int mx = 1;
			for (int j = i+1; j < n; ++j)
				if (p[i] > p[j])
					mx = max(mx, 1 + b[j]);
			if (mx != b[i])
				return false;
		}
		return true;
	}
	for (int i = 0; i < n; ++i)
	{
		if (used[i])
			continue;
		if (b[i] > n-i)
			break;
		p[st] = i;
		used[i] = 1;
		int mx = 1;
		for (int j = 0; j < st; ++j)
			if (p[j] < i)
				mx = max(mx, 1 + a[j]);
		if (mx == a[st] && gen(st+1))
			return true;
		used[i] = 0;
	}
	return false;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	
	memset(used, 0, sizeof used);
	assert(gen(0));
	for (int i = 0; i < n; ++i)
		cout << p[i]+1 << ' ';
	cout << endl;
}

int main()
{
	cin.sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
	}

	timestamp(end);
	return 0;
}
