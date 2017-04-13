#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2;
    int test, c, n, s, p, ans, val, surval;
    int t[100]; 
    f1=fopen("B-large.in","r");
    f2=fopen("lang.out","w+");
    if(f1==NULL)
       printf("\nFILE CAN'T BE OPENED");
    else {
        while(test!=EOF){
            fscanf(f1, "%d", &test);
            int c=test;
            if(test==EOF)
              exit(1);
            while(test-- > 0){
                fscanf(f1, "%d %d %d", &n, &s, &p); 
                for(int i=0; i<n; i++)
                    fscanf(f1, "%d", &t[i]);
                ans = 0;
                val = (3 * (p - 1)) + 1;
                surval = (3 * (p - 2)) + 2;
                
                for(int i=0; i<n; i++){
                    if(t[i] >= val && t[i]>=p ) ans++;
                    else if(t[i]>1 && t[i]<29 && t[i] >= surval && s!=0 && t[i]>=p){ ans++; s--;}
                } 
                
                fprintf(f2, "Case #%d: %d\n", c-test, ans);
            }        
        }
    }
    fclose(f1);
    fclose(f2);
    return(0);
}
