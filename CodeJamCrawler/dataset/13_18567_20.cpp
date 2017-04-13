#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

#define  CTRL(xx,yy) (xx>=1 && xx<=N && yy>=1 && yy<=N && d[xx][yy]==0)
#define  wait system("PAUSE")
#define  INF (long long)(1e6)
#define  mkp make_pair
#define  pb push_back
#define  f first
#define  s second

using namespace std;

typedef long long ll;

ll N,M;
vector < ll > V;

void init(){
  ll i,j,L;
  bool ctrl;
  char S[500];
  for(i=1; i<=INF; i++){
    sprintf(S,"%lld\0",i);
    L=strlen(S)-1;
    ctrl=1;
    for(j=0; j<=L && ctrl; j++,L--)
      if(S[j]!=S[L])
        ctrl=0;
    if(!ctrl) continue;
    sprintf(S,"%lld\0",i*i);
    L=strlen(S)-1;
    ctrl=1;
    for(j=0; j<=L && ctrl; j++,L--)
      if(S[j]!=S[L])
        ctrl=0;
    if(!ctrl) continue;
    if(ctrl) V.pb(i*i);
  }
}

int coz(){
  int i=0,say=0;
  while(V[i]<N) i++;
  while(V[i]<=M) i++,say++;
  return say;
}

int main(){
  int t,Test_Case;
  init();
  scanf("%d",&Test_Case);
  for(t=1; t<=Test_Case; t++){
    scanf("%lld%lld",&N,&M);
    printf("Case #%d: %d\n",t,coz());
  }
	return 0;
}
