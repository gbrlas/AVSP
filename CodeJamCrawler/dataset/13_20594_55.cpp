#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
long long int x;
long long int y;
}point;
bool cmp(const point &x,const point &y)
{
    return x.x<y.y;
}
char s[20010],out[4010],line[100];
long long int i, key[50]={1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004};
//long long int ispal(long long int c);
  int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
   long long int i2,i,out,t,in1,in2;
    //freopen("new.txt","w",stdout);
    //for(i=1;i<10000001;i++)
    //{
      //  if(ispal(i))
        //if(ispal(i*i))
          //  printf("%lld\n",i*i);
    //}
    scanf("%lld",&t);
    for(i2=1;i2<=t;i2++)
    {
        out=0;
    scanf("%lld %lld",&in1,&in2);
    i=0;
    while(in2>=key[i]&&i<=39)
    {
        if(in1<=key[i])
        out++;
        i++;
    }
    printf("Case #%lld: %lld\n",i2,out);
    }

}
long long int ispal(long long int c)
{
    long long int temp=0,q=c,o=0;
    while(c)
    {
        temp=c%10;
        o=(o*10)+temp;
        c/=10;
    }
    if(q==o)
    return 1;
    return 0;
}
