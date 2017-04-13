#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

char tiles[51][51];


void run(int casenr) {
  
  memset(tiles, '\0', sizeof(tiles));
  int r,c;
  scanf("%d %d", &r, &c);
  REP(i,r) scanf("%s", tiles[i]);

  REP(i,r) {
    REP(j,c) { 
      if (tiles[i][j] == '#' &&
	  tiles[i][j+1] == '#' &&
	  tiles[i+1][j] == '#' &&
	  tiles[i+1][j+1] == '#') {
	tiles[i][j] = tiles[i+1][j+1] = '/';
	tiles[i][j+1] = tiles[i+1][j] = '\\';
      }  else if (tiles[i][j] == '#') {
	printf("Case #%d:\n",casenr); printf("Impossible"); puts("");
	return;
      } 
    }
  }

 
  printf("Case #%d:\n",casenr);
  REP(i,r) { REP(j,c) printf("%c", tiles[i][j]); printf("\n"); }
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
