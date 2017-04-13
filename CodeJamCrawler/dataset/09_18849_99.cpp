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

int x[8192][16], y[16];

int main()
{
   int L, D, N, i, j, k;
   char s[1025];
   
   scanf("%d %d %d", &L, &D, &N);
   
   memset(x, 0, sizeof(x));
   for(i=0; i<D; i++)
   {
      scanf("%s", s);
      for(j=0; j<L; x[i][j]=1<<s[j]-'a', j++);
   }
   
   for(int T=1; T<=N; T++)
   {
      scanf("%s", s);
      
      memset(y, 0, sizeof(y));
      for(i=j=0; j<L; i++, j++)
         if(s[i]=='(')
            for(i++; s[i]!=')'; y[j]|=1<<s[i]-'a', i++);
         else
            y[j]=1<<s[i]-'a';
            
      for(k=i=0; i<D; i++)
      {
         for(j=0; j<L && (y[j]&x[i][j]); j++);
         k+=j==L;
      }
      
      printf("Case #%d: %d\n", T, k);
   }
   
   return 0;
}
