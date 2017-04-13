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

# define PI 3.14159265

int gcd(int a,int b)
{
     if(b==0)
          return a;
     return gcd(b,a%b);
}
int main()
{
    int cases,n,l,h,i,val,pro,pos,lcm,caseval=0,x,ans,j,flag;
    vector<int> v;
    scanf("%d",&cases);
    while(cases--)
    {
         caseval++;
         scanf("%d %d %d",&n,&l,&h);
         v.clear();
         for(i=0;i<n;i++)
         {
              scanf("%d",&x);
              v.push_back(x);
         }
         flag=0;
         sort(v.begin(),v.end());
         for(i=l;i<=h;i++)
         {
              for(j=0;j<n;j++)
              {
                   if(v[j]>i && v[j]%i!=0)
                   {
                        flag=1;
                        break;
                   }
                   else if(v[j]<i && i%v[j]!=0)
                   {
                        flag=1;
                        break;
                   }
              }
              if(flag!=1)
              {
                   flag=2;
                   break;
              }
              flag=0;
         }
         printf("Case #%d: ",caseval);
         if(flag==2)
              cout<<i<<endl;
         else cout<<"NO"<<endl;  
    }
    return 0;
}
