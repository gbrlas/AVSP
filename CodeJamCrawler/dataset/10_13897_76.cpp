#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int test=1; test<=T; ++test) {
        unsigned long N, K;
        scanf("%lu%lu", &N, &K);
        
        int p2n = (1 << N);
        if (K % p2n == p2n - 1) {
            printf("Case #%d: ON\n", test);
        }
        else {
            printf("Case #%d: OFF\n", test);
        }
        
    }
    return 0;
}