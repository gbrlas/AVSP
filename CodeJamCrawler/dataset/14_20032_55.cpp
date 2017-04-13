#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

int T,n;
vector<double> naomi;
vector<double> ken;

int deceitful() {
    int i = 0, j = n-1, res = 0;
    for (int x = n-1; x >= 0; x--) {
        if (naomi[j] > ken[x]) res++, j--;
        else i++;
    }
    return res;
}

void remove_next(double a) {
    int i;
    for (i = 0; ken[i] < a; i++);
    ken.erase(ken.begin()+i);
}

int not_deceitful() {
    int res = 0;
    for (int i = 0; i < n; i++)
        if (naomi[i] > ken[ken.size()-1]) res++, remove_next(-1.0);
        else remove_next(naomi[i]);
    return res;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            double a; scanf("%lf", &a);
            naomi.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            double a; scanf("%lf", &a);
            ken.push_back(a);
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        int res = deceitful();
        printf("Case #%d: %d %d\n", t, res, not_deceitful());
        naomi.clear();
        ken.clear();
    }
    return 0;
}
