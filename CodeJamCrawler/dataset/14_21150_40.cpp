#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1024;
int T,n,a[N],b[N];
map<int, int> m;
int tree[N];
void inc(int a) {
    while (a) {
        tree[a]++;
        a -= a&(-a);
    }
}
int get(int a) {
    int res = 0;
    while (a<N) {
        res += tree[a];
        a += a&(-a);
    }
    return res;
}
int pos(int a, int p) {
    if (a < p) return a+1;
    return n-a+p;
}
int f(int p) {
    for (int i=0; i<N; i++) tree[i] = 0;
    int res = 0;
    for (int i=0; i<n; i++) {
        int x = pos(m[a[i]], p);
        printf("adding %d: %d ops\n", a[i], get(x));
        res += get(x);
        inc(x);
    }
    printf("f(%d) = %d\n", p, res);
    return res;
}
int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b,b+n);
        for (int i=0; i<n; i++) m[b[i]] = i;
        int res = 1e9;
        for (int m=0; m<n; m++) res = min(res, f(m));
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
