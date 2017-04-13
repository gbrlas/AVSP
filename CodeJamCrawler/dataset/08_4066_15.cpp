#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

static char b[12][12];
static int R,C;

typedef pair<int,int> Pr;

int dp(int r,int under,map<Pr,int> &tbl);
void rio(int i,int m,int r,int curr,map<Pr,int> &tbl,vector<bool> &use,int &max_p)
{
   int tmp=m+dp(r-1,curr,tbl);
   if (tmp>max_p)
      max_p=tmp;

   for (; i<C; ++i)
      if (use[i] && b[r][i]=='.')
         rio(i+2,m+1,r,curr|(1<<i),tbl,use,max_p);
}
int dp(int r,int under,map<Pr,int> &tbl) 
{
   if (r==-1)
      return 0;

   map<Pr,int>::iterator it;
   Pr key(r,under);
   if ((it=tbl.find(key))!=tbl.end())
      return it->second;
   
   vector<bool> use(C,true);
   int i,j;
   for (i=0; i<C;++i)
      if (under&(1<<i)) {
         if (i-1>=0) use[i-1]=false;
         if (i+1<C) use[i+1]=false;
      }
   int max_p=0;
   rio(0,0,r,0,tbl,use,max_p);
   tbl[key]=max_p;
   return max_p;
}
int main()
{
   int i,j,k,n;
   int t,T;
   for (cin>>T,t=1;t<=T;++t) {
      cin>>R>>C;
      for (i=0;i<R;++i)
         cin>>b[i];

      map<Pr,int> tbl;
      printf("Case #%d: %d\n",t,
             dp(R-1,0,tbl));
   }
}
