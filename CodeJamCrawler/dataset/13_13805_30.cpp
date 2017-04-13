#include<stdio.h>
#include<math.h>
#define N 1000
int pal(int x)
{
    int n=0,i,ok,m,s[N];
    m=x;
    while(m!=0)
    {
        s[n]=m%10;
        m=m/10;
        n++;
    }
    ok=1;
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            ok=0;
        }
    }
    return ok;
}
int main()
{
    int i,n,a,b,j,k,c;
    FILE* f1;
    FILE* f2;
    f1=fopen("C-small-attempt0.in","r");
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++)
    {
        c=0;
        fscanf(f1,"%d%d",&a,&b);
        for(j=a;j<=b;j++)
        {
            if(j==1) c++;
            for(k=0;k<=j/2;k++)
            {
                if((k*k)==j)
                {
                    if(pal(j)==1 && pal(k)==1) c++;
                }
            }
        }
        f2=fopen("fairandsq.txt","a");
        fprintf(f2,"Case #%d: %d\n",i+1,c);
        fclose(f2);
    }
    fclose(f1);
    return 0;
}
