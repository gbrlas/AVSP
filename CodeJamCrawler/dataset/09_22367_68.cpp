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

int w,q;
char a[55][55];

const int lim=400;
string b[20][20][lim];
int upd[20][20][lim];

int zx[16]={1,1,1,0,0,0,-1,-1,-1,0,0,0,1,0,-1,0};
int zy[16]={0,0,0,1,1,1,0,0,0,-1,-1,-1,0,1,0,-1};
int dx[16]={1,2,1,1,0,-1,-1,-2,-1,-1,0,1,0,0,0,0};
int dy[16]={-1,0,1,1,2,1,1,0,-1,-1,-2,-1,0,0,0,0};
inline int aa(int x){return x<0?-x:x;};
inline char tov(int c){aa(c)+'0';}

void cmp(string &a, string &b){
  if(a.size()==0) a = b;
  else if(b.size()!=0){
    if(b.size()<a.size())a=b;
    else if(b.size() == a.size() && b<a)a=b;
  }

}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:\n",_case);
    scanf("%d%d",&w,&q);
    REP(i,w)scanf("%s",a[i]);
    REP(i,w)REP(j,w)REP(k,lim)b[i][j][k]="";
    const int plus=200;
    REP(i,w)REP(j,w)REP(k,lim)upd[i][j][k]=111111;
    REP(i,w)REP(j,w)
      if(a[i][j]>='0' && a[i][j]<='9'){
        b[i][j][(a[i][j]-'0')+plus]=a[i][j];
        upd[i][j][(a[i][j]-'0')+plus]=0;
      }
    REP(ppp,200){
      REP(y,w)REP(x,w)REP(k,lim)if(upd[y][x][k]==ppp){REP(d,16){        
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0||nx>=w||ny<0||ny>=w)continue;
        int nxx=x+zx[d];
        int nyy=y+zy[d];
        if(nxx<0 || nxx>=w || nyy<0||nyy>=w)continue;
        int val=a[ny][nx]-'0';
        if(a[nyy][nxx]=='-')val*=-1;
        if(k+val>=lim || k+val < 0) continue;
        int nval=k+val;
        string ns=b[y][x][k]+a[nyy][nxx];
        ns+=a[ny][nx];
        if(b[ny][nx][nval].size()==0 || (ns.size() < b[ny][nx][nval].size() || (b[ny][nx][nval].size()==ns.size() && ns<b[ny][nx][nval])))
          b[ny][nx][nval] = ns;
          upd[ny][nx][nval]=min(upd[ny][nx][nval],ppp+1);
      }}
      
    }
    REP(i,q){
      int v;scanf("%d",&v);
      string ans;
      REP(y,w)REP(x,w)
        cmp(ans,b[y][x][v+plus]);
      cout<<ans<<endl;
    }
  }
  cerr<<"ok"<<endl;
  return 0;
}
