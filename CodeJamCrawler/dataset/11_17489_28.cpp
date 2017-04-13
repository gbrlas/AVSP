#include <stdio.h>
using namespace std;

#define file_in "A-large.in"
//#define file_in "A.in"
#define file_out "A.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;
int r, c;
char a[52][52];
int b;
       
bool tryfill()
{
    int i, j;
    for (i=0; i<r-1; i++)
        for (j=0; j<c-1; j++)
            if (a[i][j]=='#')
            {
                if (a[i+1][j]!='#')  return false;
                if (a[i][j+1]!='#') return false;
                if (a[i+1][j+1]!='#') return false;
                
                a[i][j] = '/';
                a[i][j+1] = '\\';
                a[i+1][j] = '\\';
                a[i+1][j+1] = '/';
                
                return true;
            }     
}

int main() {
    int i, j, k, x, y;
    char ch;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d %d", &r, &c);
        
        b = 0;
         
        for (j=0; j<r; j++)
            fscanf(fi, "%s", a[j]);

        for (j=0; j<r; j++)
            for (k=0; k<c; k++)                
                if (a[j][k] == '#') b++;
                
        if (b%4)
        {                        
            fprintf(fo, "Case #%d:\n", i);
            fprintf(fo, "Impossible\n");
        }
        else
        {
            k = 1;
            while (k<=b/4)
            {
                if (tryfill())
                {
                    k++;
                } else
                {
                    fprintf(fo, "Case #%d:\n", i);
                    fprintf(fo, "Impossible\n");
                    goto nexti;
                }
            }
            
            fprintf(fo, "Case #%d:\n", i);
            for (j=0; j<r; j++)
            {
                for (k=0; k<c; k++)
                    fprintf(fo, "%c", a[j][k]);
                fprintf(fo, "\n");
            }
        }
nexti: ;        
    }
    fclose(fi);
    fclose(fo);
}


