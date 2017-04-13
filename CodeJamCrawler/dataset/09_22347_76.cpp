#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long double ld;
typedef long long ll;
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i) 

int a[111][111];
int dr[111][111];

int par[111*111];
int let[111*111];

int find(int v){
  if(par[v]==v)return v;
  return par[v]=find(par[v]);
}

void un(int a, int b){
  int pa=find(a),pb=find(b);
  if(pa!=pb)par[pa]=pb;
}

int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};

int main(){
  int ttt;scanf("%d",&ttt);
  REP(xxx,ttt){
    memset(dr,-1,sizeof(dr));
    memset(let,-1,sizeof(let));
    int r,c;scanf("%d%d",&r,&c);
    REP(i,r)REP(j,c){
      scanf("%d",&a[i][j]);
      dr[i][j]=i*c+j;
      par[i*c+j]=i*c+j;
    }
    REP(y,r)REP(x,c){
      int cv=a[y][x];
      int fv,fd;
      fv=fd=-1;
      REP(d,4){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0 || nx>=c || ny<0 || ny>=r)continue;
        if(a[ny][nx] >= cv)continue;
        if(fd == -1 || a[ny][nx] < fv){
          fv = a[ny][nx];
          fd = d;
        }
      }
      if(fd!=-1)
        un(dr[y][x], dr[y+dy[fd]][x+dx[fd]]);
    }
    printf("Case #%d:\n", xxx+1);
    int lets=0;
    REP(y,r){REP(x,c){
      if(x!=0)printf(" ");
      int p=find(dr[y][x]);
      if(let[p]==-1)let[p]=lets++;
      printf("%c",let[p]+'a');
    } printf("\n");}
  }
}
