#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

int n, a[1111], o[1111], b[1111];
int ll[1111];
int rr[1111];

void read(){
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        ll[i] = rr[i] = 0;
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i]) ++ll[i];
        for (int j = n; j > i; --j)
            if (a[j] < a[i]) ++rr[i];
    }
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) 
        o[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
}

void work() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int j = o[i];
        int disL = j - 1 - ll[j];
        int disR = n - j - rr[j];
        ans += min(disL, disR);
    }
    printf("%d", ans);
}

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        printf("Case #%d: ", cas);
        read();
        work();
        puts("");
    }

    return 0;
}
