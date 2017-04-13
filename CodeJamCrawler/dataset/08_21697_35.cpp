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

int h,w;
int a[12][1<<10];
char c[15][15];

bool isok(int m){
  REP(j,w-1)if((m&(1<<j)) && (m&(1<<(j+1))))return false;
  return true;
}

int f(int r, int m){
  if(a[r][m]!=-1)return a[r][m];
  if(!isok(m))return a[r][m]=0;
  REP(i,w)if(c[r][i]=='x' && (m&(1<<i))) return a[r][m]=0;
  if(r==0){
    if(!isok(m)){a[r][m]=0;return 0;}
    int b=0;
    int mm=m;
    while(m>0){b+=m%2;m/=2;};
    a[r][mm]=b;
    return b;
  }
  a[r][m]=0;
  REP(i,(1<<w)){
    bool ok=true;
    if(!isok(i))continue;
    REP(j,w-1)if((m&(1<<j)) && (i&(1<<(j+1)))){ok=false;break;}
    if(!ok)continue;
    REP(j,w-1)if((i&(1<<j)) && (m&(1<<(j+1)))){ok=false;break;}
    if(!ok)continue;
    a[r][m]=max(a[r][m],f(r-1,i));
  }
  int mm=m;
  while(m>0){a[r][mm]+=m%2;m/=2;}
  return a[r][mm];
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    scanf("%d%d",&h,&w);
    REP(i,h)scanf("%s",c[i]);
    int ma=0;
    memset(a,-1,sizeof(a));
    REP(i,(1<<w))ma=max(ma,f(h-1,i));
//    REP(i,h)REP(j,(1<<w))printf("%d %d %d\n",i,j,f(i,j));
    printf(" %d\n",ma);

  }
  return 0;
}
