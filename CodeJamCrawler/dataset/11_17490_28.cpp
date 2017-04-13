#include <stdio.h>
using namespace std;

#define file_in "C-small-attempt0.in"
//#define file_in "B.in"
#define file_out "C.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;

int n, h, l;
int a[101];

bool check(int nd)
{
    int j;
    for (j=0; j<n; j++)
        if ((nd % a[j] != 0) && (a[j] % nd != 0)) return false;
    return true;
}

int main() {
    int i, j, k, x, y;
    int node;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d %d %d", &n, &l, &h);
        for (j=0; j<n;j++) fscanf(fi, "%d", &a[j]);
        
        for (node = l; node<=h; node++)
        {
            if (check(node))
            {
              fprintf(fo, "Case #%d: %d\n", i, node);
              goto nexti;
            }
        }
                
        fprintf(fo, "Case #%d: NO\n", i);
        
        nexti: ;
    }               
     fclose(fi);
    fclose(fo);
}
