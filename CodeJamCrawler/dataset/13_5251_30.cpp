#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int ispalin(int num)
{
    int temp,s=0,r;
    temp=num;
    while(num!=0)
    {
        r=num%10;
        s=s*10+r;
        num/=10;
    }
    if(temp==s)
    return 1;
    else
    return 0;
}
int main()
{
    int t,a,b,i,j,count,sq;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        count=0;
        scanf("%d %d",&a,&b);
        for(j=a;j<=b;j++)
        {
            sq=sqrt(j);
            if(sq*sq==j)
            if(ispalin(j)==1)
            if(ispalin(sq)==1)
                count++;
        }
        printf("Case #%d: %d\n",i+1,count);
    }
}
