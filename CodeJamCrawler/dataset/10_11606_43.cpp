#include <stdio.h>
#include <math.h>

int main() {
    FILE *myin = fopen("in.in", "r");
    FILE *myout = fopen("out.out", "w");

    unsigned int t=0, k=0, n=0, i=0;

    fscanf(myin, "%u", &t);

    while (i < t) {
        fscanf(myin, "%u", &n);
        fscanf(myin, "%u", &k);
        // k in number, n is mask
        k = k & ((1<<n)-1);
        if(k == ((1<<n)-1))
            fprintf(myout, "Case #%u: ON\n", i+1);
        else
            fprintf(myout, "Case #%u: OFF\n", i+1);
        i++;
    }

    fclose(myin);
    fclose(myout);
    return 0;
}

