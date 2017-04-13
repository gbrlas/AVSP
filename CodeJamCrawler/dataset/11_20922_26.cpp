#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;
#define rep(i,a,b) for(int i=a,_b=b;i<_b;++i)
#define sz size()
#define pb(x) push_back(x)
typedef long long LL;
const int N = 1005;

const double eps = 1e-5;
int hn, wn, d;
char ma[N][N];

bool ok(int len) {

    double x = 0, y = 0, xm = 0, ym = 0, m = 0;
    rep(i, 0, hn) rep(j, 0, wn)
    if (i + len <= hn && j + len <= wn) {
        x = 0, y = 0, xm = 0, ym = 0, m = 0;

        rep(u, i, i + len) rep(v, j, j + len) {
            if (u == i && (v == j || v == j + len - 1)) continue;
            if (u == i + len - 1 && (v == j || v == j + len - 1)) continue;

            x += u;
            y += v;
            xm += u * ma[u][v];
            ym += v * ma[u][v];
            m += ma[u][v];
        }
        
        x /= (len * len - 4);
        y /= (len * len - 4);
        xm /= m;
        ym /= m;
      //  cout << xm << " " << ym << " " << x << " " << y << endl;
        if (fabs(x - xm) < eps && fabs(y - ym) < eps) return true;
    }
    return false;
}

int main() {
      freopen("in.txt","r",stdin);
      freopen("outB.txt","w",stdout);
    int cas;
    scanf("%d", &cas);
    int tcas = 0;
    while (cas--) {
        scanf("%d%d%d", &hn, &wn, &d);
        rep(i, 0, hn)scanf("%s", ma[i]);
        rep(i, 0, hn) rep(j, 0, wn) ma[i][j] -= ('0'- d);
        int l = 3, r = min(hn, wn);

        int ans = 0;
        for(int i=min(wn,hn);i>=3;--i)
            if(ok(i)) {ans = i;break;}
        printf("Case #%d: ", ++tcas);
        if (ans) printf("%d\n", ans);
        else printf("IMPOSSIBLE\n");
    }
}