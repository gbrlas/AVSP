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
    int n; ld d;
    cin>>n>>d;
    ld cnt[333], pos[333];
    REP(i,n){
      cin>>pos[i]>>cnt[i];
    };
    ld l=0,r=100000000;
    r*=r;
    REP(i,5000){
      ld mid = (l+r)/(ld)2.0;
      bool ok = true;
      ld last = pos[0] - mid - d - 1;
      REP(j,n){
        ld left = max(last + d, pos[j] - mid);
        ld right = left + d * (cnt[j]-(ld)1);
        if(right > pos[j] + mid)ok=false;
        last = right;
      }
      if(ok){
        r = mid;
      }else l=mid;
    }
    printf(" %.50Lf\n",l);
  }
  return 0;
}
