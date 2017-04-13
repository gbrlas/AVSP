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

char w[512][512];
long long x[512][512], y[512][512], z[512][512];

int main()
{
   int T, t, R, C, D, i, j, k, s;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d %d", &R, &C, &D);
      fr(i,R) scanf("%s", w+i);
      
      memset(x, 0, sizeof(x));
      memset(y, 0, sizeof(y));
      memset(z, 0, sizeof(z));
      frr(i,1,R+1) frr(j,1,C+1)
      {
         x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1]+(w[i-1][j-1]-'0')*(j-1);
         y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1]+(w[i-1][j-1]-'0')*(i-1);
         z[i][j]=z[i-1][j]+z[i][j-1]-z[i-1][j-1]+w[i-1][j-1]-'0';
      }
      
      int found=-1;
      for(s=(R<?C)+1; s>=3 && found==-1; s--)
         for(i=0; i<=R-s && found==-1; i++)
            for(j=0; j<=C-s && found==-1; j++)
            {
               long long mass=z[i+s][j+s]-z[i][j+s]-z[i+s][j]+z[i][j]-(w[i][j]-'0')-(w[i+s-1][j]-'0')-(w[i][j+s-1]-'0')-(w[i+s-1][j+s-1]-'0');
               long long mx=x[i+s][j+s]-x[i][j+s]-x[i+s][j]+x[i][j]-(w[i][j]-'0')*j-(w[i+s-1][j]-'0')*j-(w[i][j+s-1]-'0')*(j+s-1)-(w[i+s-1][j+s-1]-'0')*(j+s-1);
               long long my=y[i+s][j+s]-y[i][j+s]-y[i+s][j]+y[i][j]-(w[i][j]-'0')*i-(w[i+s-1][j]-'0')*(i+s-1)-(w[i][j+s-1]-'0')*i-(w[i+s-1][j+s-1]-'0')*(i+s-1);
               if(mass*(j+j+s-1)==mx*2 && mass*(i+i+s-1)==my*2)
                  found=s;
            }
      
      if(found==-1)
         printf("Case #%d: IMPOSSIBLE\n", t);
      else
         printf("Case #%d: %d\n", t, found);
   }
   
   return 0;
}
