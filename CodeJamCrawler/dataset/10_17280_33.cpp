#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define Nul 0.0000000001

int main(){
    FILE *f = fopen("A-large.in", "r");
    FILE *g = fopen("A-large.out", "w");
    int t;
    fscanf(f, "%d", &t);
    for (int i = 1; i <= t; i++){
        int n, k;
        fscanf(f, "%d%d", &n, &k);
        if ((k + 1) % (1 << n) == 0) fprintf(g, "Case #%d: ON\n", i);
        else fprintf(g, "Case #%d: OFF\n", i);
    }

    fclose(f); fclose(g);
    return 0;
}
