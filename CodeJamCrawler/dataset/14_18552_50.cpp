#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int lli;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int T, W, H, B;
int Wall[1000][1000];
int vis[1000][1000];
int d[4][2] = {{0, 1},{-1, 0},{0, -1},{1, 0}};
int p[3] = {1, 0, 3};
int ans = 0;
int dfs(int x, int y, int pd){
//	printf("%d %d %d\n", x ,y , pd);
	if(Wall[y][x]) return 0;
	if(vis[y][x]) return 0;
	Wall[y][x] = 1;
	vis[y][x] = 1;
	if(y == H) return 1;
	REP(i, 3){
		int dx = d[(pd+p[i])%4][0];
		int dy = d[(pd+p[i])%4][1];
		if(dfs(x+dx, y+dy, (pd+p[i])%4)){
			return 1;
		}
	}
	Wall[y][x] = 0;
	return 0;
}
int bfs(int x, int y){
	if(vis[y][x] || Wall[y][x]) return 0;
	queue<pii> que;
	que.push(pii(x, y));
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		vis[y][x] = 1;
		if(y == H) return 1;
		REP(i, 4){
			int dx = x+d[i][0];
			int dy = y+d[i][1];
			if(vis[dy][dx] || Wall[dy][dx]) continue;
			vis[dy][dx] = 1;
			que.push(pii(dx, dy));
		}
	}
	return 0;
}
main(){
	cin >> T;
	REP(t, T){
		cin >> W >> H >> B;
		memset(Wall, 0, sizeof(Wall));
		memset(vis, 0, sizeof(vis));
		REP(i, W+1) Wall[0][i] = Wall[H+1][i] = 1;
		REP(i, H+1) Wall[i][0] = Wall[i][W+1] = 1;
		REP(i, B){
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			for(int y=y0;y<=y1;y++)for(int x=x0;x<=x1;x++) Wall[y+1][x+1] = 1;
		}
		fflush(stdout);
		ans = 0;
		REP(i, W){
			if(!bfs(i+1, 1)) continue;;
			memset(vis, 0, sizeof(vis));
			ans += dfs(i+1, 1, 0);
			memset(vis, 0, sizeof(vis));
		}
//		REP(i, H)REP(j, W)printf("%d%s", Wall[i+1][j+1], j==W-1?"\n":"");
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
