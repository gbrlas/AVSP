/*
 * Zhiqiang Ma
 * http://fclose.com/zma/
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

enum {
    BOT_O = 0,
    BOT_B = 1
};

int app(const char* input_file)
{
    int ret = 0;

    FILE *fin = NULL;

    int T = 0;
    int input[100][100][2];
    int N[100];

    int step = 0;
    int free_o = 0;
    int free_b = 0;

    int i, j, k, m, n, p; // tmp var
    char c; // tmp var

    // get input
    fin = fopen(input_file, "r");

    fscanf(fin, "%d", &T);

    for (i = 0; i < T; i++) {
        fscanf(fin, "%d", &(N[i]));
    
        for (j = 0; j < N[i]; j++) {
            do {
                fscanf(fin, "%c", &c);
            } while (c == ' ');
            if (c == 'O') {
                input[i][j][0] = BOT_O;
            } else {
                input[i][j][0] = BOT_B;
            }
            fscanf(fin, "%d", &(input[i][j][1]));
        }
    }

    // change input to number of moves
    for (i = 0; i < T; i++) {
        m = 1; // O
        n = 1; // B
        for (j = 0; j < N[i]; j++) {
            if (input[i][j][0] == BOT_O) {
                p = m;
                m = input[i][j][1];
                if (m < p) {
                    input[i][j][1] = p - m;
                } else {
                    input[i][j][1] = m - p;
                }
            } else {
                p = n;
                n = input[i][j][1];
                if (n < p) {
                    input[i][j][1] = p - n;
                } else {
                    input[i][j][1] = n - p;
                }
            }
        }
    }

    // start cal step
    for (i = 0; i < T; i++) {
        step = 0;
        free_o = 0; // O
        free_b = 0; // B
        for (j = 0; j < N[i]; j++) {
            if (input[i][j][0] == BOT_O) {
                if (free_o >= input[i][j][1]) {
                    step += 1;
                    free_b += 1;
                } else {
                    m = input[i][j][1] - free_o;
                    m += 1;
                    step += m;
                    free_b += m;
                }
                free_o = 0;
            } else {
                if (free_b >= input[i][j][1]) {
                    step += 1;
                    free_o += 1;
                } else {
                    m = input[i][j][1] - free_b;
                    m += 1;
                    step += m;
                    free_o += m;
                }
                free_b = 0;
            }
        }
        // output result
        printf("Case #%d: %d\n", i+1, step);
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

