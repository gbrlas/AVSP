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
   int T, t, i, j, k;
   long long N, P, x, y, z, w;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%lld %lld", &N, &P);
      if(P==1)
         printf("Case #%d: %lld %lld\n", t, 0LL, 0LL);
      else if(P==1LL<<N)
         printf("Case #%d: %lld %lld\n", t, (1LL<<N)-1, (1LL<<N)-1);
      else
      {
         for(z=0, x=P, y=N-1; x>1LL<<y; z+=1LL<<N-y, x-=1LL<<y--);
         for(w=0, x=N-1; 1LL<<x>P; w+=1LL<<N-x--);
         printf("Case #%d: %lld %lld\n", t, z, (1LL<<N)-1-w-1);
      }
   }
   
   return 0;
}
