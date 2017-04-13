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
     string ans,str,opp,com;
     int caseval=0,cases,c,d,n,i,flag,len,j;
     scanf("%d",&cases);
     while(cases--)
     {
          caseval++;
          scanf("%d",&c);
          if(c!=0)
               cin>>com;
          scanf("%d",&d);
          if(d!=0)
               cin>>opp;
          
          scanf("%d",&n);
          cin>>str;
          string ans;
          flag=0;
          if(c==0 && d==0)
               ans=str;
        else
        {
          for(i=0;i<n;i++)
          {
               len=ans.size();
               if(c!=0 && len!=0)
               {
                    if( (str[i]==com[0] && ans[len-1]==com[1]) || (str[i]==com[1] && ans[len-1]==com[0]) )
                    {
                         ans[len-1]=com[2];
                         flag=0;
                         for(j=0;j<len;j++)
                         {
                              if(ans[j]==opp[0])
                              {
                                   flag=1;
                                   break;
                              }
                              if(ans[j]==opp[1])
                              {
                                   flag=2;
                                   break;
                              }
                         }
                         continue;
                    }
               }
               ans.push_back(str[i]);
               if(d!=0)
               {
                    if(flag==0)
                    {
                         if(str[i]==opp[0])
                              flag=1;
                              
                         else if(str[i]==opp[1])
                              flag=2;
                    }
                    else if(flag==1 && str[i]==opp[1])
                    {
                         ans.clear();
                         flag=0;
                    }
                    else if(flag==2 && str[i]==opp[0])
                    {
                         ans.clear();
                         flag=0;
                    }
               }
          }
        }
        len=ans.size();
          printf("Case #%d: [",caseval);
          for(i=0;i<len-1;i++)
               printf("%c, ",ans[i]);
          if(ans.size()!=0)
               printf("%c",ans[len-1]);
          printf("]\n");
     }
     return 0;
}
