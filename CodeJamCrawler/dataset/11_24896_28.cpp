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

int main()
{
    string str;
    vector<string> v;
    int r,c,ans,left,cases,caseval=0,i,j;
    scanf("%d",&cases);
    while(cases--)
    {
         caseval++;
         scanf("%d %d",&r,&c);
         v.clear();
         cin>>str;
         left=0;
         ans=0;
         v.push_back(str);
         for(i=0;i<c;i++)
         {
              if(str[i]=='#') left++;
         }
         
         for(i=1;i<r;i++)
         {
              cin>>str;
              v.push_back(str);
              if(str[0]=='#') left++;
              for(j=1;j<c;j++)
              {
                   if(v[i][j]=='#' && v[i][j-1]=='#' && v[i-1][j]=='#' && v[i-1][j-1]=='#')
                   {
                        v[i][j]='/';
                        v[i][j-1]='\\';
                        v[i-1][j]='\\';
                        v[i-1][j-1]='/';
                        left-=3;
                        ans++;
                   }
                   else if(v[i][j]=='#') left++;
              }
         }
         printf("Case #%d:\n",caseval);
         if(left!=0)
              cout<<"Impossible\n";
         else
         {
              for(i=0;i<r;i++)
                   cout<<v[i]<<endl;
         }
    }
    return 0;
}
