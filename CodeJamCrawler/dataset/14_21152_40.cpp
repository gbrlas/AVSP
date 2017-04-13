#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1024;
int T,n,a[N],b[N],greaterBefore[N],greaterAfter[N];
int res[N][N], gres[N][N], gt;
int f(int x, int y) {
    int z = x+y;
    if (z == n) return 0;
    if (gres[x][y] == gt) return res[x][y];
    gres[x][y] = gt;
    return res[x][y] = min(greaterBefore[z]+f(x+1,y), greaterAfter[z]+f(x,y+1));
}
int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        gt = t;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b,b+n);
        for (int i=0; i<n; i++) {
            greaterBefore[i] = 0;
            int j=0;
            while (a[j] != b[i]) {
                if (a[j] > b[i]) greaterBefore[i]++;
                j++;
            }
            greaterAfter[i] = n-1-i-greaterBefore[i];
        }
        printf("Case #%d: %d\n", t, f(0,0));
    }
    return 0;
}
