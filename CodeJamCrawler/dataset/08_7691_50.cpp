#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define pb push_back
#define PIII pair<PII, int> 

int main() 
{
    freopen("b.in", "rt", stdin);
    freopen("b.out", "wt", stdout);

    int n, T, a, b, c, d, na, nb;
    cin >> n;

    for(int t = 1; t <= n; t++)
    {
        cin >> T >> na >> nb;
        vector<PIII> v;
        priority_queue<PII> av[2];
        
        for(int i = 0; i < na; i++)
        {
            scanf("%d:%d %d:%d", &a, &b, &c, &d);
            v.pb(make_pair(make_pair(a * 60 + b, c * 60 + d), 0));
        }
        for(int i = 0; i < nb; i++)
        {
             scanf("%d:%d %d:%d", &a, &b, &c, &d);
             v.pb(make_pair(make_pair(a * 60 + b, c * 60 + d), 1));
        }
        sort(v.begin(), v.end());
        int res[2] = {0, 0};
        for(int i = 0; i < na + nb; i++) 
        {
            int city = v[i].second;
            if(!av[city].empty() && v[i].first.first >= -av[city].top().first) 
            {
                av[city].pop();
            }
            else 
            {
                res[city]++;
            }
            int d = v[i].first.second + T;
            int e = v[i].first.second - v[i].first.first;
            if(d + e < 24 * 60)
            {
                av[!city].push(make_pair(-d, -(d + e)));
            }
        }
        printf("Case #%d: %d %d\n", t, res[0], res[1]); 
    }
    return 0;
}