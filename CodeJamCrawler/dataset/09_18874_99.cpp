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

int w[1024][32];

int main()
{
   char s[1024], u[]="welcome to code jam";
   int T, t, n, i, j, k;
   
   for(scanf("%d\n", &T), t=1; t<=T; t++)
   {
      fgets(s, 1024, stdin);
      n=strlen(s);
      
      memset(w, 0, sizeof(w));
      
      for(i=0; i<n; i++)
         for(j=0; j<19; j++) if(i>=j)
            if(i==0)
            {
               if(s[0]==u[0])
               {
                  w[0][0]=1;
               }
            }
            else if(s[i]==u[j])
            {
               w[i][j]=(w[i-1][j]+(j>0?w[i-1][j-1]:1))%10000;
            }
            else
            {
               w[i][j]=w[i-1][j];
            }
      
      printf("Case #%d: %04d\n", t, w[n-1][18]);
   }
   
   return 0;
}
