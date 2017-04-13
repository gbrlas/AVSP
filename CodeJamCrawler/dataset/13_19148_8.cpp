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
int main()
{
   char s[101];
   char ch[]="01110111011111011111011111";
   int t,i,j,l,n,k,z,x;
   int c,co;
   bool flag;
   scanf("%d",&t);
   for(i=1;i<=t;++i)
   {
      scanf("%s %d",s,&n);
      l=strlen(s);
      c=0;
      co=0;
      z=n;
      while(z<=l)
      {
      for(j=0;j<=(l-z);++j)
      {
         c=0;
         for(k=j;k<(j+z);++k)
         {
            if(ch[s[k]-'a']=='1')
            {
               ++c;
               if(c==n) {++co;  break; }
            }
            else c=0;
            //printf("%d %d\n",k,c);
         }
         //printf("---\n");
      }
      ++z;
      }
      printf("Case #%d: %d\n",i,co);
   }
   return 0;
}
