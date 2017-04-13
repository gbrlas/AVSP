#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
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
#define fi(p,x) for(typeof(x.end()) p=x.begin(); p!=x.end(); p++)
#define all(x) x.begin(),x.end()
#define inside(x,y,X,Y) (0<=(x) && (x)<(X) && 0<=(y) && (y)<(Y))
#define ratio(A,B,x,y,m) ((A)+(double)((B)-(A))*((m)-(x))/((y)-(x)))
template<class T> string x2s(T x) { ostringstream out; out << x; return out.str(); }

int g[128][128], h[128][128], p[128];

int main()
{
   int T, t, j, i, n, m, a, b;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &n);
      fr(i,n) fr(j,n) g[i][j]=0;
      fr(i,n-1)
      {
         scanf("%d %d", &a, &b);
         a--;
         b--;
         g[a][b]=g[b][a]=1;
      }
      scanf("%d", &m);
      fr(i,m) fr(j,m) h[i][j]=0;
      fr(i,m-1)
      {
         scanf("%d %d", &a, &b);
         a--;
         b--;
         h[a][b]=h[b][a]=1;
      }
      
      fr(i,n) p[i]=i;
      int v;
      do
      {
         v=1;
         for(i=m; i-- && v; )
            for(j=m; j-- && v; )
               if(h[i][j]!=g[p[i]][p[j]]) v=0;
         if(v) break;
      } while(next_permutation(p, p+n));
      
      printf("Case #%d: %s\n", t, v?"YES":"NO");
   }
   
   return 0;
}
