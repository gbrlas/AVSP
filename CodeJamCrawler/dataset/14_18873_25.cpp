#include <cstdio>
#include <algorithm>

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; ++t) {
        long double c, f, x;
        scanf("%Lf %Lf %Lf", &c, &f, &x);
        int k = std::max(0.0L, (f*x - 2 *c)/(f*c));

        long double ans = x/(2 + k*f);

        for(int i = 0; i < k; ++i) {
            ans += c / (2 + i * f);
        }
        printf("Case #%d: %0.8Lf\n", t, ans);
    }

    return 0;
}
