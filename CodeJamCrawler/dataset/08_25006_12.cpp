#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

struct EE {int u, v;} e[20], e2[20];
int m, n;
int mp[10][10];
int a[20], t[20];

int cnt_dig(int mk) {
    int s = 0;
        while (mk) {
            if (mk&1) ++s;
            mk >>= 1;
        }
        return s;
}

int check(int *plist) {
    int i;
    for (i = 0 ; i < m ; i++) a[i] = i;
    do {
        for (i = 0 ; i < m ; i++)
            t[a[i]] = plist[i];
        //for (i = 0 ; i < m ; i++)
         //   printf("t[%d]:%d ",i,t[i]);
        //printf("\n");
        for (i = 0 ; i < m - 1 ; i++)
            if (mp[t[e2[i].u]][t[e2[i].v]] == 0) {
                //printf("mp[%d][%d]\n",t[e2[i].u],t[e2[i].v]);
                break;
            }
        if (i == m - 1) return 1;
    } while (next_permutation(a,a+m));
    return 0;
}

int main() {
    freopen("D-small.in","r",stdin);
    freopen("D-small.out","w",stdout);
    int T, ca = 0, flg;
    int i, mk, pl, plist[20];
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        memset(mp, 0, sizeof(mp));
        for (i = 0 ; i < n - 1 ; i++) {
            scanf("%d%d",&e[i].u,&e[i].v);
            --e[i].u; --e[i].v;
            mp[e[i].u][e[i].v] = mp[e[i].v][e[i].u] = 1;
        }
        scanf("%d",&m);
        for (i = 0 ; i < m - 1 ; i++) {
            scanf("%d%d",&e2[i].u,&e2[i].v);
            --e2[i].u; --e2[i].v;
        }
        flg = 0;
        for (mk = 0 ; mk < (1<<n) ; mk++) {
            if (cnt_dig(mk) != m) continue;
            pl = 0;
            for (i = 0 ; i < n ; i++) {
                if (mk&(1<<i)) plist[pl++] = i;
            }
            if (check(plist)) {flg = 1; break;}
        }
        printf("Case #%d: ",++ca);
        if(flg) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
