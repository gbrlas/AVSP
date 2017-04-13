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

int tx[2]={2,1};int ty[2]={1,2};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int h,w,r;
    scanf("%d%d%d",&h,&w,&r);
    bool oc[1000][1000];CLEAR(oc);
    int a[1000][1000];CLEAR(a);
    REP(i,r){
      int x,y;scanf("%d%d",&y,&x);
      oc[y][x]=true;
    }
    a[1][1]=1;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
      for(int k=0;k<2;k++)if(!oc[i+ty[k]][j+tx[k]]){
        a[i+ty[k]][j+tx[k]]+=a[i][j];
        a[i+ty[k]][j+tx[k]]%=10007;
      };

    }
    printf(" %d\n",a[h][w]%10007);

  }
  return 0;
}
