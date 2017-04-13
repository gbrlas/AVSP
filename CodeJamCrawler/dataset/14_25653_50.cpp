//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int TC;
int w, h, b;
bool ok[510][110];

struct edge{
    int to, cap, rev;
    edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev){}
    edge(){}
};

vector<edge> g[100110];
bool vis[100110];

void ae(int f, int t, int c){
    g[f].pb(edge(t, c, g[t].size()));
    g[t].pb(edge(f, 0, (int)g[f].size() - 1));
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    vis[v] = true;
    rep(i, g[v].size()){
	edge &e = g[v][i];
	if(!vis[e.to] && e.cap > 0){
	    int d = dfs(e.to, t, min(f, e.cap));
	    if(d > 0){
		e.cap -= d;
		g[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}

int mof(int s, int t){
    int flow = 0;
    while(true){
	memset(vis, 0, sizeof(vis));
	int f = dfs(s, t, 1000000000);
	if(f == 0) return flow;
	flow += f;
    }
}

int main(){
    scanf("%d", &TC);

    for(int num = 1; num <= TC; ++num){
	printf("Case #%d: ", num);
	scanf("%d %d %d", &w, &h, &b);
	memset(ok, 0, sizeof(ok));

	rep(i, w * h * 2 + 2) g[i].clear();
	rep(i, b){
	    int p, q, r, s;
	    scanf("%d %d %d %d", &p, &q, &r, &s);
	    for(int y = q; y <= s; ++y){
		for(int x = p; x <= r; ++x){
		    ok[y][x] = true;
		}
	    }
	}

	rep(i, h){
	    rep(j, w){
		if(!ok[i][j]){
		    ae((i * w + j) * 2 + 1, (i * w + j) * 2 + 2, 1);
		    rep(d, 4){
			int ny = i + dy[d];
			int nx = j + dx[d];
			if(ny >= 0 && ny < h && nx >= 0 && nx < w && !ok[ny][nx]){
			    ae((i * w + j) * 2 + 2, (ny * w + nx) * 2 + 1, 1);
			}
		    }
		}
	    }
	}
	int s = 0, t = w * h * 2 + 2;
	rep(i, w){
	    if(!ok[0][i]){
		ae(s, i * 2 + 1, 1);
	    }
	}
	rep(i, w){
	    if(!ok[h-1][i]){
		ae(((h - 1) * w + i) * 2 + 2, t, 1);
	    }
	}
	printf("%d\n", mof(s, t));
    }

    return 0;
}
