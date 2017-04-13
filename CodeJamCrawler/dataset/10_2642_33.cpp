#include<cstdio>
using namespace std;
int main() {
    int t, n, k;
    freopen("A-small.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++) {
        scanf("%d%d", &n, &k);
        k++;
        if (k % (1 << n))
            printf("Case #%d: OFF\n", i);
        else
            printf("Case #%d: ON\n",i);
    }
    return 0;
}
