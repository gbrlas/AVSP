#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<double> ken, naomi;

int score(vector<double> & a, vector<double> & b) {
    int res = 0;
    int ptr = N - 1;

    for (int i = N - 1; i >= 0; i--) {
        while (ptr >= 0 && b[ptr] > a[i]) {
            ptr--;
        }
        if (ptr < 0) {
            break;
        }
        res++;
        ptr--;
    }

    return res;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        ken.clear();
        naomi.clear();
        scanf("%d", &N);

        double x;
        for (int i = 0; i < N; i++) {
            scanf("%lf", &x);
            naomi.push_back(x);
        }
        for (int i = 0; i < N; i++) {
            scanf("%lf", &x);
            ken.push_back(x);
        }

        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());

        printf("Case #%d: %d %d\n", t, score(naomi, ken), N - score(ken, naomi));
    }

    return 0;
}
