#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

const int SZ = 1111;
double naomi[SZ], ken[SZ];
bool nwar[SZ], kwar[SZ], ndwar[SZ], kdwar[SZ];
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
    war[fpl] = true;
    return ken[fpl];
    return -1.0;
}

void ken_extr(bool* war, double& maxv, double& minv) {
    maxv = -1e100, minv = 1e100;;
    for (int i = 0; i < n; ++i)
        if (!war[i]) {
            maxv= max(maxv, ken[i]);
            minv = min(minv, ken[i]);
        }
}

int get_war(vector<int> perm) {
    int score = 0;
    for (int i = 0; i < perm.size(); ++i) {
        double n = naomi[perm[i]];
        double m = ken_answer(kwar, n);
        if (n > m) ++score;
    }
    return score;
}

int get_dwar(vector<int> perm) {
    int a = 0;
    int score = 0;
    for (int i = 0; i < perm.size(); ++i) {
        double n = naomi[perm[i]];
        double kmax, kmin;
        ken_extr(kdwar, kmax, kmin);
        if (n > kmax) {
            ken_answer(kdwar, n);
            ++score;
            continue;
        }
        if (n > kmin) {
            ken_answer(kdwar, 1.0);
            ++score;
            continue;
        }

        ken_answer(kdwar, kmax - 1e-7);
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
        vector<int> perm(n);
        int war = 0, dwar = 0;
        for (int i = 0; i < n; ++i) perm[i] = i;
        do {
            clear();
            war = max(war, get_war(perm));
            dwar = max(dwar, get_dwar(perm));
        } while (next_permutation(perm.begin(), perm.end()));
        printf("Case #%d: %d %d\n", tc, dwar, war);
    }

    return 0;
}
