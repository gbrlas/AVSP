/*
 * Zhiqiang Ma
 * http://fclose.com/zma/
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int app(const char* input_file)
{
    int ret = 0;

    FILE *fin = NULL;
    
    int T = 0;
    int C = 0;
    int D = 0;
    int N = 0;

    char combine[72][3];
    char opposed[56][2];
    char list[100];

    char result[100];
    int result_len = 0;

    int i, j, k, m;
    char c;
    int is_combined = 0;

    fin = fopen(input_file, "r");

    fscanf(fin, "%d", &T);

    for (i = 0; i < T; i++) {
        // read input
        fscanf(fin, "%d", &C);
        C = 2*C;
        for (j = 0; j < C; j+=2) {
            fscanf(fin, "%c", &c); // 1 space
            fscanf(fin, "%c%c%c", 
                    &(combine[j][0]), 
                    &(combine[j][1]),
                    &(combine[j][2]));
            k = j + 1;
            combine[k][1] = combine[j][0];
            combine[k][0] = combine[j][1];
            combine[k][2] = combine[j][2];
        }
        fscanf(fin, "%d", &D);
        D = 2*D;
        for (j = 0; j < D; j+=2) {
            fscanf(fin, "%c", &c); // 1 space
            fscanf(fin, "%c%c", 
                    &(opposed[j][0]), 
                    &(opposed[j][1]));
            k = j + 1;
            opposed[k][1] = opposed[j][0];
            opposed[k][0] = opposed[j][1];
        }
        fscanf(fin, "%d", &N);
        fscanf(fin, "%c", &c); // 1 space
        for (j = 0; j < N; j++) {
            fscanf(fin, "%c", &(list[j]));
        }
        // start work
        result_len = 0;
        for (j = 0; j < N; j++) {
            result[result_len] = list[j];
            result_len++;
            is_combined = 0;
            // combine
            for (k = 0; k < C; k++) {
                if (result_len >= 2) {
                    if (combine[k][0] == result[result_len-2] &&
                            combine[k][1] == result[result_len-1]) {
                        result_len -= 1;
                        result[result_len - 1] = combine[k][2];
                        is_combined = 1;
                        break;
                    }
                }
            }
            if (is_combined)
                continue;
            // opposed
            if (result_len >= 2) {
                for (m = 0; m < result_len - 1; m++) {
                    for (k = 0; k < D; k++) {
                        if (opposed[k][0] == result[m] &&
                                opposed[k][1] == result[result_len - 1]) {
                            // result_len = m;
                            result_len = 0;
                            break;
                        }
                    }
                }
            }
        }
        // output
        printf("Case #%d: [", i+1);
        for (j = 0; j < result_len - 1; j++) {
            printf("%c, ", result[j]);        
        }
        if (result_len > 0) {
            printf("%c", result[result_len-1]);
        }
        printf("]\n");
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

