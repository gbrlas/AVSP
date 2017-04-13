using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

int countdig(int a)
{
    int x=0;
    while(a)
    {
         x++;
         a/=10;
    }
    return x;
}
int main()
{
    int tc,a,b,fact,ans,cases,i,temp,val,dig;
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);

    scanf("%d",&cases);tc=0;
    
    while(cases--)
    {
         tc++;
         scanf("%d%d",&a,&b);
         dig=countdig(a);
         fact=1;
         for(i=2;i<=dig;i++) fact*=10;
         ans=0;
         
         for(i=a;i<=b;i++)
         {
              temp=i;
              do
              {
                   if(temp>i && temp<=b) ans++;
                   val=fact;
                   while(temp%10==0)
                        temp/=10;

                   temp=(temp%10)*val+(temp/10);
              }while(i!=temp);
         }
         printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
