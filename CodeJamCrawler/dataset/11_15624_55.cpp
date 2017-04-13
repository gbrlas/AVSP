/*
 * Zhiqiang Ma
 * http://fclose.com/zma/
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

inline int patrick_sum(int a, int b)
{
    int ba = 0;
    int bb = 0;
    int bc[20];
    int c = 0;

    int i, j, k;

    for (i = 0; i < 20; i++) {
        ba = (a >> i) & 0x1;
        bb = (b >> i) & 0x1;
        bc[i] = (ba + bb) & 0x1;
    }
    for (i = 19; i>=0; i--) {
        c = c << 1;
        c += bc[i];
    }
    return c;
}

int app(const char* input_file)
{
    int ret = 0;

    FILE *fin = NULL;

    int num[1000];
    int T = 0;
    int N = 0;

    int mark[1000];
    int p_sum0 = 0;
    int p_sum1 = 0;
    int s_sum0 = 0;
    int s_sum1 = 0;

    int max = 0;
    int cur = 0;

    int i, j, k;

    fin = fopen(input_file, "r");

    fscanf(fin, "%d", &T);

    for (i = 0; i < T; i++) {
        // input
        fscanf(fin, "%d", &N);
        for (j = 0; j < N; j++) {
            fscanf(fin, "%d", &(num[j]));
            mark[j] = 0;
        }
        mark[0] = 1;
        mark[N] = 0;
        max = -1;
        // search
        while (mark[N] == 0) {
            p_sum0 = 0;
            p_sum1 = 0;
            s_sum0 = 0;
            s_sum1 = 0;
            for (k = 0; k < N; k++) {
                if (mark[k] == 0) {
                    p_sum0 = patrick_sum(p_sum0, num[k]);
                    s_sum0 = s_sum0 + num[k];
                } else {
                    p_sum1 = patrick_sum(p_sum1, num[k]);
                    s_sum1 = s_sum1 + num[k];
                }
                // printf("\np_sum0: %d, p_sum1: %d, s_sum0: %d, s_sum1: %d, max: %d\n", 
                //        p_sum0, p_sum1, s_sum0, s_sum1, max);
            }
            if (p_sum0 == p_sum1 && p_sum0 != 0) {
                if (s_sum0 > s_sum1) {
                    cur = s_sum0;
                } else {
                    cur = s_sum1;
                }
                if (cur > max) {
                    max = cur;
                    // for (k = 0; k < N; k++) {
                    //    printf("%d ", mark[k]);
                    // }
                    // printf("\np_sum0: %d, p_sum1: %d, s_sum0: %d, s_sum1: %d, max: %d\n", 
                    //        p_sum0, p_sum1, s_sum0, s_sum1, max);
                }
            }
            k = 0;
            while (mark[k] == 1) {
                mark[k] = 0;
                k++;
            }
            mark[k] = 1;
        }

        // output
        printf("Case #%d: ", i+1);
        if (max == -1) {
            printf("NO\n");
        } else {
            printf("%d\n", max);
        }

    }

    fclose(fin);
    return ret;
}

int main(int argc, char* argv[])
{
    int ret = 0;

    if (argc < 1) {
        printf("No input file!\n");
        ret = -1;
    } else {
        ret = app(argv[1]);
    }

    return ret;
}

