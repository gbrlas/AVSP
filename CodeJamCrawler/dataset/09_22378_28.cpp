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

    int x[5],y[5],r[5],n;

bool isin(int a, int b){
  if(r[b]>r[a])return false;
  return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=(r[a]-r[b])*(r[a]-r[b]);
}

void rem(int z){
  x[z]=x[2];
  y[z]=y[2];
  r[z]=r[2];
  n--;
}

double get(int a, int b){
  return (sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]))+r[a]+r[b])/2.0;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    scanf("%d",&n);
    REP(i,n)scanf("%d%d%d",&x[i],&y[i],&r[i]);
    if(isin(0,1))rem(1);
    else if(isin(1,0))rem(0);
    else if(isin(0,2))rem(2);
    else if(isin(2,0))rem(0);
    else if(isin(1,2))rem(2);
    else if(isin(2,1))rem(1);
    double ans=0;
    if(n==1)ans=r[0];
    if(n==2)ans=max(r[0],r[1]);
    if(n==3){
      double p=max(get(0,1),(double)r[2]);
      double q=max(get(0,2),(double)r[1]);
      double u=max(get(1,2),(double)r[0]);
      ans=min(p,min(q,u));
    }
    printf("Case #%d: %.9lf\n",_case,ans);

  }
  return 0;
}
