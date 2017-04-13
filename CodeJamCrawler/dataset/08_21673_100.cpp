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

bool c[120][12][2];

int bits(int x){
  int a=0;
  while(x!=0){
    a+=x%2;
    x/=2;
  }
  return a;
};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    int n,m;
    scanf("%d%d",&n,&m);
    memset(c,0,sizeof(c));
    for(int i=0;i<m;i++){
      int t;
      scanf("%d",&t);
      for(int j=0;j<t;j++){
        int x,y;scanf("%d %d",&x,&y);
        c[i][x-1][y]=true;
      };
    }

    int bs=-1;
  
    for(int i=0;i<(1<<n);i++){
      if (bs!= -1 && bits(i)>=bits(bs)) continue;
      
      for(int j=0;j<m;j++){
        bool ok =false;
        for(int k=0;k<n;k++){
          int p=0;
          if (i&(1<<k))p=1;
          if (c[j][k][p]){ ok = true;  break;}
        }
        if(!ok) goto aaa;
      }

    bs=i;
aaa:;
    }


    if(bs==-1)printf(" IMPOSSIBLE\n");
    else {
      for(int i=0;i<n;i++,bs/=2) printf(" %d",bs%2);
      printf("\n");
    }
  }


  return 0;
}
