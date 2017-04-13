#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()

//North, West, East, South
int dy[] = {-1, 0, 0, 1};
int dx[] = { 0,-1, 1, 0};

bool isOut(int y, int x, int H, int W){
  return y < 0 || x < 0 || y >= H || x >= W;
}

struct UnionFind{
  int dat[10001];
  UnionFind(){}
  void Init(int n){
    REP(i, n) dat[i] = i;
  }
  int parent(int ch){
    return ch == dat[ch] ? ch : parent(dat[ch]);
  }
  int set_union(int a, int b){
    a = parent(a);
    b = parent(b);
    return dat[min(a, b)] = dat[max(a, b)];
  }
};

int field[101][101];
int height[101][101];
char tab[10001];
int main(){
  int T;
  cin >> T;
  UnionFind union_find;
  REP(case_no, T){
    int H, W;
    cin >> H >> W;
    union_find.Init(H*W);
    REP(y, H) REP(x, W) {
      cin >> height[y][x];
      field[y][x] = y * W + x;
    }
    REP(y, H) REP(x, W){
      int flow_to_x(-1), flow_to_y(-1);
      REP(i, 4){
	int ny(y + dy[i]), nx(x + dx[i]);
	if(!isOut(ny, nx, H, W) && 
	   height[ny][nx] < height[y][x] && 
	   (flow_to_x == -1 || height[flow_to_y][flow_to_x] > height[ny][nx])){
	  flow_to_y = ny; flow_to_x = nx;
	}	
      }
      if(flow_to_x != -1){
	field[y][x] = field[flow_to_y][flow_to_x] = union_find.set_union(field[y][x], field[flow_to_y][flow_to_x]);
      }
    }
    char cur('a');
    memset(tab, 0, sizeof(tab));
    printf("Case #%d:\n", case_no+1);
    REP(y, H) {      
      REP(x, W){
	int idx = union_find.parent(field[y][x]);
	if(tab[idx] == (char)0) tab[idx] = cur++;
	printf("%s%c", (x?" ":""), tab[idx]);
      }
      puts("");
    }
    
  }
  return 0;
}
