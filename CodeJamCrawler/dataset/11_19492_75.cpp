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

int main()
{
   int N, T, t, i, j, k, b, Ot=0, Bt=0, Ob=1, Bb=1;
   char w[2];
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      Ot=0, Bt=0, Ob=1, Bb=1;
      for(scanf("%d", &N); N--; )
      {
         scanf("%s %d", w, &b);
         if(w[0]=='O')
         {
            Ot=(Ot+abs(b-Ob)+1)>?(Bt+1);
            Ob=b;
         }
         else
         {
            Bt=(Bt+abs(b-Bb)+1)>?(Ot+1);
            Bb=b;
         }
      }
      
      printf("Case #%d: %d\n", t, Ot>?Bt);
   }
   
   return 0;
}
