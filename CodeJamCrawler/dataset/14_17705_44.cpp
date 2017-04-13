#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

const int SZ = 1111;
double naomi[SZ], ken[SZ];
bool kwar[SZ], kdwar[SZ];
int n;


void clear() {
    memset(kwar, 0, sizeof(kwar)); memset(kdwar, 0, sizeof(kdwar));
}

double ken_answer(bool* war, double weight) {
    int fpl = -1;
    for (int i = 0; i < n; ++i) {
        if (!war[i] && fpl == -1) fpl = i;
        if (!war[i] && ken[i] > weight) {
            war[i] = true;
            return ken[i];
        }
    }
    if (fpl != -1) {
        war[fpl] = true;
        return ken[fpl];
    }
    return -1;
}

double ken_extr(bool* war) {
    for (int i = 0; i < n; ++i)
        if (!war[i]) return ken[i];
    return 1e100;
}

int get_war() {
    int score = 0;
    for (int i = n - 1; i >= 0; --i) {
        double n = naomi[i];
        double m = ken_answer(kwar, n);
        if (n > m) ++score;
    }
    return score;
}

int get_dwar() {
    int score = 0;
    for (int l = 0; l < n; ++l) {
        double kmin = ken_extr(kdwar);
        if (naomi[l] > kmin) {
            ken_answer(kdwar, 1.0);
            ++score;
        }
    }
    return score;
}

int main() {
    int tcn = 0; scanf("%d", &tcn);
    for (int tc = 1; tc <= tcn; ++tc) {
        clear(); scanf("%d", &n);
        for (int i = 0; i < n * 2; ++i) {
            if (i < n) scanf("%lf", naomi + i);
            else scanf("%lf", ken + i - n);
        }
        sort(naomi, naomi + n);
        sort(ken, ken + n);
        int war = get_war();
        int dwar = get_dwar();
        printf("Case #%d: %d %d\n", tc, dwar, war);
    }

    return 0;
}
