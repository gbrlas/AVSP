#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
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

char s[1<<16], u[1<<10];

double ask(set<string> f, string s, int &L, double p)
{
   int i, j, k;
   for(; s[L]==' '; L++);
   for(i=L+1; s[i]==' '; i++);
   for(j=i; s[j]!=' ' && s[j]!=')'; j++);
   string u=s.substr(i, j-i);
   double v=atof(u.cs);
   for(; s[j]==' '; j++);
   if(s[j]==')')
   {
      L=j+1;
      return v*p;
   }
   for(i=j; s[j]!=' ' && s[j]!='('; j++);
   u=s.substr(i, j-i);
   
   for(; s[j]==' '; j++);
   double x=ask(f, s, j, p*v);
   for(; s[j]==' '; j++);
   double y=ask(f, s, j, p*v);
   L=j;
   for(; s[L]!=')'; L++);
   L++;
   
   return in(u,f)?x:y;
}

int main()
{
   int T, t, L, N, n, i, j, k;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d\n", &L);
      s[0]=0;
      fr(i,L)
      {
         j=strlen(s);
         gets(s+j);
      }
      
      printf("Case #%d:\n", t);
      
      scanf("%d\n", &N);
      fr(i,N)
      {
         scanf("%s %d", u, &n);
         set<string> f;
         fr(j,n)
         {
            scanf("%s", u);
            f.insert(u);
         }
         
         k=0;
         printf("%.7lf\n", ask(f, s, k, 1));
      }
   }
   
   return 0;
}
