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

int M, V, G[1<<15], C[1<<15], B[1<<15], ans[1<<15][2];

int main()
{
   char s[128];
   int T, t, i;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &M, &V);
      fr(i,M+1) B[i]=-1;
      frr(i,1,(M-1)/2+1) scanf("%d %d", G+i, C+i);
      for(; i<=M; i++)
      {
         scanf("%d", B+i);
         ans[i][0]=B[i]==0?0:(1<<20);
         ans[i][1]=B[i]==1?0:(1<<20);
      }
      for(i=(M-1)/2; i>=1; i--)
      {
         ans[i][0]=1<<20;
         ans[i][1]=1<<20;
         if(G[i] || C[i])
         {
            ans[i][0]<?=(ans[i*2][0]<?ans[i*2+1][0])+(G[i]==0);
            ans[i][1]<?=(ans[i*2][1]+ans[i*2+1][1])+(G[i]==0);
         }
         if(G[i]==0 || C[i])
         {
            ans[i][0]<?=(ans[i*2][0]+ans[i*2+1][0])+(G[i]==1);
            ans[i][1]<?=(ans[i*2][1]<?ans[i*2+1][1])+(G[i]==1);
         }
      }
      
      if(ans[1][V]<1000000)
         printf("Case #%d: %d\n", t, ans[1][V]);
      else
         printf("Case #%d: IMPOSSIBLE\n", t);
   }
   
   return 0;
}
