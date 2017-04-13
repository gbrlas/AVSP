#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

map<string,int> m;

struct S{
  int from,to,c;
};

int getc(string s){
  if(m.count(s))return m[s];
  int l=m.size();m[s]=l;return l;
}

int main(){

  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int n;scanf("%d",&n);
    S o[50];m.clear();
    REP(i,n){
      char ss[50];S s;
      scanf("%s %d %d",ss,&s.from,&s.to);
      s.c=getc(ss);
      o[i]=s;
    }
    bool p[10100];
    bool cu[1000];
    int ans=1000000;
    REP(i,(1<<n)){
      CLEAR(cu);
      int bs=0;
      REP(j,n)if((i&(1<<j))){cu[o[j].c]=true;bs++;}
      if(bs>=ans)continue; 
      int cls=0;REP(j,n)if(cu[j])cls++;
      if(cls>3)continue;
      CLEAR(p);
      REP(j,n)if((i&(1<<j))){
        for(int k=o[j].from;k<=o[j].to;k++)p[k]=true;
      }
      bool ok=true;
      for(int j=1;j<=10000;j++)if(!p[j]){ok=false;break;}
      if(ok)ans=bs;

    }
    if(ans>1000)printf(" IMPOSSIBLE\n");
    else printf(" %d\n",ans);
    
  }
  return 0;
}
