#include<stdio.h>
#include<math.h>
int ispalin(long int x)
{
    long int s=0,n=x;
    while(x!=0)
    {
        s=s*10+(x%10);
        x/=10;
    }
    if(s==n)
        return 1;
    else
        return 0;
}
int isps(long int x)
{
    long int n=sqrt(x);
    if(n*n==x)
        return 1;
    else
        return 0;
}
main()
{
    int t,j=1;double a,b;
    scanf("%d",&t);
    while(t--)
    {
        long int i,c=0;
        scanf("%lf%lf",&a,&b);
        for(i=ceil(sqrt(a));i<=floor(sqrt(b));i++)
        {
                if(ispalin(i*i)==1 && ispalin(i)==1)
                {

                c++;}
        }
        printf("Case #%d: %ld\n",j++,c);
    }
    return 0;
}
