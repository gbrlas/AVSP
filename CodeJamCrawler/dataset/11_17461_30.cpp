#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll gcd(ll x, ll y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

void solve()
{
    ll N, Pd, Pg, D, W;// G, M;
    cin >> N >> Pd >> Pg;
    if (Pd == 0)
    {
        D = 1; W = 0;
    }  else
    {
        D = 100 / gcd(Pd, 100);
        W = Pd * D / 100;
    }
    if (D > N) {printf("Broken\n"); return;}
    if (D - W > 0 && Pg == 100){puts("Broken"); return;}
    if (W > 0 && Pg == 0){puts("Broken"); return;}
    puts("Possible");
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out","w", stdout);
    int task; cin >> task;
    for (int cas = 1; cas <= task; ++cas)
    {
        printf("Case #%d: ", cas);
        solve();
    }
    return 0;
}
