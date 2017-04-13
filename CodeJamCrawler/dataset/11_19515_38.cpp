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
   int T, t, X, S, R, N, i, j, k;
   double Z;
   vector< pair<int, int > > w;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      w.clear();
      scanf("%d %d %d %lf %d", &X, &S, &R, &Z, &N);
      fr(i,N)
      {
         int a, b, c;
         scanf("%d %d %d", &a, &b, &c);
         w.pb(make_pair(c, b-a));
         X-=b-a;
      }
      w.pb(make_pair(0, X));
      sv(w);
      
      double ans=0;
      fr(i,N+1)
      {
         if(Z>1e-9)
         {
            double u=(double)(w[i].second)/(w[i].first+R);
            if(u>Z)
            {
               ans+=(w[i].second-(w[i].first+R)*Z)/(w[i].first+S)+Z;
               Z=0;
            }
            else
            {
               Z-=u;
               ans+=u;
            }
         }
         else
         {
            ans+=(double)(w[i].second)/(w[i].first+S);
         }
      }
      
      printf("Case #%d: %.9lf\n", t, ans);
   }
   
   return 0;
}
