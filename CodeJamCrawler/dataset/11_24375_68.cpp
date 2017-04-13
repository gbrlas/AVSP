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

int gcd(int a, int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int p(vector<int> &v){
  bool ch=false;
  int l=v.size();
  int res=0;
  int mod[1010];
  CLEAR(mod);
  ll val=0;
  bool first=true;
  int mp[1111];CLEAR(mp);
  for(int j=0;j<l;j++){
    int prod = v[j];
    bool ok=true;
    for(int i=2;i<=l;i++){
      int tms=0;
      while(prod % i ==0){
        prod/=i;
        tms++;
      }
      if(tms>mp[i]){
        ok=false;
        mp[i]=tms;
      }
    }

    if(!ok || j==0)res++;
    /*    bool ss=false;
    do{
      ch=false;
      REP(i,j+1)if(first || mod[v[i]]!=0){
        ch=true;ss=true;
        int plus = v[i] - mod[v[i]];
        val+=plus;
        for(int k=1;k<=l;k++)
          mod[k] = (mod[k] + plus)%k;
        first = false;
        break;
      }
    }while(ch);
    cout<<v[j]<<" "<<val<<" "<<ss<<endl;
    
    if(ss)res++;*/
  }
  return res;
}

bool isp[1111];

int main(){
  CLEAR(isp);
  for(int i=2;i<=1111;i++){
    isp[i]=true;
    for(int j=2;j*j<=i;j++)
      if(i%j==0){
        isp[i]=false;
        break;
      }
  }
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int n;cin>>n;
    vector<int> a,b;
    bool pres[1111];
    CLEAR(pres);
    for(int i=1;i<=n;i++){
      a.push_back(i);
      if(isp[i]){
        int val=i;
        while(val*i<=n)val*=i;
        pres[val]=true;
        b.push_back(val);
      }
    }
    for(int i=1;i<=n;i++)
      if(!pres[i])b.push_back(i);
    cout<<" "<<p(a)-p(b)<<endl;
  }
  return 0;
}
