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
   int N, T, t, i, j, k, p;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      p=j=0;
      k=1<<30;
      for(scanf("%d", &N); N--; scanf("%d", &i), j+=i, k<?=i, p^=i);
      if(p)
         printf("Case #%d: NO\n", t);
      else
         printf("Case #%d: %d\n", t, j-k);
   }
   
   return 0;
}
