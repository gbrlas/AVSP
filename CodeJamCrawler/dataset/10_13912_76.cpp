#include <stdio.h>

typedef unsigned long long ull;

unsigned long input[1000];
struct startposcost {
    ull cost;
    int offset;
};

startposcost poscost[1000];

int main()
{
    int T;
    scanf("%d",&T);
    for (int test = 1; test<=T; ++test) {
        unsigned long R, k, N;
        scanf("%lu%lu%lu",&R,&k,&N);
        for (int i=0; i<N; ++i) {
            scanf("%lu",&input[i]);
        }
        for (int i=0; i<N; ++i) {
            startposcost spc;
            spc.cost = input[i];
            spc.offset = 1;
            for (int j= (i + 1)%N; j != i; j = (j + 1)%N) {
                ull cost = spc.cost + input[j];
                if (cost > k) {
                    break;
                }
                spc.cost = cost;
                ++spc.offset;
            }
            poscost[i] = spc;
        }
        int startpos = 0;
        ull ans = 0;
        for (int i=0; i<R; ++i) {
            ans += poscost[startpos].cost;
            startpos += poscost[startpos].offset ;
            startpos %= N;
        }

        printf("Case #%d: %llu\n", test, ans);
    }
    return 0;
}