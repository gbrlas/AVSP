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

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    int n; scanf("%d",&n);
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
      int x;scanf("%d",&x); v1.push_back(x);
    }
    for(int i=0;i<n;i++){
      int x; scanf("%d",&x); v2.push_back(x);
    }
    vector<int> p;
    for(int i=0;i<n;i++)p.push_back(i);

    ll mv=0;
    REP(i,n) mv+=(ll)v1[i]*(ll)v2[i];

    do{
      ll cv=0;
      REP(i,n) cv+=(ll)v1[p[i]]*(ll)v2[i];
      if(cv<mv)mv=cv;
    }while(next_permutation(p.begin(),p.end()));
    printf(" %lld\n",mv);
  }


  return 0;
}
