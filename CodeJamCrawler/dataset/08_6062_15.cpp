// 
// File:   02.08.08_A.cc
// Author: cain
//
// Created on 2 Август 2008 г., 20:04
//
#if 1
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppp;
typedef pair<pll, pll> plp;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
const ll INF = 9999999;
//
// 
//
vector<plp> numbers;
vector<bool> state;
int n, m, v;
pll dfs(int n)
{
    if (state[n]) return numbers[n].Y;
    state[n] = 1;
    pll tmp1 = dfs((n << 1));
    pll tmp2 = dfs((n << 1) + 1);
    if (!numbers[n].X.Y)
    {
        if (numbers[n].X.X)
        {
            numbers[n].Y.Y = tmp1.Y + tmp2.Y;
            numbers[n].Y.X = min(tmp1.Y + tmp2.X, min(tmp1.X + tmp2.X, tmp1.X + tmp2.Y));
        }
        else
        {
            numbers[n].Y.X = tmp1.X + tmp2.X;
            numbers[n].Y.Y = min(tmp1.Y + tmp2.X, min(tmp1.Y + tmp2.Y, tmp1.X + tmp2.Y));
        }
    }
    else
    {
        if (numbers[n].X.X)
        {
            numbers[n].Y.Y = min(tmp1.Y + tmp2.Y, min(tmp1.Y + tmp2.X, min(tmp1.Y + tmp2.Y, tmp1.X + tmp2.Y)) + 1);
            numbers[n].Y.X = min(min(tmp1.Y + tmp2.X, min(tmp1.X + tmp2.X, tmp1.X + tmp2.Y)), tmp1.X + tmp2.X + 1);
        }
        else
        {
            numbers[n].Y.Y = min(tmp1.Y + tmp2.Y + 1, min(tmp1.Y + tmp2.X, min(tmp1.Y + tmp2.Y, tmp1.X + tmp2.Y)));
            numbers[n].Y.X = min(min(tmp1.Y + tmp2.X, min(tmp1.X + tmp2.X, tmp1.X + tmp2.Y)) + 1, tmp1.X + tmp2.X);
        }
    }
    return numbers[n].Y;
}
int main(int argc, char** argv) 
{
    freopen("INPUT", "r", stdin);
    freopen("OUTPUT", "w", stdout);
    cin >> n;
    int temp;
    for (int l = 1; l <=n; ++l)
    {
        cin >> m >> v;
        numbers.clear();
        numbers.resize(m + 1);
        state.clear();
        state.resize(m + 1);
        int i = 0;
        for (int i = 1; i <= (m - 1) / 2; ++i)
            cin >> numbers[i].X.X >> numbers[i].X.Y;            
        for (int i = (m + 1) / 2; i <=m; ++i)
        {
            numbers[i].X.X = numbers[i].X.Y = 0 ;
            cin >> temp;
            if (temp) 
            {
                numbers[i].Y.Y = 0;
                numbers[i].Y.X = INF;
                state[i] = 1;
            }
            else 
            {
                numbers[i].Y.X = 0;
                numbers[i].Y.Y = INF;
                state[i] = 1;
            }
        }
        pll q = dfs(1);
        int res;
        if (v) res = q.Y;
        else res = q.X;
        cout << "Case #" << l << ": ";
        if (res >= INF) cout << "IMPOSSIBLE";
        else cout << res;
        cout << endl;
    }
    
    return (EXIT_SUCCESS);
}

#endif