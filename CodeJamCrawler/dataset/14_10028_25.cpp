#include <stdio.h>
#include <algorithm>
using namespace std;

int T;
double C, F, X;

int main() {
    scanf("%d", &T);
    for (int _42=1; _42<=T; _42++) {
        scanf("%lf %lf %lf", &C, &F, &X);
        printf("Case #%d: ", _42);

        double buy_t=0;
        double prod_t = X;

        for (int i=0; i<=X; i++) {
            double cookie_prod=i*F+2;
            double tmp_t = buy_t+X/cookie_prod;
            prod_t = min(prod_t, tmp_t);

            buy_t+=(C/(i*F+2));
        }

        printf("%.7lf\n", prod_t);
    }

    return 0;
}
