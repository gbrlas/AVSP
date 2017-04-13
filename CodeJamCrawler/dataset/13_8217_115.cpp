#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <cmath>
#include <cstdlib>
#include <memory>

#define sz(a) ((int)(a).size())
#define fori(i,b,e) for(int i = (b); i < (e); ++i)
#define pb push_back
#define mp make_pair

using namespace std;

int a[100][100], mr[100], mc[100];

bool good(int n, int m) {
    fori(i,0,n) {
        fori(j,0,m) {
            if (a[i][j] != mr[i] && a[i][j] != mc[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    int TT;
    scanf ("%d\n", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        printf("Case #%d: ", tt);
        int n, m;
        scanf ("%d%d", &n, &m);
        fori(i,0,n) mr[i]=0;
        fori(j,0,m) mc[j]=0;

        fori(i,0,n) {
            fori(j,0,m) {
                scanf ("%d", &a[i][j]);
                mr[i] = max(mr[i], a[i][j]);
                mc[j] = max(mc[j], a[i][j]);
            }
        }
        if (good(n,m)) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf ("\n");
    }
}
