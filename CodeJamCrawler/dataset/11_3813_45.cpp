#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int MXN = 10001;
int a[MXN];
vector <int> l[MXN];
int n;
int main () {
    freopen ("B-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		for (int i = 0; i < MXN; i++)
			l[i].clear();
		sort (a, a + n);
		for (int i = 0; i < n; i++) {
			if (l[a[i] - 1].size() > 0) {
				vector <int>::iterator k = l[a[i] - 1].begin();
				for (vector <int>::iterator itr = l[a[i] - 1].begin(); itr != l[a[i] - 1].end(); itr++)
					if (*itr < *k)
						k = itr;
				int v = *k;
				l[a[i] - 1].erase (k);
				l[a[i]].push_back (v + 1);
			} else
				l[a[i]].push_back (1);
		}
		int ans = 1000000000;
		for (int i = 0; i < MXN; i ++)
			for (int j = 0; j < l[i].size(); j++)
				ans = min (ans, l[i][j]);
		if (n == 0)
			ans = 0;
        printf ("Case #%d: %d\n", ci + 1, ans);
    }
    return 0;
}
