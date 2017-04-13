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

int main()
{
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n,s,p,num,i,one,two,both,temp,cases,tc,ans;
    scanf("%d",&cases);tc=0;
    
    while(cases--)
    {
         tc++;
         scanf("%d%d%d",&n,&s,&p);
         one=0;two=0;both=0;
         for(i=1;i<=n;i++)
         {
              scanf("%d",&num);
              if(num==0)
              {
                   if(p==0) one++;
                   continue;
              }
              if(num==1)
              {
                   if(p<=1) one++;
                   continue;
              }
              if(num==2)
              {
                   if(p==0) both++;
                   else if(p==1) one++;
                   else if(p==2) two++;
                   continue;
              }
              if(num%3==0)
              {
                   temp=num/3;
                   if(temp>=p && (temp+1)>=p) both++;
                   else if(temp<p && (temp+1)>=p) two++;
              }
              else if(num%3==1)
              {
                   temp=num/3;
                   if((temp+1)>=p) both++;
              }
              else if(num%3==2)
              {
                   temp=num/3;
                   if((temp+2)>=p && (temp+1)>=p) both++;
                   else if((temp+2)>=p && (temp+1)<p) two++;
              }
         }

         if(s<=two)
              ans=s+both+one;
         else if(s>two)
              ans=s+one+(both-s+two);
         
         printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
