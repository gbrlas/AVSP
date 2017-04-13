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

ld r[2222];
ld x[2222],y[2222];

int rev[2222];

ld sq(ld x){return x*x;}

    int W,L;
    int n;
    bool found;
void f(int i,bool first){
  if(found)return;
  if(i==n){
    REP(j,n)printf(" %.8Lf %.8Lf",x[rev[j]],y[rev[j]]);
    printf("\n");
    found=true;
    return;
  }
  if(i==0 && first){
    x[0]=y[0]=0;
    f(1,false);
  }
  REP(j,10){
    x[i]=rand()%(W+1);
    y[i]=rand()%(L+1);
    bool ok=true;
    ld lst=0;
    int li=-1;
    REP(k,i){
      ld d = sq(x[i]-x[k])+sq(y[i]-y[k]);
      if(d<sq(r[k]+r[i])){ok=false;break;}
      if(d<lst || li==-1){lst=d;li=k;}
    }
    if(!ok)continue;
    if(i>0){
      lst=sqrt(lst);
      ld in=r[i]+r[li];
      in+=0.001;
      ld dx = ((x[i]-x[li])/lst)*in;
      ld dy = ((y[i]-y[li])/lst)*in;
      x[i]=x[li]+dx;
      y[i]=y[li]+dy;
    }      
    ok=true;
    REP(k,i)
      if(sq(x[i]-x[k])+sq(y[i]-y[k]) <= sq(r[k]+r[i])){ok=false;break;}
    if(ok)f(i+1,false);
  }
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    scanf("%d%d%d",&n,&W,&L);
    REP(i,n)scanf("%Lf",&r[i]);
    pair<ld, int> p[2222];
    REP(i,n)p[i]=make_pair(r[i],i);
    sort(p,p+n);
    reverse(p,p+n);
    REP(i,n){
      r[i]=p[i].first;
      rev[p[i].second]=i;
    }
    do{
    found=false;
    f(0,true);
    }while(!found);
  }
  return 0;
}
