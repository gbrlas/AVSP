#include <vector> 
#include <map> 
#include <set> 
#include <queue> 
#include <list>
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <fstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORN(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i, 0, (n)-1)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000
typedef long long LL;
typedef long double LD;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef pair<int, int> PII;

int ys[] = {0, -1, 1, 0};
int xs[] = {-1, 0, 0, 1};

void runCase(int caseNum)
{
	int H, W;
	cin >> H >> W;
	VII mp(H, VI(W, 0));
	VII mark(H, VI(W, -1));

	vector< pair<int, pair<int, int> > > lst;

	REP(hhh, H) REP(www, W) {
		int t;
		cin >> t;
		mp[hhh][www] = t;
		lst.push_back(pair<int, pair<int, int> >(t, PII(hhh, www)));
	}
	sort(ALL(lst));
	int cnt = 0;
	FORN(i, SZ(lst) - 1, 0) {
		int x = lst[i].second.first;
		int y = lst[i].second.second;
		if(mark[x][y] >= 0)
			continue;
		vector<PII > path;
		while(true) {
			int nx = -1, ny = -1;
			int v = mp[x][y];
			path.push_back(PII(x, y) );
			//mp[x][y] = -1;
			//mark[x][y] = cnt;
			REP(j, 4) {
				int xx = x + xs[j];
				int yy = y + ys[j];
				if(xx >= 0 && xx < H && yy >= 0 && yy < W && mp[xx][yy] >= 0 && mp[xx][yy] < v) {
					v = mp[xx][yy];
					nx = xx;
					ny = yy;
				}
			}
			if(nx >= 0) {
				x = nx;
				y = ny;
			}
			else
				break;

		}
		x = path.back().first;
		y = path.back().second;
		int vv;
		if(mark[x][y] >= 0) {
			vv = mark[x][y];
		}
		else
			vv = cnt++;

		REP(j, SZ(path)) {
			mark[path[j].first][path[j].second] = vv;
		}
	}

	printf("Case #%d:\n",caseNum);
	map<int, char> r;
	char cc = 'a';
	REP(i, H) {
		REP(j, W) {
			if( !r.count(mark[i][j])) {
				r[mark[i][j]] = cc++;
			}
			if(j > 0)
				printf(" ");
			printf("%c", r[mark[i][j]]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int K;
	cin >> K;
	REP(k, K){
		runCase(k+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


