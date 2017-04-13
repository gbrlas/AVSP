#include <cstdio>

using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int t, T;
    double C, F, X, p, ta, tpg, tx, ty;

    scanf("%d", &T);

    for(t = 1;t <= T;t++) {
        scanf("%lf%lf%lf", &C, &F, &X);
        p = 2.0;
        ta = 0.0;

        while(true) {
            tx = X / p;
            tpg = C / p;
            ty = tpg + X / (p + F);
            if(tx <= ty) {
                ta += tx;
                break;
            }
            ta += tpg;
            p += F;
        }
        printf("Case #%d: %.7lf\n", t, ta);
    }
    return 0;
}
