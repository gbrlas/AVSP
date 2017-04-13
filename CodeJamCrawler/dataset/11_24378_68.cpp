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

const int L=2111111;
bool isc[L];

int main(){
  CLEAR(isc);
  for(int i=2;i<L;i++)
    if(!isc[i])
      for(int j=2*i;j<L;j+=i)
        isc[j]=true;
  
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    ll n;cin>>n;
    ll res=0;
    if(n>1)res++;
    for(int i=2;i<=n;i++){
      if(!isc[i]){
        ll val=i;
        ll pr=i;
        while(val*pr<=n){
          val*=pr;
          res++;
        }
        if(val == pr)break;
      }
    }
    cout<<" "<<res<<endl;
  }
  return 0;
}
