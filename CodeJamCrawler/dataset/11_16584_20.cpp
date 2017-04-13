
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


int main() {
fin=fopen("a.in","r");
fout=fopen("a.out","w");
long int a,b,c,d,e,x,y,z;
char m[110][110];
double p[110],q[110],r[110];
double f,g,h,i;
long int s[110];
fscanf(fin,"%ld",&a);
for(z=1;z<=a;z++)
{
    fprintf(fout,"Case #%ld:\n",z);
    fscanf(fin,"%ld",&b);
    for(y=0;y<b;y++)
    {
        fscanf(fin,"%s",&m[y]);
        c=0;
        d=0;
        p[y]=0;
        for(x=0;x<b;x++)
        {
            if(m[y][x]!='.')
            {
                c++;
            }
            if(m[y][x]=='1')
            {
                d++;
            }
        }
        s[y]=c;
        if(c>0)
        {
        p[y]=(double)d;
        }
    }
    for(x=0;x<b;x++)
    {
        c=0;
            f=0;
            g=0;
            h=0;
            q[x]=0;
        for(y=0;y<b;y++)
        {

            if(m[x][y]!='.')
            {
                c++;
                if(m[x][y]=='0' && s[y]>1)
                {
                f+=(p[y]-1)/(double)(s[y]-1);
                }
                else
                {
                    f+=p[y]/(double)(s[y]-1);
                }
            }
        }
        q[x]=f/(double)c;
    }
    for(x=0;x<b;x++)
    {
        c=0;
            f=0;
            r[x]=0;
        for(y=0;y<b;y++)
        {
            if(m[x][y]!='.')
            {
                c++;
                f=f+q[y];
            }
        }
            if(c>0)
            {
            r[x]=f/(double)c;
            }

    }
    for(x=0;x<b;x++)
    {
        fprintf(fout,"%.12lf\n",.25*p[x]/(double)s[x]+.5*q[x]+.25*r[x]);
    }
}

return 0;
}


