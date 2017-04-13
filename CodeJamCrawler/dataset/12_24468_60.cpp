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

int len;
string tostring(int x)
{
     string str;
     int r;
     char c;
     str="";
     while(x)
     {
          r=x%10;
          x/=10;
          
          c=r+'0';
          str=c+str;
     }
     return str;
}
string next(string str)
{
     int i,x;
     for(i=len-1;i>=0 && str[i]=='0';i--);
     
     string temp="";
     x=i;
     for(;i<len;i++) temp=temp+str[i];
     for(i=0;i<x;i++) temp=temp+str[i];
     
     return temp;
}
int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int cases,a,b,tc,ans,i;
    string final,temp,val;
    scanf("%d",&cases);tc=0;
    
    while(cases--)
    {
         tc++;
         scanf("%d%d",&a,&b);
         final=tostring(b);
         
         len=final.length();

         ans=0;
         for(i=a;i<=b;i++)
         {
          //    cout<<i<<endl;
              temp=tostring(i);
              val=next(temp);
              while(val!=temp)
              {
          //         cout<<val<<" "<<temp<<endl;
                   if(val>temp && val<=final)
                        ans++;
                   val=next(val);
              }
         }
         printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
              
