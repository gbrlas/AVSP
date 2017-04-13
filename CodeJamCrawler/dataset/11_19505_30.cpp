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

int gcd(int a, int b)
{
   return a?gcd(b%a, a):b;
}

int main()
{
   int T, t, d, g;
   long long N;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%lld %d %d", &N, &d, &g);
      if(g==0)
         printf("Case #%d: %s\n", t, d==0?"Possible":"Broken");
      else if(g==100)
         printf("Case #%d: %s\n", t, d==100?"Possible":"Broken");
      else
      {
         int x=gcd(d, 100);
         printf("Case #%d: %s\n", t, N>=100/x?"Possible":"Broken");
      }
   }
   
   return 0;
}
