#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

struct node
{
    int cur, x, y;
};

int u[200][200][200], d[200][200][200];
int ans, n, T;
vector<pair<int, int> > a;
vector<node> q;

node makenode(int cur, int x, int y)
{
    node ans;
    ans.cur = cur, ans.x = x, ans.y = y;
    return ans;
}

int check(int who, int pos, int op, pair<int, int> next)
{
    if (op == 1) return pos > 1;
    if (op == 2) return pos < 100;
    if (op == 3) return 1;
    return make_pair(who, pos) == next;
}

void make(node &t, int x, int y)
{
    switch (x)
    {
        case 1 :
            t.x --; break;
        case 2 : 
            t.x ++; break;
    }
    switch(y)
    {
        case 1 : 
            t.y --; break;
        case 2 :
            t.y ++; break;
    }
    if (x > 3 || y > 3)
        t.cur ++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    cin >> T;
    for (int TT = 1; TT <= T; TT ++)
    {
        a.clear();
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            char v; int x;
            cin >> v >> x;
            a.push_back(make_pair((v == 'O' ? 1 : 2), x));
        }
        //BFS
        memset(u, 0, sizeof(u));
        u[0][1][1] = 1;
        d[0][1][1] = 0;
        q.clear();
        q.push_back(makenode(0, 1, 1));
        int ans = 1 << 30;
        for (int f = 0; f < q.size(); f ++)
        {
            node v = q[f];
            if (v.cur == n)
                ans = min(ans, d[v.cur][v.x][v.y]);
            for (int x = 1; x <= 4; x ++)
                for (int y = 1; y <= 4; y ++)
                {
                    if (! check(1, v.x, x, a[v.cur])) continue;
                    if (! check(2, v.y, y, a[v.cur])) continue;
                    node t = v;
                    make(t, x, y);
                    if (! u[t.cur][t.x][t.y])
                    {
                        u[t.cur][t.x][t.y] = 1;
                        d[t.cur][t.x][t.y] = d[v.cur][v.x][v.y] + 1;
                        q.push_back(t);
                    }
                }
        }
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}
