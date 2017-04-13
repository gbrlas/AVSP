#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define MAX 101
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
     freopen("repeater.txt", "w", stdout);
   int t;
   scanf("%d",&t);
   int i,n;
   int count[MAX];
   char str[MAX][MAX];
   for(i = 1;i <= t; i++)
   {
       scanf("%d",&n);
       for(int j = 1;j<=n;j++)
       scanf("%s",str[j]);

       int m = 0,n = 0;int flag = 0,ans = 0,diff,f1 = 0,f2 = 0;
      while(str[1][m]!='\0' || str[2][n]!= '\0')
      {
          f1 = 0;f2 = 0;
          while(str[1][m+1]==str[1][m])
          {
              m++;f1++;
          }
          while(str[2][n+1] == str[2][n])
          {
              n++;f2++;
          }
          if(str[1][m]==str[2][n])
          {
              if(f1>f2)  diff = f1-f2;
              else diff = f2-f1;
              ans+=diff;
              flag = 1;
          }
          else
          {
              flag = 0;
              break;
          }
          m++;n++;
      }

      if(flag == 0)
      {
          printf("Case #%d: Fegla Won\n",i);
      }
      else
        printf("Case #%d: %d\n",i,ans);
   }
}


