#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;

int n, cap;
int x[11000];

int f(int k, int taken) {
    if(k==n) return 0;

    int ans = 1 + f(k+1, taken);

    for(int i=0; i<k; ++i) {
        if(((taken>>i)&1 != 0)) continue;
        if(x[k] + x[i] <= cap) {
            ans = min(ans, f(k+1, taken | (1<<i) | (1<<k)));
        }
    }

    return ans;
}

int main() {
    int Cases;
    scanf("%d", &Cases);

    for(int Case=1; Case<=Cases; ++Case) {
        scanf("%d %d", &n, &cap);

        for(int i=0; i<n; ++i) {
            scanf("%d", &x[i]);
        }

        printf("Case #%d: %d\n", Case, f(0,0));
    }

    return 0;
}
