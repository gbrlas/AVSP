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
   char s[128];
   int x[1024], y[1024], n, T, t, i, j, u, v;
   long long ans;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &n);
      fr(i,n) scanf("%d", x+i);
      fr(i,n) scanf("%d", y+i);
      
      sort(x,x+n);
      sort(y,y+n);
      ans=0;
      
      i=0; j=n-1;
      u=0; v=n-1;
      for(; i<=j && (long long)x[i]*y[v]<=0; ans+=x[i]*y[v], i++, v--);
      for(; i<=j && (long long)x[j]*y[u]<=0; ans+=x[j]*y[u], u++, j--);
      for(; i<=j; ans+=x[i]*y[v], i++, v--);
      
      
      printf("Case #%d: %lld\n", t, ans);
   }
   
   return 0;
}
