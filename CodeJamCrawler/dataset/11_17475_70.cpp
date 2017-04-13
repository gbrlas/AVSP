#include <stdio.h>
using namespace std;

#define file_in "B-large.in"
#define file_out "magicka.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;

int c, d, n, k; /* k = result.length */
char inv[40][4];
char opp[30][3];
char st[101];
char res[101];
char ch;

bool invoke(char c1, char c2)
{
    int i;
    
    for (i=1; i<=c; i++)
        if (((inv[i][0]==c1)&&(inv[i][1]==c2)) ||
           ((inv[i][1]==c1)&&(inv[i][0]==c2)))
           {
               ch = inv[i][2];
               return true;
           }
           
    return false;
}

bool oppose(char c1)        
{
    int i, j;
    
    for (i=1; i<=d; i++)
        for (j=0; j<=k; j++)
            if (((opp[i][0]==c1)&&(opp[i][1]==res[j])) ||
           ((opp[i][1]==c1)&&(opp[i][0]==res[j])))
           {
               return true;
           }
           
    return false;
}

int main() {
    int i, j;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d", &c);
        for (j=1; j<=c; j++)
            fscanf(fi, "%s", inv[j]);
   
        fscanf(fi, "%d", &d);
        for (j=1; j<=d; j++)
            fscanf(fi, "%s", opp[j]);
                      
        fscanf(fi, "%d %s", &n, st);
        
        k = 0;
        res[0] = st[0];
        for (j=1; j<n; j++)
        {
            if (k<0)
            {
                    k=0;
                    res[k] = st[j];
            }
            else
            {
                if (invoke(res[k], st[j])) 
                {
                   res[k] = ch;
                } else if (oppose(st[j]))
                  {
                       k = -1;
                  }
                  else
                  {
                      k++;
                      res[k] = st[j];
                  }
            }
        }                
        k++;
        fprintf(fo, "Case #%d: [", i);
        for (j=0; j<k-1; j++) fprintf(fo, "%c, ", res[j]);
        if (k>0) fprintf(fo, "%c]\n", res[k-1]);
        else fprintf(fo, "]\n");
    }
    fclose(fi);
    fclose(fo);
}


