// 
// File:   26.07.08_1.cc
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
#define mp make_pair
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
//
// 
//
int main(int argc, char** argv) 
{
    freopen("input.1", "r", stdin);
    freopen("output.1", "w", stdout);
    vector<pii> p;
    ll n, a, b, c, d, x0, y0, m;
    ll N;
    
    cin >> N;
    for (int k = 1; k <= N; ++k)
    {
        cin >> n >>  a >>  b >>  c >> d >>  x0 >>  y0 >> m;
        p.clear();
        p.pb(mp(x0, y0));
        for (int i = 1; i < n; ++i)
        {
            x0 = (x0 * a + b) % m;
            y0 = (y0 * c + d) % m;
            p.pb(mp(x0, y0));
            
        }
        sort(p.begin(), p.end());
        int cnt = 0;
        for (int i = 0; i < p.size(); ++i)
            for (int j = i + 1; j < p.size(); ++j)
                for (int l = j + 1; l < p.size(); ++l)
                    if ((p[i].X + p[j].X + p[l].X) % 3 == 0 && 
                        (p[i].Y + p[j].Y + p[l].Y) % 3 == 0) cnt++;
        cout << "Case #" << k << ": " << cnt << endl;
    }
    
    return (EXIT_SUCCESS);
}

#endif
