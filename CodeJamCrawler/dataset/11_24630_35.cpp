#include <cstdio>

const double eps = 1e-9;
const double MAXV = 1e10;
const int MAXN = 210;

int l[MAXN], p[MAXN], c[MAXN];

int main() {
    int testnum, n, D;
    double min, max, mid, left;
    bool suc;

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        scanf("%d%d", &n, &D);
        min = max = MAXV;
        for (int i = 0;i < n;i++) {
            scanf("%d%d", &p[i], &c[i]);
            l[i] = D * (c[i] - 1);
            if (l[i] < min) min = l[i];
        }
        min *= 0.5;
        while (min + eps < max) {
            left = -MAXV - MAXV;
            mid = (min + max) * 0.5;
            suc = true;
            for (int i = 0;i < n;i++) {
                if (left + mid + eps < p[i])
                    left = p[i] - mid;
                if (left > p[i] + mid + eps || left + l[i] > p[i] + mid + eps) {
                    suc = false;
                    break;
                }
                left += l[i] + D;
            }
            if (suc)
                max = mid;
            else
                min = mid;
        }
        printf("Case #%d: %.10lf\n", test, min);
    }
    return 0;
}
