#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOREACH(a,n) for (__typeof(n.begin())a=n.begin();a!=n.end();++a)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define FORD(i,a,b) for (int i=(a);i>=(b);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define ALL(x) x.begin(),x.end()
#define CLR(t) memset(t,0,sizeof(t));

const int N = 100007;

int tfu[N];

int find(int x){
  int y=x, z;
  while(tfu[y]>=0)
    y=tfu[y];
  while(tfu[x]>=0){
    z=x;
    x= tfu[x];
    tfu[z] = y;
  }
  return y;
}

void join(int x,int y){
  x = find(x);
  y = find(y);
  if(tfu[x] != tfu[y]){
    if(tfu[x] < tfu[y])
      tfu[y] = x;
    else
      tfu[x] = y;
  }
  else{
    tfu[y] = x;
    tfu[x] --;
  }
}

const int INF = 7000000;
const int M = 107;

int alt[M][M];
char s[N];

int fromxy(int h, int w){
  return h*M + w;
}

int mh[] = {-1, 0, 0, 1},
    mw[] = {0, -1, 1, 0};
//North, West, East, South.


int main()
{
  int D,h,w;
  scanf("%d",&D);
  FOR(I,1,D){
    scanf("%d %d",&h,&w);
    REP(i,h){
      REP(j,w)
        scanf("%d",&alt[i][j]);
    }
    REP(i,M*M){
      tfu[i] = -1;
      s[i] = '#';
    }
    REP(i,h)
      REP(j,w){
        int aw=INF;
        REP(kier, 4){
          int hh=i+mh[kier], ww = j+mw[kier];
          if(0<=hh && hh<h && 0<=ww && ww<w && alt[hh][ww] < aw)
            aw = alt[hh][ww];
        }
        if (aw < alt[i][j]){//not sink
          REP(kier, 4){
            int hh=i+mh[kier], ww = j+mw[kier];
            if(0<=hh && hh<h && 0<=ww && ww<w && alt[hh][ww] == aw){//w dobrej kolejnosci
/*              cout<<"--: "<<i<<" "<<j<<": "<<hh<< " "<<ww<<endl;
              cout<<fromxy(i,j)<<" "<< fromxy(hh,ww)<<endl;*/
              join(fromxy(i,j), fromxy(hh,ww));
              break;
            }
          }
        }
      }
    printf("Case #%d:\n",I);    
    char lit = 'a';
    REP(i,h){
      REP(j,w){
        int index = find(fromxy(i,j));
        if(s[index] == '#')
          s[index] = lit++;
        printf("%c ", s[index]);
      }
      printf("\n");
    }
  }
	return 0;
}
