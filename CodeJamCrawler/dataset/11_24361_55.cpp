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

char a[111][111];
int n;

double wp(int team, int ign){
  int pl, won;
  pl=won=0;
  REP(i,n){
    if(i==ign)continue;
    if(a[team][i]=='.')continue;
    pl++;
    if(a[team][i]=='1')won++;
  };
  return won/(double)pl;
};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    scanf("%d",&n);
    REP(i,n)scanf("%s",a[i]);
    double c1[111];
    REP(i,n)c1[i]=wp(i,-1);
    double c2[111];
    REP(i,n){
      c2[i]=0;
      int pl=0;
      REP(j,n)if(a[i][j]!='.'){pl++;c2[i]+=wp(j,i);}
      c2[i]/=pl;
    }
    double c3[111];
    REP(i,n){
      c3[i]=0;
      int pl=0;
      REP(j,n)if(a[i][j]!='.'){pl++;c3[i]+=c2[j];}
      c3[i]/=pl;
    };printf("\n");
    REP(i,n)printf("%.50lf\n",0.25 * c1[i] + 0.5 * c2[i] + 0.25 * c3[i]);
  }
  return 0;
}
