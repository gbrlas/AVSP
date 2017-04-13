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

char L[32];
vector<string> s;
vector<int> p;

void ask(vector<int> z, int guessed, int g)
{
   vector< pair<string,int> > h;
   int i, j, k, mask=0;
   
   if(z.size()==1 || g>=27) return;
   
   fr(i,z.size())
   {
      h.pb(make_pair(string(s[z[i]].size(), ' '),z[i]));
      fr(j,h[i].first.size())
      {
         if(1<<s[z[i]][j]-'a'&guessed)
            h[i].first[j]=s[z[i]][j];
         mask|=1<<s[z[i]][j]-'a';
      }
   }
   
   for(; !(1<<L[g]-'a'&mask); g++);
   // printf("%d %c\n", g, L[g]);
   fr(i,h.size())
   {
      int bad=1;
      fr(j,h[i].first.size())
         if(s[z[i]][j]==L[g])
         {
            h[i].first[j]=L[g];
            bad=0;
         }
      // printf("%s\n", h[i].first.c_str());
      p[z[i]]+=bad;
   }
   
   sv(h);
   for(i=0; i<h.size(); i=j)
   {
      for(j=i+1; j<h.size() && h[j].first==h[i].first; j++);
      vector<int> y;
      frr(k,i,j) y.pb(h[k].second);
      ask(y, guessed|1<<L[g]-'a', g+1);
   }
}

int main()
{
   int T, t, N, M, i, j, k, w;
   char x[16];
   vector<int> z;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &N, &M);
      s.clear();
      fr(i,N)
      {
         scanf("%s", x+1);
         x[0]='{';
         s.pb(x);
      }
      printf("Case #%d:", t);
      fr(i,M)
      {
         scanf("%s", L+1);
         L[0]='{';
         p.clear();
         z.clear();
         fr(j,N)
         {
            p.pb(0);
            z.pb(j);
         }
         
         ask(z, 0, 0);
         k=-1;
         fr(j,N) if(p[j]>k)
         {
            k=p[j];
            w=j;
         }
         printf(" %s", s[w].c_str()+1);
      }
      printf("\n");
   }
   
   return 0;
}
