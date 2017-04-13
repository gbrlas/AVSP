#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long minval=0;
char s[100];
long long decode[200];

long long poww(long long b,long long p)
{
    long long sum=1,i=0;
    for(i=0;i<p;i++)sum=sum*b;
    return sum;
}

main()
{
    long long i,j,k,z,t,nownum=0,base,len;
    scanf("%lld",&t);
    for(z=0;z<t;z++)
    {
        scanf("%s",s);
        len=strlen(s);
        minval=0;
        nownum=0;
        for(i=0;i<200;i++)decode[i]=-1;

        decode[s[0]]=1;
        for(i=1;i<len;i++)
        {
            if(decode[s[i]]==-1)
            {
                decode[s[i]]=nownum;
                nownum++;
                if(nownum==1)nownum++;
            }
        }
        if(nownum==0)base=2; else base=nownum;

        for(i=len-1;i>=0;i--)
        {
            minval+=poww(base,len-1-i)*decode[s[i]];
        }

        printf("Case #%lld: %lld\n",z+1,minval);


    }


}
