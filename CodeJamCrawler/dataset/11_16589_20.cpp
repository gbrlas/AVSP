
#include<stdio.h>
#include<string.h>
#include<math.h>

FILE *fin,*fout;

long int gcd(long int a,long int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
long int max(long int a,long int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
long int min(long int a,long int b)
{
    return a+b-max(a,b);
}


int main()
{
    fin=fopen("a.in","r");
    fout=fopen("a.out","w");
    long int a,b,c,d,e,x,y,z,g,h,i;
    char m[51][51];
    fscanf(fin,"%ld",&a);
    for(z=1;z<=a;z++)
    {
        fprintf(fout,"Case #%ld:\n",z);
        fscanf(fin,"%ld %ld",&b,&c);
        for(x=0;x<b;x++)
        {
            fscanf(fin,"%s",&m[x]);
        }
        for(x=0;x<=b-2;x++)
        {
            for(y=0;y<=c-2;y++)
            {
                if(m[x][y]=='#' && m[x+1][y]=='#' && m[x][y+1]=='#' && m[x+1][y+1]=='#')
                {
                    m[x][y]='/';
                    m[x+1][y]=92;
                    m[x][y+1]=92;
                    m[x+1][y+1]='/';
                }
            }
        }
        d=1;
        for(x=0;x<b;x++)
        {
            for(y=0;y<c;y++)
            {
                if(m[x][y]=='#')
                {
                    d=0;
                }
            }
        }
        if(d)
        {
            for(x=0;x<b;x++)
            {
                fprintf(fout,"%s\n",m[x]);
            }
        }
        else
        {
            fprintf(fout,"Impossible\n");
        }
    }
return 0;
}


