#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define mp make_pair
#define pb push_back
#define NAME ""

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 1e5 + 3;
const ld pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int ans1, ans2, t, n;
ld a[nmax], b[nmax];
bool used[nmax];

void gen(int i, int ans)
{
	if (i == n)
	{
//		cerr << i << " " << ans << endl;
		ans2 = max(ans, ans2);
	}
	else
	{
		for (int j = 0; j < n; j++)
			if (!used[j])
			{
//				cerr << j << endl;
				used[j] = true;
				if (a[i] > b[j])
					gen(i + 1, ans + 1);
				else
					gen(i + 1, ans);
				used[j] = false;
//				cerr << -j << endl;
			}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(b, b + n);
		ans2 = 0, ans1 = 0;
		gen(0, 0);
		int i2 = 0;
		for (int i = 0; i < n; i++)
		{
			while (i2 < n && a[i] > b[i2])
				i2++, ans1++;
			if (i2 < n)
				i2++;
		}
		cout << "Case #" << q + 1 << ": " << ans2 << " " << ans1 << endl;
	}
}