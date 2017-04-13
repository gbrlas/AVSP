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
   int T, t, M, N, A;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d %d", &N, &M, &A);
      
      if(A>M*N)
         printf("Case #%d: IMPOSSIBLE\n", t);
      else
      {
         for(; M*N>=A; M--);
         M++;
         for(; M*N>=A; N--);
         N++;
         
         if(M*N==A)
            printf("Case #%d: %d %d %d %d %d %d\n", t, 0, 0, 0, M, N, 0);
         else
         {
            printf("Case #%d: %d %d %d %d %d %d\n", t, 0, 1, N-(M*N-A), M, N, 0);
         }
      }
   }
   
   return 0;
}
