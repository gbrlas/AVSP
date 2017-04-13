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

bool x[10001][10001];
int d[10100],l[10100];

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    CLEAR(x);
    printf("Case #%d:",_case);
    int n;scanf("%d",&n);
    REP(i,n)scanf("%d%d",&d[i],&l[i]);
    int D;scanf("%d",&D);
    for(int j=n-1;j>=0;j--){
      int to = j;
      bool res=false;
      for(int i=j;i>=0;i--){
        int used = min(l[j],d[j]-d[i]);
        int upto = d[j]+used;
        if(l[i]<d[j]-d[i])continue;
        if(upto>=D)res=true;
        while(to<n){
          if(d[to]<=upto)res|=x[j][to++];
          else break;
        }
        x[i][j]=res;
      }
    }
    bool r=2*d[0]>=D;
    for(int i=1;i<n;i++)
      if(d[0]*2>=d[i])r|=x[0][i];
    if(r)printf(" YES\n");
    else printf(" NO\n");
  }
  return 0;
}
