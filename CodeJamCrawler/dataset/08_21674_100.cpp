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

bool c[2020][2020][2];
bool s[2020];
bool st[2020];

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    int n,m;
    scanf("%d%d",&n,&m);
    memset(c,0,sizeof(c));
    CLEAR(s);CLEAR(st);
    for(int i=0;i<m;i++){
      int t;
      scanf("%d",&t);
      for(int j=0;j<t;j++){
        int x,y;scanf("%d %d",&x,&y);
        c[i][x-1][y]=true;
      };
    }

    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        if(s[j]) continue;
        bool ok=false;
        for(int k=0;k<n;k++)
          if(st[k]==0 && c[j][k][0]){ok=true;break;}
        if(!ok){
          int x=-1;
          for(;x<n;x++)if(st[x]==0 && c[j][x][1]) break;
          if(x==n){printf(" IMPOSSIBLE\n"); goto aaa;}
          st[x]=1;
          for(int k=0;k<m;k++) if(c[k][x][1])s[k]=true;
        }
      }
    }
   
   for(int i=0;i<n;i++) printf(" %d",st[i]);
  printf("\n"); 

aaa:;


  }


  return 0;
}
