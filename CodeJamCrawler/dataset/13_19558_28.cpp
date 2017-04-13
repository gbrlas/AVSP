#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
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

int main()
{
   int T, t;
   map<long long, long long> en, ex;
   long long N, M, a, b, c, tot, i, j, k, tot2;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      tot=tot2=0;
      scanf("%lld %lld", &N, &M);
      en.clear();
      ex.clear();
      for(i=0; i<M; i++)
      {
         scanf("%lld %lld %lld", &a, &b, &c);
         en[a]+=c;
         ex[b]+=c;
         tot+=(N+(N+(b-a)+1))*(b-a)/2*c;
      }
      
      for(typeof(ex.end()) p=ex.begin(); p!=ex.end(); p++)
         for(typeof(en.rend()) q=en.rbegin(); q!=en.rend(); q++)
            if(p->second>0 && q->second>0 && q->first<=p->first)
            {
               c=p->second<?q->second;
               p->second-=c;
               q->second-=c;
               a=q->first;
               b=p->first;
               tot2+=(N+(N+(b-a)+1))*(b-a)/2*c;
            }
               
      printf("Case #%d: %lld\n", t, tot2-tot);
   }
   
   return 0;
}
