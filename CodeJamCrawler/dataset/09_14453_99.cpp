#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define dbg(x) cout << #x << " -> " << x << "\t" << flush;
#define dbge(x) cout << #x << " -> " << x << "\t" << endl;
#define LET(x,a) typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1
typedef unsigned long long LL;

int arr[101][101];
char vis[101][101];
char vis1[101][101];
int par[101*101];
int n, m;
int X[] = {-1,  0, 0, 1};
int Y[] = {0,   -1, 1, 0};
int Parent(int a)
{
    if(par[a] == a) return a;
    return par[a] = Parent(par[a]);
}
void solve(int a, int b)
{
    int ca = -1, cb = -1, alti = INT_MAX;
    FORZ(i, 4)
    {
        int na = a + X[i];
        int nb = b + Y[i];
        if(na >= 0 && na < n && nb >= 0 && nb < m && arr[na][nb] < arr[a][b] && alti > arr[na][nb])
        {
            alti = arr[na][nb];
            ca = na, cb = nb;
        }
    }
    if(ca != -1)
    {
        int l1 = Parent(ca*m + cb);
        int m1 = Parent(a*m + b);
        par[m1] = l1;
        solve(ca, cb);
    }
}

void flood(int a, int b, char c)
{
    vis[a][b] = c;
    FORZ(i, 4)
    {
        int na = a + X[i];
        int nb = b + Y[i];
        if(na >= 0 && na < n && nb >= 0 && nb < m && !vis[na][nb] && Parent(na*m + nb) == Parent(a*m + b))
        {
            flood(na, nb, c);
        }
    }
}




int main()
{
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        n = GI, m = GI;
        FORZ(i, n)
            FORZ(j, m)
            {
                arr[i][j] = GI;
//                vec.PB(PI(arr[i][j], PII(i, j)));
                par[i*m + j] = i*m + j;
            }

        printf("Case #%d:\n", nc);
        memset(vis, 0, sizeof vis);
        int cnt = 'a';


        FORZ(i, n)
            FORZ(j, m)
            {
                solve(i, j);
            }
        cnt = 'a';
        FORZ(i, n)
            FORZ(j, m)
            if(!vis[i][j])
                flood(i, j, cnt++);

        FORZ(i, n)
        {
            printf("%c",vis[i][0]);
            FOR(j, 1, m)
                printf(" %c",vis[i][j]);
            puts("");
        }

    }
}
