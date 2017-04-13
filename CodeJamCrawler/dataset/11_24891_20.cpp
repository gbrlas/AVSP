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
     int cases,caseval,i,j,a,b,n,total[200];
     vector<string> v;
     string str;
     double x,wp[200],owp[200],oowp[200],rpi;
     scanf("%d",&cases);
     caseval=0;
     while(cases--)
     {
          caseval++;
          scanf("%d",&n);
          printf("Case #%d:\n",caseval);
          v.clear();
          for(i=0;i<n;i++)
          {
               cin>>str;
               v.push_back(str);
               a=0;
               b=0;
               for(j=0;j<n;j++)
               {
                    if(str[j]!='.') b++;
                    if(str[j]=='1') a++;
               }
               total[i]=b;
               wp[i]=(a*1.0)/(b*1.0);
          }
          for(i=0;i<n;i++)
          {
              x=0.0;
              b=0;
              for(j=0;j<n;j++)
              {
                   if(v[i][j]=='0')
                        x+=( ((wp[j]*total[j])-1)/(total[j]-1) );
                   else if(v[i][j]=='1')
                        x+=( ((wp[j]*total[j]))/(total[j]-1) );
              }
              owp[i]=x/total[i];
          }
          for(i=0;i<n;i++)
          {
              x=0.0;
              b=0;
              for(j=0;j<n;j++)
              {
                   if(v[i][j]!='.')
                   {
                        x+=owp[j];
                        b++;
                   }
              }
              oowp[i]=x/b;
              rpi = (0.25 * wp[i]) + (0.50 * owp[i]) + (0.25 * oowp[i]);
              printf("%lf\n",rpi);
          }
     }
     return 0;
}
          
