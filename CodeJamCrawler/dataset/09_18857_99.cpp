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
#define inside(x,y,X,Y) (0<=(x) && (x)<(X) && 0<=(y) && (y)<(Y))

int djs[1<<14];
void djs_init(int n)
{
   int i;
   for(i=0; i<n; djs[i]=i, i++);
}

int djs_find(int x)
{
   return x!=djs[x]?djs[x]=djs_find(djs[x]):x;
}

int djs_union(int x, int y)
{
   return djs[djs_find(x)]=djs_find(y);
}

int x[128][128], dx[]={0,-1,1,0}, dy[]={-1,0,0,1};
char z[1<<14];

int main()
{
   int T, H, W, t, i, j, k;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &H, &W);
      for(i=0; i<H; i++)
         for(j=0; j<W; scanf("%d", &(x[i][j++])));
      
      djs_init(H*W);
      for(i=0; i<H; i++)
         for(j=0; j<W; j++)
         {
            int w=1<<30, a, b;
            for(k=0; k<4; k++)
            {
               int u=j+dx[k];
               int v=i+dy[k];
               if(inside(u,v,W,H) && x[v][u]<x[i][j] && x[v][u]<w)
               {
                  w=x[v][u];
                  a=u;
                  b=v;
               }
            }
            if(w<1<<30)
               djs_union(i*W+j, b*W+a);
         }
      
      printf("Case #%d:\n", t);
      
      memset(z, -1, sizeof(z));
      char c='a';
      for(i=0; i<H; i++)
         for(j=0; j<W; j++)
         {
            if(z[djs_find(i*W+j)]==-1)
               z[djs_find(i*W+j)]=c++;
            printf("%c", z[djs_find(i*W+j)]);
            printf(j==W-1?"\n":" ");
         }
   }
   
   
   return 0;
}
