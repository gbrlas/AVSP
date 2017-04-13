#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 110;

int n, m;
int a[MaxN][MaxN], l[MaxN][MaxN], r[MaxN][MaxN], u[MaxN][MaxN], d[MaxN][MaxN];

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen(InputFileName, "r", stdin);
	//freopen(OutputFileName, "w", stdout);
	#endif
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        memset(d, 0, sizeof(d));
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                l[i][j] = max(a[i][j], l[i][j-1]);
                u[i][j] = max(a[i][j], u[i-1][j]);
            }
        for (int i = n; i; --i)
            for (int j = m; j; --j)
            {
                r[i][j] = max(a[i][j], r[i][j+1]);
                d[i][j] = max(a[i][j], d[i+1][j]);
            }
        bool Ans = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                Ans &= (a[i][j] >= l[i][j-1] && a[i][j] >= r[i][j+1] || a[i][j] >= u[i-1][j] && a[i][j] >= d[i+1][j]);
        cout << "Case #" << Test << ": " << (Ans ? "YES" : "NO") << endl;
    }
	return 0;
}
