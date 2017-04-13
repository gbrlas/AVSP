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

int x[128][128], u[128], v[128];

int main()
{
   int T, t, m, n, i, j, f;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &m, &n);
      fr(i,m) fr(j,n) scanf("%d", &(x[i][j]));
      fr(i,m)
      {
         u[i]=0;
         fr(j,n) u[i]>?=x[i][j];
      }
      fr(j,n)
      {
         v[j]=0;
         fr(i,m) v[j]>?=x[i][j];
      }
      f=0;
      fr(i,m) fr(j,n) f=f || x[i][j]!=u[i] && x[i][j]!=v[j];      
      printf("Case #%d: %s\n", t, f?"NO":"YES");
   }
   
   return 0;
}
