#include <stdio.h>
using namespace std;

#define file_in "C-small-attempt0.in"
#define file_out "candy.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;
int n;
long min, sum, exor;

int main() {
    int i, j, x;
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        min = 1000001;
        sum = 0;
        exor = 0;
        fscanf(fi, "%d", &n);
        for (j=1; j<=n; j++)
        {
            fscanf(fi, "%d", &x);
            sum += x;
            exor ^= x;
            if (x < min) min = x;
        }
            
        if (exor==0) fprintf(fo, "Case #%d: %ld\n", i, sum-min);
        else fprintf(fo, "Case #%d: NO\n", i);
    }
    fclose(fi);
    fclose(fo);
}


