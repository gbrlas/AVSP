#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>

#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int field[2][102][102];
void fill_field(int x1, int y1, int x2, int y2){
  if(x1 > x2) swap(x1, x2); 
  if(y1 > y2) swap(y1, y2);
  FOR(x, x1, x2+1) FOR(y, y1, y2+1) field[0][x][y] = 1;
}

void show(int cur, int r, int c){
  FOR(i, 1, r+1) {FOR(j, 1, c+1) cerr << field[cur&1][i][j]; cerr << endl;} cerr << endl;
}

int main(){
  int C;
  cin >> C;
  REP(case_no, C){
    memset(field, 0, sizeof(field));
    int R; cin >> R;
    int r(100), c(100);
    REP(i, R){
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      fill_field(x1, y1, x2, y2);
    }

    for(int ct = 0;; ct++){
      //      show(ct, 10, 10);
      bool isChanged(false);
      int current(ct & 1);
      int next(current ^ 1);
      FOR(x, 1, r+1) FOR(y, 1, c+1){
	if(!field[current][x][y] && field[current][x-1][y] && field[current][x][y-1]){
	  field[next][x][y] = 1;
	  isChanged = true;
	}
	else if(field[current][x][y] && (field[current][x-1][y] || field[current][x][y-1])){
	  field[next][x][y] = 1;
	  isChanged = true;
	}
	else 
	  field[next][x][y] = 0;
      }
      if(!isChanged){
	cout << "Case #" << case_no+1 << ": " << ct+1 << endl;
	break;
      }
    }
  }
  return 0;
}
