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

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    double x,s,r,t; int n;
    cin>>x>>s>>r>>t>>n;
    int sum=0;
    vector<pair<double, int> > v;
    REP(i,n){
      int b,e;double w;
      cin>>b>>e>>w;
      v.push_back(make_pair(w,e-b));
      sum += e-b;
    }
    v.push_back(make_pair(0,x-sum));
    sort(v.begin(),v.end());
    double res=0;
    REP(i,(int)v.size()){
      double rt = (double)v[i].second / (double)(v[i].first + r);
      rt = min(rt, t);
      double rl = rt * (double)(v[i].first + r);
      t -= rt;
      res += rt;
      res += ((double)v[i].second - rl) / (double)(v[i].first + s);
    }
    printf(" %.15lf\n",res);
  }
  return 0;
}
