#include<stdio.h>

int main()
{
    FILE *fin  = fopen ("A-large.in", "r");
    FILE *fout = fopen ("test.txt", "w");
    int T,a[32]={0},i,j=1,x=1;
    for(i=1;i<31;i++)
    {
        if(i>1)
            j=j*2;
        a[i]=a[i-1]+j;
    }
    fscanf(fin,"%d",&T);
    while(T-->0)
    {
        int N,K;
        fscanf (fin, "%d %d", &N, &K);
        if(K==0)
            fprintf (fout, "Case #%d: OFF\n", x);
        else
        {
            if(K%(a[N]+1)==a[N])
                fprintf (fout, "Case #%d: ON\n", x);
            else
                fprintf (fout, "Case #%d: OFF\n", x);
        }
        x++;
    }
    return 0;
}
