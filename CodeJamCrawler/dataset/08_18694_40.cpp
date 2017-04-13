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

int fav[2048][2048], ans[2048];

int main()
{
   int N, M, T, t, i, j, a, b, C;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &N, &M);
      fr(i,M) fr(j,N) fav[i][j]=2;
      fr(i,M)
      {
         scanf("%d", &C);
         fr(j,C)
         {
            scanf("%d %d", &a, &b);
            fav[i][a-1]<?=b;
         }
      }
      
      fr(i,N) ans[i]=0;
      
      for(int redo=1; redo;)
      {
         redo=0;
         fr(i,M)
         {
            int sat=0;
            fr(j,N) if(fav[i][j]==ans[j]) sat=1;
            if(!sat)
            {
               fr(j,N) if(fav[i][j]==1) break;
               if(j==N) goto fail;
               ans[j]=1;
               redo=1;
            }
         }
      }
      
      
      printf("Case #%d:", t);
      fr(i,N) printf(" %d", ans[i]);
      printf("\n");
      continue;

fail:      
      printf("Case #%d: IMPOSSIBLE\n", t);
   }
   
   return 0;
}
