// 
// File:   26.07.08_2.cc
// Author: cain
//
// Created on 26 Июль 2008 г., 20:01
//
#if 1
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <memory.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
int state[1111];
int cnt;
int g[1111][1111];
vector <int> pr[1111];
int a, b, p;
void dfs(int q, int cnt)
{
    state[q] = cnt;
    for (int i = a; i <= b ; ++i)
        if (g[q][i] >= p && state[i] == 0)
            dfs(i,cnt);
}
//
// 
//
int main(int argc, char** argv) 
{
    freopen("input.2", "r", stdin);
    freopen("output.2", "w", stdout);
    int n;
    cin >> n;
    for (int i(1); i < 1001; ++i)
    {
        int q(i);
        for (int j(2); j * j <= q; ++j)
        {
            if (!(q % j)) pr[i].pb(j);
            while (!(q % j)) q /=j;
        }
        if (q > 1) pr[i].pb(q);
    }
    for (int i(2); i < 1001; ++i)
        for (int j(2); j < 1001; ++j)
        {
            int e, r;
            e = pr[i].size() - 1;
            r = pr[j].size() - 1;
            while (e >= 0 && r >= 0 && pr[i][e] != pr[j][r]) 
                if (pr[i][e] > pr[j][r]) e--;
                else r--;
            if (pr[i][e] == pr[j][r]) g[i][j] = g[j][i] = pr[i][e];
        }
    for (int l(1); l <=n ; ++l)
    {
        memset(state, 0, sizeof(state));
        cin >> a >> b >> p;
        int cnt = 0;
        for (int  i = a; i < b + 1; ++i)
            if (state[i] == 0) dfs(i,++cnt);
        cout << "Case #" << l << ": " << cnt << endl;
    }
    return (EXIT_SUCCESS);
}

#endif
