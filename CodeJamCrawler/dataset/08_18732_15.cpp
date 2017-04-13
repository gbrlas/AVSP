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

int x[1<<10], y[1<<10][1<<10], c[1<<10], z[2][1<<10];

int ok(int n)
{
   int j;
   fr(j,9) if((n>>j&3)==3) break;
   return j==9;
}

int main()
{
   char map[16][16];
   int bit[16], M, N, T, t, i, j, k;
   
   memset(x, 0, sizeof(x));
   memset(y, 0, sizeof(y));
   fr(i,1<<10) x[i]=ok(i);
   fr(i,1<<10) fr(j,1<<10) if(x[i] && x[j]) y[i][j]=ok(i|j);
   c[0]=0;
   frr(i,1,1<<10) c[i]=1+c[i&i-1];
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &M, &N);
      fr(i,M)
      {
         scanf("%s", map[i]);
         bit[i]=0;
         fr(j,N) if(map[i][j]=='x') bit[i]|=1<<j;
      }
      
      fr(i,1<<N) z[0][i]=(x[i] && (i&bit[0])==0)?c[i]:0;
      frr(k,1,M)
      {
         fr(i,1<<N) z[1][i]=0;
         fr(i,1<<N) if(x[i]) fr(j,1<<N) if(x[j] && (j&bit[k])==0 && y[i][j]) z[1][j]>?=z[0][i]+c[j];
         fr(i,1<<N) z[0][i]=z[1][i];
      }
      
      int ans=0;
      fr(i,1<<N) ans>?=z[0][i];
      
      printf("Case #%d: %d\n", t, ans);
   }
   
   return 0;
}
