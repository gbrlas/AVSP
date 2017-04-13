#include<stdio.h>
#include<math.h>
long int min(long int a,long int b)
{
    if(b>a)
    {
        return a;
    }
    return b;
}
main()
{
    FILE *fin=fopen("a.in","r");
    FILE *fout=fopen("a.out","w");
    char a[2];
    long int b,d,e,f,c,m,n,g,h,x,y,z;
    e=0;
    f=1;
    g=1;
    fscanf(fin,"%ld",&b);
    for(x=1;x<=b;x=x+1)
    {
        fscanf(fin,"%ld",&c);
        e=0;
        f=1;
        g=1;
        m=0;
        n=0;
        h=1;
        for(y=1;y<=c;y=y+1)
        {
            fscanf(fin,"%s %ld",&a,&d);
            if(a[0]=='B')
            {
                m+=abs(d-f)+1;
                if(h==2)
                {
                    m-=min(n,m-1);
                    e+=n;
                    n=0;
                }
                h=1;
                f=d;
            }
            else
            {
                n+=abs(d-g)+1;
                if(h==1)
                {
                    n-=min(n-1,m);
                    e+=m;
                    m=0;
                }
                h=2;
                g=d;
            }
        }
        e+=m+n;
        fprintf(fout,"Case #%ld: ",x);
        fprintf(fout,"%ld\n",e);
    }
    return 0;
}
