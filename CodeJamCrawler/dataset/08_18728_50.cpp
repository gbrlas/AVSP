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

char s[1<<20], v[1<<20];
int n;

int ask(char *u, int m)
{
   int ans=0, i;
   frr(i,1,m) ans+=u[i]!=u[i-1];
   return ans+1;
}

int main()
{
   int p[32], T, t, k, i, j, ans;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %s", &k, s);
      n=strlen(s);
      
      ans=1<<20;
      
      fr(i,k) p[i]=i;
      do
      {
         for(i=0; i<n; i+=k)
            fr(j,k)
               v[i+j]=s[i+p[j]];
         v[n]=0;
         ans<?=ask(v, n);
      } while(next_permutation(p, p+k));
      
      printf("Case #%d: %d\n", t, ans);
   }
   
   return 0;
}
