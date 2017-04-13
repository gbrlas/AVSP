#include <stdio.h>
using namespace std;

#define file_in "A-large.in"
//#define file_in "A.in"
#define file_out "A.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;
int n;
char a[101][101];
int b[101][101];
int c[101];
int w[101];
float wp[101];
float owp[101];
float oowp[101];

void abc()
{
    int i, j, k, x, y, z;
    float t;
    for (i=0; i<n; i++)
    {
        t = 0;
        z = 0;
        for (j=0; j<n; j++) if ((j!=i)&&(b[i][j]>=0))
        {
            z++;
            
            y = 0;
            x = 0;
            for (k=0; k<n; k++)
            {
                if ((k!=i) && (k!=j))
                {
                    if (b[j][k]>=0) 
                    {   y++;
                        if (b[j][k]) x++;
                    }
                }
            }
            t+=(float)x/(float)y;
        }
        if (z>0) owp[i] = t/(float)z; else owp[i] = 0;
    }
    
    
    for (i=0; i<n; i++)
    {
        z = 0;
        t = 0;
        for (j=0; j<n; j++) if (b[i][j]>=0)
        {
            z++;
            t += owp[j];
        }
        if (z>0) oowp[i] = t/(float)z; else oowp[i] = 0;
    }
}
    
        
        
int main() {
    int i, j, k, x, y;
    float rpi;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d", &n);
        for (k=0; k<n; k++)
        {
            fscanf(fi, "%s", a[k]);
        
            x = 0;
            y = 0;
            for (j=0; j<n; j++)
            {
                if (a[k][j] != '.') 
            {   
                x++;
                b[k][j] = a[k][j]-48;
                if (b[k][j]) y++;
            }
            else b[k][j] = -1;
            }
           if (x>0) wp[k] = (float)y/float(x); else wp[k]=0;
        }
              
        abc();
        
        /*
        for (j=0; j<n; j++)
            fprintf(fo, "%.10f\n", owp[j]);
            
        for (j=0; j<n; j++)
            fprintf(fo, "%.10f\n", oowp[j]);
        */
        //RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP
        fprintf(fo, "Case #%d:\n", i);
        for (j=0; j<n; j++)
        {
            rpi = wp[j]*0.25 + 0.5*owp[j] + 0.25*oowp[j];
            fprintf(fo, "%.12f\n", rpi);
        }
            
        //fprintf(fo, "Case #%d: %ld\n", i, sum-min);
        //else fprintf(fo, "Case #%d: NO\n", i);
    }
    fclose(fi);
    fclose(fo);
}


