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

int M,v;
int typ[100100],c[100100],val[100100];

int mp[100100][2];


int f(int v, int b){
  if(v>(M-1)/2){
    if(val[v]==b)return 0;
    return 10101;
  };
  if (mp[v][b]!=-1)return mp[v][b];
  int res=10101;
  if(b==1){
    if(typ[v]==1){
      res=f(2*v,1)+f(2*v+1,1);
      if (c[v])res=min(res,1+min(f(2*v,1),f(2*v+1,1)));
    }else{
      res=min(f(2*v,1),f(2*v+1,1));
      if(c[v])res=min(res,1+f(2*v,1)+f(2*v+1,1));
    }
  } else {
    if(typ[v]==0){
      res=f(2*v,0)+f(2*v+1,0);
      if(c[v])res=min(res,1+min(f(2*v,0),f(2*v+1,0)));
    }else{
      res=min(f(2*v,0),f(2*v+1,0));
      if(c[v])res=min(res,1+f(2*v,0)+f(2*v+1,0));
    }
  };


  return mp[v][b]=res;
};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    scanf("%d%d",&M,&v);
    for(int i=1;i<=(M-1)/2;i++) scanf("%d%d",&typ[i],&c[i]);
    for(int i=(M-1)/2+1;i<=M;i++)scanf("%d",&val[i]);
    memset(mp,-1,sizeof(mp));
    if(f(1,v)>10000)printf(" IMPOSSIBLE\n");
    else printf(" %d\n",f(1,v));
  }
  return 0; 
}
