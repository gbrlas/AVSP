#include <cstdio>
#include <algorithm>
using namespace std;
int w(double *a, double *gb, int n) {
    double b[n];
    for (int i=0; i<n; i++) b[i] = gb[i];
    int res = 0;
    for (int i=0; i<n; i++) {
        res++;
        for (int j=0; j<n; j++) {
            if (b[j] > a[i]) {
                b[j] = -1;
                res--;
                break;
            }
        }
    }
    return res;
}
int dw(double *a, double *b, int n) {
    int res = 0, j = 0;
    for (int i=0; i<n; i++) {
        if (a[i] > b[j]) {
            res++;
            j++;
        }
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        int n;
        scanf("%d", &n);
        double a[n], b[n];
        for (int i=0; i<n; i++) scanf("%lf", &a[i]);
        for (int i=0; i<n; i++) scanf("%lf", &b[i]);
        sort(a,a+n);
        sort(b,b+n);
        printf("Case #%d: %d %d\n", t, dw(a,b,n), w(a,b,n));
    }
    return 0;
}
