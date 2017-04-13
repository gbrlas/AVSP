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

char s[55][55];
int n,res;

void swap(int a,int b){
  res++;
  REP(i,n)
    swap(s[a][i],s[b][i]);
}

bool can(int r, int k){
  for(int i=k+1;i<n;i++)
    if(s[r][i]=='1')return false;
  return true;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    scanf("%d",&n);
    REP(i,n)scanf("%s",s[i]);
    res=0;
    REP(i,n){
      if(can(i,i))continue;
      for(int j=i+1;j<n;j++){
        if(can(j,i)){
          for(int k=j-1;k>=i;k--)swap(k,k+1);
          break;
        }
      }
    }
    printf("Case #%d: %d\n",_case,res);

  }
  return 0;
}
