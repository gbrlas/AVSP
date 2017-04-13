#include<iostream>
#include<stdio.h>
using namespace std;
int a,b,k,t,cs,i,j;
long long int cnt,s;
int main()
{
    freopen("Bout.txt","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    scanf("%d",&t);
    while(t--) 
    {
          cs++;
          s=0;
          cnt=0;
          scanf("%d %d %d",&a,&b,&k);
          for(i=0;i<a;i++)
          {
              for(j=0;j<b;j++)
              {
                  if((i&j)<k)
                  cnt++; 
              }
          }
          printf("Case #%d: %lld\n",cs,cnt);
    }
    return 0;
} 
