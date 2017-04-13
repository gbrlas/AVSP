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

ll a[2][2]={{3,5},{1,3}};
ll id[2][2]={{1,0},{0,1}};

struct M{
  ll a[2][2];
};

void po(int n, M *m){
  if(n==0){
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)m->a[i][j]=id[i][j];
  }else if(n==1){
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)m->a[i][j]=a[i][j];
  } else {
    M t;
    po(n/2,&t);
    M p;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
      p.a[i][j]=0;
      for(int k=0;k<2;k++)p.a[i][j]+=t.a[i][k]*t.a[k][j];
    }
    if(n%2){
      for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        m->a[i][j]=0;
        for(int k=0;k<2;k++)m->a[i][j]+=p.a[i][k]*a[k][j];
      }
    } else {
      for(int i=0;i<2;i++)for(int j=0;j<2;j++)m->a[i][j]=p.a[i][j];
    }
  }
  for(int i=0;i<2;i++)for(int j=0;j<2;j++)m->a[i][j]%=1000;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int n;scanf("%d",&n);
    ld r=sqrtl(5)+(ld)3;
    int ans=0;

    if(n<5){
      ld an=1;
      for(int i=0;i<n;i++){
        an*=r;
      }
      ans=an;
      printf(" %03d\n",ans);
    } else {
      M m;
      po(n,&m);
      ll v = (ll)2*m.a[1][1];
      //printf("%lld %lld\n%lld %lld\n",m.a[0][0],m.a[0][1],m.a[1][0],m.a[1][1]);
      v%=1000;
      ans=v-1;
      ans+=1000;
      ans%=1000;
      printf(" %03d\n",ans);
    }


  }
};
