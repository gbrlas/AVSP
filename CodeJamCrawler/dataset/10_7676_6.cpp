#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

//map<int, map<int, int> > a;
int a[110][110], b[110][110], (*p)[110], (*np)[110], r;

int end() {
    for(int i = 0; i < 110; ++i) {
        for(int j = 0; j < 110; ++j) {
            if(p[i][j]) return 0;
        }
    }
    return 1;
}

int solve() {
    int ret = 0;
    while(!end()) {
        ++ret;
        for(int i = 0; i < 110; ++i) {
            for(int j = 0; j < 110; ++j) {
                if(p[i - 1][j] == 1 && p[i][j - 1] == 1) np[i][j] = 1;
                else if(p[i - 1][j] == 1 || p[i][j - 1] == 1) np[i][j] = p[i][j];
                else np[i][j] = 0;
            }
        }
        int (*tp)[110] = p;
        p = np;
        np = tp;
    }
    return ret;
}

void input() {
    scanf("%d", &r);
    memset(a, 0, sizeof(a));
    while(r--) {
        int x[2], y[2];
        scanf("%d %d %d %d", x, y, x + 1, y + 1);
        for(int i = x[0]; i <= x[1]; ++i) {
            for(int j = y[0]; j <= y[1]; ++j) {
                a[i][j] = 1;
            }
        }
    }
    p = a;
    np = b;
}

int main() {
    int cas;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    scanf("%d", &cas);
    for(int t = 0; t < cas; ++t) {
        input();
        printf("Case #%d: %d\n", t + 1, solve());
    }
    return 0;
}
