#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

char c[55][55];
int n;

bool win(int x, int y, int k, char ch){
    bool b = true;
    if (x >= k-1){
        for (int i = x-k+1; i <= x; i++)
            if (c[i][y] != ch) b = false;
    }
    else b = false;

    if (b) return b;
    b = true;

    if (x + k <= n){
        for (int i = x; i < x+k; i++)
            if (c[i][y] != ch) b = false;
    }
    else b = false;

    if (b) return b;
    b = true;

    if (y >= k-1){
        for (int i = y-k+1; i <= y; i++)
            if (c[x][i] != ch) b = false;
    }
    else b = false;

    if (b) return b;
    b = true;

    if (y + k <= n){
        for (int i = y; i < y+k; i++)
            if (c[x][i] != ch) b = false;
    }
    else b = false;

    if (b) return b;
    b = true;

    if (x >= k-1 && y >= k-1){
        int X = x, Y = y;
        for (int i = 1; i <= k; i++){
            if (c[X][Y] != ch) b = false;
            X--; Y--;
        }
    }
    else b = false;

    if (b) return b;
    b = true;

    if (x + k <= n && y >= k-1){
        int X = x, Y = y;
        for (int i = 1; i <= k; i++){
            if (c[X][Y] != ch) b = false;
            X++; Y--;
        }
    }
    else b = false;

    return b;
}

int main(){
    FILE *f = fopen("A-small.in", "r");
    FILE *g = fopen("A-small.out", "w");
    int t;
    fscanf(f, "%d", &t);
    for (int tests = 1; tests <= t; tests++){
        int k;
        fscanf(f, "%d%d\n", &n, &k);
        for (int i = 0; i < n; i++) fscanf(f, "%s", c[i]);
        for (int i = 0; i < n; i++){
            int j = n-1;
            while (1){
                while (c[i][j] != '.') j--;
                while (c[i][j] == '.'){
                    j--; if (j < 0) break;
                }
                //printf("h i = %d, j = %d\n", i, j);
                if (j < 0) break;
                //printf("i = %d, j = %d\n", i, j);
                while (c[i][j+1] == '.'){
                    c[i][j+1] = c[i][j]; c[i][j] = '.'; j++;
                }
            }
        }

        /*for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) fprintf("%c", c[i][j]);
            printf("\n");
        } printf("\n");*/
        bool w1 = false, w2 = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (c[i][j] == 'B') if (win(i, j, k, 'B')) w1 = true;
                if (c[i][j] == 'R') if (win(i, j, k, 'R')) w2 = true;
            }

        if (w1)
            if (w2) fprintf(g, "Case #%d: Both\n", tests);
            else fprintf(g, "Case #%d: Blue\n", tests);
        else
            if (w2) fprintf(g, "Case #%d: Red\n", tests);
            else fprintf(g, "Case #%d: Neither\n", tests);

    }

    fclose(f); fclose(g);
    return 0;
}
