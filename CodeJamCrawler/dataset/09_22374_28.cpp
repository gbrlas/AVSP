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

vector<int> a[111];

int inter(int x, int y,int k){
  int M=a[x][0]-a[y][0];
  int m=M;
  REP(i,k){
    int d=a[x][i] - a[y][i];
    M=max(M,d);
    m=min(m,d);
  }
  if(M>0 && m>0)return false;
  if(M<0 && m<0)return false;
  return true;
}

bool ins[55][55];
int n,all;

int p[1<<16];
int q[1<<16];

bool isok(int m){
  REP(i,n)
    if(m&(1<<i))
      for(int j=i+1;j<n;j++)
        if(m&(1<<j))
          if(ins[i][j])return false;
  return true;

}

int f(int m){
  if(p[m]!=-1)return p[m];
  if(m==all){
  //  printf("zde\n");
    return 0;
  }
  p[m] = 100;
  int mm=0,ls;
  REP(i,n)
    if((m&(1<<i))==0){mm|=(1<<i);ls=i;}
  for(int s=mm;s!=0;s=(s-1)&mm)
    if(q[s] && (s&(1<<ls))){
//      printf("%d %d %d %d %d\n",n,m,s,m^s,mm);
      p[m] = min(p[m],1+f(m^s));
    }
  return p[m];
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    int k;scanf("%d%d",&n,&k);
    REP(i,n){
      a[i].clear();
      REP(j,k){
        int x;scanf("%d",&x);
        a[i].push_back(x);
      }
    }
    REP(i,n)REP(j,n)ins[i][j]=inter(i,j,k);    
    REP(i,(1<<n))q[i]=isok(i);    
    memset(p,-1,sizeof(p));
    all=(1<<n)-1;
    printf("Case #%d: %d\n",_case,f(0));

  }
  return 0;
}
