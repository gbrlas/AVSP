#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <complex>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll L = (1 << 20);
ll par[L];
ll pr[L];
ll s1[L], s2[L];
int c1, c2;

int count(ll S)
{
    set<ll> s;
    for (int i = 0; i <= S; ++ i)
    {
        ll a = i;
        c1 = 0;
        while (par[a] != a)
        {
            s1[c1 ++] = a;
            a = par[a];
        }
        for (int j = 0; j < c1; ++ j) par[s1[j]] = a;
        s.insert(a);
    }
    return s.size();
}

void unite(ll a, ll b)
{
    //printf("(%lld %lld) ", a, b);
    c1 = c2 = 0;
    while (par[a] != a)
    {
        s1[c1 ++] = a;
        a = par[a];
    }
    while (par[b] != b)
    {
        s2[c2 ++] = b;
        b = par[b];
    }
    par[b] = a;
    for (int i = 0; i < c1; ++ i) par[s1[i]] = a;
    for (int i = 0; i < c2; ++ i) par[s2[i]] = a;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int __it = 0;
    scanf ("%d", &__it);
    vector <ll> prime;
    memset(pr, 1, sizeof(pr));
    pr[0] = pr[1] = 0;
    for (ll i = 0; i < L; ++ i)
        if (pr[i])
        {
            prime.push_back(i);
            for (ll j = i * i; j < L; j += i)
                pr[j] = 0;
        };
    int c = prime.size();
    for (int __xx = 1; __xx <= __it; ++ __xx)
    {
        ll A, B, P;
        scanf ("%lld %lld %lld", &A, &B, &P);
        for (ll i = 0; i <= B - A; ++ i)
            par[i] = i;
        for (int i = 0; i < c; ++ i)
            if (prime[i] >= P)
            {
                ll x = prime[i];
                for (ll j = A + (x - A % x) % x; j <= B; j += x)
                {
                    //cout << j << " ";
                    if (j - x >= A) unite(j - A, j - x - A);
                }
                //if (A + (x - A % x) % x <= B) cout << endl;
            }
        printf("Case #%d: %d\n", __xx, count(B - A));
    }
    return 0;
}

