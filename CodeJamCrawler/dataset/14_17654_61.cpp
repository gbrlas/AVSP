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

int a[123456];

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        printf("Case #%d: ", cas);
        int n, x; scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; ++i) 
            scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        int ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            int y = x - a[r--];
            if (y >= a[l]) ++l;
            ++ans;
        }
        printf("%d", ans);
        puts("");
    }

    return 0;
}
