#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#define ll long long

using namespace std;

int n, cap;
int x[11000];

int main() {
    int Cases;
    scanf("%d", &Cases);

    for(int Case=1; Case<=Cases; ++Case) {
        scanf("%d %d", &n, &cap);

        for(int i=0; i<n; ++i) {
            scanf("%d", &x[i]);
        }

        sort(x, x+n);

        int nd=0;
        bool p[10010] = {0};

        for(int i=n-1; i>=0; --i) {
            if(p[i]) continue;

            int next=-1;
            for(int j=0; j<i; ++j) {
                if(x[i] + x[j] > cap) break;
                if(p[j]) continue;
                next=j;
            }

            if(next!=-1) {
                p[next] = 1;
            }

            ++nd;
        }

        printf("Case #%d: %d\n", Case, nd);
    }

    return 0;
}
