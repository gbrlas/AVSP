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

    int n,m;
    ll a;
    scanf("%d%d%lld",&n,&m,&a);

    for(int x=0;x<=n;x++)for(int y=0;y<=m;y++){
      int vx=x;
      int vy=-y;

      for(int p=0;p<=n;p++)for(int q=0;q<=m;q++){
        int obs=vx*(q-y)-vy*p;
        if(obs<0)obs*=-1;
        if(obs==a){
          printf(" %d %d %d %d %d %d\n",x,0,0,y,p,q);
          goto aaa;
        }
      }

    }

    printf(" IMPOSSIBLE\n");
aaa:;

  }
  return 0;
}
