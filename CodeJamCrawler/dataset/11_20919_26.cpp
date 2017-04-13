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
const int N = 1000005;
const double eps = 1e-4;

int len, v[N], a, b, w, s, r, n;
int id[N];
double t;

bool cmp(const int x, const int y) {
    return v[x] < v[y];
}

int main() {
    freopen("A.in","r",stdin);
    freopen("outA.txt","w",stdout);
    int cas;
    scanf("%d", &cas);
    int tcas = 0;
    while (cas--) {
        scanf("%d%d%d%lf", &len, &s, &r, &t);
        scanf("%d", &n);
        len--;
        memset(v, 0, sizeof (v));

        rep(i, 0, n) {
            scanf("%d%d%d", &a, &b, &w);
            rep(j, a, b) v[j] += w;
        }
    //    rep(i,0,len+1) printf("%d ",v[i]); puts("");
        rep(i, 0, len + 1) id[i] = i;
        sort(id, id + len + 1, cmp);
        double ans = 0;
        double temp;
        int i;
        rep(j, 0, len + 1) {
            i = id[j];
            if (fabs(t)<eps) {
                ans += 1.0 / (v[i]+s);
            } else if (t >= 1.0 / (v[i] + r)) {
                temp = 1.0 / (v[i] + r);
                ans += temp;
                t -= temp;
            } else {
                ans += t;
                ans += (1.0 - (v[i] + r) * t) / (v[i]+s);
                t = 0;
            }
        }
        printf("Case #%d: %.7lf\n", ++tcas, ans);
    }
}