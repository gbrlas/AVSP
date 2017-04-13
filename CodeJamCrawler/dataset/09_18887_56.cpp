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

#define   SWAP(X,Y)   { char __TMP__=X; X=Y; Y=__TMP__; }
int nextPermutation(char *p, char n)
{
   int i, j, r=0;
   for(i=n-2; i>=0 && p[i]>=p[i+1]; i--);
   if(i!=-1)
   {
      for(j=n-1; p[j]<=p[i]; j--);
      SWAP(p[i], p[j]);
      r=1;
   }
   for(j=(i+n)>>1; j>i; j--)
      SWAP(p[j], p[i+n-j]);
   return r;
}

int main()
{
   int T, t, n, i, j;
   char s[1024];
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%s", s);
      n=strlen(s);
      if(nextPermutation(s, n))
      {
         printf("Case #%d: %s\n", t, s);
      }
      else
      {
         j=1<<30;
         fr(i,n) if(s[i]!='0') j<?=s[i];
         for(i=0; s[i]!=j; i++);
         if(i>0) SWAP(s[i], s[0])
         s[n]='0';
         s[++n]=0;
         sort(s+1, s+n);
         printf("Case #%d: %s\n", t, s);
      }
   }
   
   return 0;
}
