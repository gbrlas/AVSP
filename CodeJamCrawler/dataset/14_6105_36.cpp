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

const int MaxN = 60;
const int ox[] = {0, 1, 0, -1, -1, -1, 1, 1}, oy[] = {1, 0, -1, 0, -1, 1, -1, 1};

int n, m, K;
char a[MaxN][MaxN];
int c[MaxN][MaxN];
int View[MaxN][MaxN];

void DFS(const int i, const int j)
{
    View[i][j] = 1;
    for (int k = 0, ti, tj; k < 8; ++k)
    {
        ti = i+ox[k];
        tj = j+oy[k];
        if (ti >= 0 && ti < n && tj >= 0 && tj < m && a[ti][tj] == '.')
            if (c[ti][tj])
                View[ti][tj] = 1;
            else if (! View[ti][tj])
                DFS(ti, tj);
    }
}

int main()
{
    freopen("C-small-attempt8.in.txt", "r", stdin);
    freopen("C-small-attempt8.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ":" << endl;
        cin >> n >> m >> K;
        int Ans = 0;
        if (K == n*m-1)
        {
            for (int i = 0; i < n; a[i++][m] = 0)
                for (int j = 0; j < m; ++j)
                    a[i][j] = '*';
            a[0][0] = 'c';
            Ans = 1;
        }
        for (int opt = 0; opt < 1 << n*m && ! Ans; ++opt)
        {
            int cnt = 0;
            for (int s = opt; s; s -= s & -s, ++cnt);
            if (cnt != K)
                continue;
            for (int i = 0; i < n; a[i++][m] = 0)
                for (int j = 0; j < m; ++j)
                    a[i][j] = ((opt >> i*m+j) & 1) ? '*' : '.';
            int ci = -1, cj;
            for (int i = 0, j, k, ti, tj; i < n; ++i)
                for (j = 0; j < m; ++j)
                {
                    View[i][j] = 0;
                    c[i][j] = 0;
                    for (k = 0; k < 8; ++k)
                    {
                        ti = i+ox[k];
                        tj = j+oy[k];
                        if (ti >= 0 && ti < n && tj >= 0 && tj < m && a[ti][tj] == '*')
                            ++c[i][j];
                    }
                    if (a[i][j] == '.' && ! c[i][j])
                        ci = i, cj = j;
                }
            if (ci == -1)
                continue;
            a[ci][cj] = 'c';
            DFS(ci, cj);
            bool succ = 1;
            for (int i = 0; i < n && succ; ++i)
                for (int j = 0; j < m && succ; ++j)
                    if (a[i][j] == '.' && ! View[i][j])
                        succ = 0;
            if (succ)
                Ans = 1;
        }
        if (Ans)
            for (int i = 0; i < n; ++i)
                cout << a[i] << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
