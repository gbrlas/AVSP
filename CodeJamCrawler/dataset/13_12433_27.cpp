#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------
#define MAXN 2000
#define MIDN (MAXN/2)
char C[] = {'E', 'W', 'N', 'S'};
int X, Y;
int way[][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

struct NODE {
	int x, y, m;
	bool operator <(const NODE &in) const {
		return in.m < m;
	}
};

bool islegal(int x, int y){
	if(x < 0 || y < 0 || x >= MAXN || y >= MAXN){
		return false;
	}
	return true;
}
int dp[MAXN][MAXN];
vector<int> path[MAXN][MAXN];

vector<int> dijkstra() {
	//initial
	forn(i, MAXN) {
		forn(j, MAXN) {
			dp[i][j] = INT_MAX;
			path[i][j].clear();
		}
	}

	//min heap
	priority_queue<NODE> q;
	NODE start;


	start.x = MIDN;
	start.y = MIDN;
	start.m = 0;
	q.push(start);

	dp[start.x ][start.x] = 0;

	while (!q.empty()) {
		NODE now = q.top();
		q.pop();
		int x = now.x;
		int y = now.y;

		//printf("%d %d [%d]\n", x, y, now.m);

		//if (dp[x][y] <= now.m)
		//	continue;

		//dp[x][y] = now.m;

		if (x == X + MIDN && y == Y + MIDN){
			return path[x][y];
		}


		NODE next;
		for (int i = 0; i < 4; i++) {
			int nx = x + way[i][0] * (now.m + 1);
			int ny = y + way[i][1] * (now.m + 1);
			if (islegal(nx, ny) == false) continue;
			if (dp[nx][ny] > dp[x][y] + 1) {
				dp[nx][ny] = dp[x][y] + 1;
				path[nx][ny] = path[x][y];
				path[nx][ny].pb(i);
				next.x = nx;
				next.y = ny;
				next.m = now.m + 1;
				q.push(next);
			}
		}
	}
	return path[0][0];
}

int main() {

	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		scanf("%d%d", &X, &Y);
		//printf("%s\n", str);

		//vector<int> ans = dijkstra();

		printf("Case #%d: ", casenum++);

		// move X way first
		for(int i = 0; i < abs(X); i++){

			if(X > 0) printf("WE");
			if(X < 0) printf("EW");
		}
		for(int i = 0; i < abs(Y); i++){
			if(Y > 0) printf("SN");
			if(Y < 0) printf("NS");
		}
		printf("\n");
/*
		int rx = 0, ry = 0, c = 1;
		for(int i = 0; i < (int)ans.size(); i++){
			printf("%c", C[ ans[i]]);
			rx += way[ans[i]][0]* c;
			ry += way[ans[i]][1]* c;
			c++;
		}
		printf("\n");
		printf(" (%d %d)(%d %d)\n", rx, ry, X, Y);
		*/

		fflush(stdout);
	}
	return 0;
}
