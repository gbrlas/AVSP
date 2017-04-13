#include <stdio.h>
using namespace std;

//#define file_in "a.in"
#define file_in "A-large.in"
#define file_out "B.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;
long long n, d, g, wd, wg;
long long pd, pg;
long long d2, d5;
long long g2, g5;
long long ld, lg;

void abc()
{
    int t = pd;
    d2 = 0;
    while ((t % 2 ==0) && (t>0))
    {
        d2++; t/=2;
    }
    
    t = pd;
    d5 = 0;
    while ((t % 5 ==0) && (t>0))
    {
        d5++; t/=5;
    }
    
    t = pg;
    g2 = 0;
    while ((t % 2 ==0) && (t>0))
    {
        g2++; t/=2;
    }
    
    t = pg;
    g5 = 0;
    while ((t % 5 ==0) && (t>0))
    {
        g5++; t/=5;
    }
}

int main() {
    int i, j;
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%lld %d %d", &n, &pd, &pg);
        if ((pd > 0) && (pg ==0))
        {
            fprintf(fo, "Case #%d: Broken\n", i);
            goto  nexti;
        }
        /*
        if ((pd == 0) && (pg ==0))
        {
            fprintf(fo, "Case #%d: Possible\n", i);
           goto  nexti;
        }
        */
        
        if (pd == 0) 
            if (pg == 100)
            {
                fprintf(fo, "Case #%d: Broken\n", i);
                goto  nexti;
            }
            else
            {
                fprintf(fo, "Case #%d: Possible\n", i);
                goto  nexti;
            }
        
        if ((pd <100) && (pg ==100))
        {
            fprintf(fo, "Case #%d: Broken\n", i);
           goto  nexti;
        }
        
        abc();
        
        d = 1;
        if (d2 < 2) d *= 2;
        if (d2 < 1) d *= 2;
        if (d5 < 2) d *= 5;
        if (d5 < 1) d *= 5;
        
        g = 1;
        if (g2 < 2) g *= 2;
        if (g2 < 1) g *= 2;
        if (g5 < 2) g *= 5;
        if (g5 < 1) g *= 5;
        
        ld = d; lg = g;
        
        if (d > n)
        {
            fprintf(fo, "Case #%d: Broken\n", i);
        }
        else
        {
            while (d<=n)
            {
                g = lg;
                while (g<d) g += lg;
                wd = pd * d / 100;
                for (j=1; j<10000; j++)
                {
                    wg = pg * g / 100;
                    if ((wg >= wd) && (g-wg >= d-wd))
                    {
                        fprintf(fo, "Case #%d: Possible\n", i);  
                        goto nexti;
                    }
                    g+=lg;
                }
  
                d += ld;
  
            }
            
            fprintf(fo, "Case #%d: Broken\n", i);    
        }
        
nexti: ;        
                               
    }
    fclose(fi);
    fclose(fo);
}


