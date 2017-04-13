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

int main()
{
   int T, t, n, i, j, ans, y[64];
   char x[64][64];
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &n);
      fr(i,n) scanf("%s", x[i]);
      
      fr(i,n)
      {
         for(j=n-1; j>=0 && x[i][j]=='0'; j--);
         y[i]=j;
      }
      
      ans=0;
      fr(i,n) if(y[i]>i)
      {
         for(j=i+1; y[j]>i; j++);
         ans+=j-i;
         for(; j>i; j--) y[j]=y[j-1];
      }
      
      printf("Case #%d: %d\n", t, ans);
   }
   
   return 0;
}
