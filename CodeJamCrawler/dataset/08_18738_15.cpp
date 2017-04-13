#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
#define iss istringstream
#define pb push_back
#define cs c_str()
#define frr(i,a,b) for(i=(a); i<(b); i++)
#define fr(i,n) frr(i,0,(n))
#define rrf(i,b,a) for(i=(b)-1; i>=(a); i--)
#define rf(i,n) rrf(i,(n),0)
#define sq(x,y,z) sqrt((x)*(x)+(y)*(y)+(z)*(z))
#define in(x,s) (s.find(x)!=s.end())
#define sv(x) sort(x.begin(),x.end())

int x[128][128], d[128][128];

int main()
{
   char s[128];
   int T, t, H, W, R, i, j, k;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d %d", &H, &W, &R);
      memset(x, 0, sizeof(x));
      memset(d, 0, sizeof(d));
      
      fr(k,R)
      {
         scanf("%d %d", &i, &j);
         d[i-1][j-1]=1;
      }
      
      for(j=H-1; j>=0; j--)
      for(i=W-1; i>=0; i--)
      {
         if(j==H-1 && i==W-1)
            x[j][i]=1;
         else if(!d[j][i])
         {
            x[j][i]=((j+2<H && i+1<W)?x[j+2][i+1]:0)+((j+1<H && i+2<W)?x[j+1][i+2]:0);
            x[j][i]%=10007;
         }
      }
      
      printf("Case #%d: %d\n", t, x[0][0]);
   }
   
   return 0;
}
