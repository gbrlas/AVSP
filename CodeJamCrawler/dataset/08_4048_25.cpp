#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> Pr;

static const int inf=100000;
int rio(int i,int v,map<Pr,int> &tbl,vector<Pr> &tree)
{
   map<Pr,int>::iterator it;
   Pr key(i,v);
   if ((it=tbl.find(key))!=tbl.end())
      return it->second;

   int r=inf;
   if (tree[i].second==-1) {
      // child
      if (tree[i].first==v)
         r=0;
   } else {
      int add;
      if (tree[i].first==1 || tree[i].second==1) {
         // and
         add=0;
         if (tree[i].first==0)
            add=1;
         if (v==1)
            r=min(r,rio(2*i,1,tbl,tree)+rio(2*i+1,1,tbl,tree)+add);
         else {
            r=min(r,rio(2*i,0,tbl,tree)+rio(2*i+1,1,tbl,tree)+add);
            r=min(r,rio(2*i,0,tbl,tree)+rio(2*i+1,0,tbl,tree)+add);
            r=min(r,rio(2*i,1,tbl,tree)+rio(2*i+1,0,tbl,tree)+add);
         }
      }
      if (tree[i].first==0 || tree[i].second==1) {
         // or
         add=0;
         if (tree[i].first==1)
            add=1;
         if (v==0)
            r=min(r,rio(2*i,0,tbl,tree)+rio(2*i+1,0,tbl,tree)+add);
         else {
            r=min(r,rio(2*i,0,tbl,tree)+rio(2*i+1,1,tbl,tree)+add);
            r=min(r,rio(2*i,1,tbl,tree)+rio(2*i+1,1,tbl,tree)+add);
            r=min(r,rio(2*i,1,tbl,tree)+rio(2*i+1,0,tbl,tree)+add);
         }
      }
   }

   tbl[key]=r;
   return r;
}
int main()
{
   int t,T;
   for (cin>>T,t=1;t<=T;++t) {
      int i,j,n,v;
      cin>>n>>v;
      
      vector<Pr> tree;
      tree.push_back(Pr(-1,-1));
      for (i=0; i<(n-1)/2; ++i) {
         int g,c;
         cin>>g>>c;
         tree.push_back(Pr(g,c));
      }
      for (i=0; i<(n+1)/2; ++i) {
         cin>>j;
         tree.push_back(Pr(j,-1));
      }
      
      map<Pr,int> tbl;
      i=rio(1,v,tbl,tree);
      cout<<"Case #"<<t<<": ";
      if (i>=inf)
         cout<<"IMPOSSIBLE"<<endl;
      else
         cout<<i<<endl;
   }
}
