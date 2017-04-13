#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
using namespace std;
struct game
   {
      int x;
      int o;
      int t;
   };
   struct game r[4],c[4],d[2];
int main()
{

   int t,i,j,l;
   int xflag,oflag,dot;
   char ch[5][5];
   scanf("%d",&t);
   for(l=1;l<=t;++l)
   {
      for(i=0;i<4;++i) r[i].x=r[i].o=r[i].t=0;
      for(i=0;i<4;++i) c[i].x=c[i].o=c[i].t=0;
      for(i=0;i<2;++i) d[i].x=d[i].o=d[i].t=0;
      for(i=0;i<4;++i) scanf("%s",ch[i]);
      dot=0;
      for(i=0;i<4;++i)
      {
         for(j=0;j<4;++j)
         {
            if(ch[i][j]=='X')
            {
               ++r[i].x;
               ++c[j].x;
               if(i==j)++d[0].x;
               else if((i+j)==3) ++d[1].x;
            }
            else if(ch[i][j]=='O')
            {
               ++r[i].o;
               ++c[j].o;
               if(i==j)++d[0].o;
               else if((i+j)==3) ++d[1].o;
            }
            else if(ch[i][j]=='T')
            {
               r[i].t=1;
               c[j].t=1;
               if(i==j)d[0].t=1;
               else if((i+j)==3) d[1].t=1;
            }
            else if(ch[i][j]=='.')
            {
               dot=1;
            }
         }
      }
      xflag=0;
      oflag=0;
      for(i=0;i<4;++i)
      {
         if(r[i].x==4 || ((r[i].x+r[i].t)==4)) { xflag=1; break; }
         else if(r[i].o==4 || ((r[i].o+r[i].t==4))) { oflag=1; break; }
      }
      for(i=0;i<4;++i)
      {
         if(c[i].x==4 || ((c[i].x+c[i].t)==4)) { xflag=1; break; }
         else if(c[i].o==4 || ((c[i].o+c[i].t==4))) { oflag=1; break; }
         c[i].x=c[i].o=c[i].t=0;
      }
      for(i=0;i<2;++i)
      {
         if(d[i].x==4 || ((d[i].x+d[i].t)==4)) { xflag=1; break; }
         else if(d[i].o==4 || ((d[i].o+d[i].t==4))) { oflag=1; break; }
         d[i].x=d[i].o=d[i].t=0;
      }
      if(xflag) printf("Case #%d: X won\n",l);
      else if(oflag) printf("Case #%d: O won\n",l);
      else if(dot) printf("Case #%d: Game has not completed\n",l);
      else printf("Case #%d: Draw\n",l);
   }
   return 0;
}
