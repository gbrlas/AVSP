#include<stdio.h>
#include<math.h>
long int m[1001],n[1001];
long int e,l,b=0;
void check(long int a,long int next)
{
    long int x,y,z,c,d,f,g,h;
    h=0;
    c=0;
    if(next>e)
    {
        return;
    }
    if(next>0)
    {
    for(y=0;y<e;y=y+1)
    {
        if(n[y]==1)
        {
            h=h^m[y];
            c+=m[y];
        }
    }
    }
    if(h==a)
    {
        if(c>b)
        {
            b=c;
        }
    }
    if(next<e)
    {
    for(x=next;x<e;x=x+1)
    {
        if(n[x]==1)
        {
            n[x]=0;
            check(a^m[x],x+1);
            n[x]=1;
        }
    }
    }
}
main()
{
    FILE *fin=fopen("a.in","r");
    FILE *fout=fopen("a.out","w");
    long int d,f,c,g,h,x,y,z;
    fscanf(fin,"%ld",&f);
    for(x=1;x<=f;x=x+1)
    {
        fscanf(fin,"%ld",&e);
        l=0;
        b=0;
        for(y=0;y<e;y=y+1)
        {
            fscanf(fin,"%ld",&m[y]);
            l+=m[y];
            n[y]=1;
        }
        fprintf(fout,"Case #%ld: ",x);
        b=0;
        check(0,0);
        if(b==0)
        {
            fprintf(fout,"NO\n");
        }
        else
        {
            if(b<l-b)
            {
                b=l-b;
            }
            fprintf(fout,"%ld\n",b);
        }
    }
    /*scanf("%ld %ld",&b,&c);
    printf("%ld",b^c);/*/
    return 0;
}
