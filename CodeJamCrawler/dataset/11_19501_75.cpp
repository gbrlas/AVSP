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

double f[1024], x[1024][1024], y[1024][1024], z[1024], w;

int main()
{
   int N, T, t, i, j, k, p[1024], q[1024];
   
   f[0]=1;
   for(i=1; i<1024; i++) f[i]=f[i-1]*i;
   for(i=0; i<1024; i++) x[i][0]=x[i][i]=1;
   for(i=2; i<1024; i++)
      for(j=1; j<i; j++)
         x[i][j]=x[i-1][j-1]+x[i-1][j];
   y[1][0]=0;
   y[1][1]=1;
   for(i=2; i<1024; i++)
   {
      y[i][0]=f[i];
      for(j=1; j<i; j++)
         y[i][0]-=y[i][j]=x[i][j]*y[i-j][0];
      y[i][0]-=y[i][i]=1;
   }
   z[0]=z[1]=0;
   z[2]=2;
   for(i=3; i<1024; i++)
   {
      w=1;
      for(j=1; j<=i; j++)
         w+=z[i-j]*y[i][j]/f[i];
      z[i]=w/(1-y[i][0]/f[i]);
   }
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      for(scanf("%d", &N), i=0; i<N; scanf("%d", p+i++));
      for(i=0; i<N; q[i]=p[i], i++);
      sort(p, p+i);
      for(j=i=0; i<N; i++)
         j+=p[i]!=q[i];
      
      printf("Case #%d: %.6lf\n", t, j*1.0);
   }
   
   return 0;
}
