#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define FOR(i,s,n) for(int(i)=(s);(i)<(n);(i)++)
#define DFOR(i,s,n) for(int(i)=(s);(i)>(n);(i)--)
#define SZ(v) (int)(v).size()
#define RESET(v,n) memset((v),(n),sizeof((v)))
#define PII pair<int,int>
#define PFF pair<double,double>
#define eps 1e-8
#define isEQF(f,a) (abs((f)-(a)) < eps)
#define LL long long
#define DEBUG puts("OK")
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
using namespace std;

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

inline void OPEN(string s) {
	freopen((s+ ".in").c_str(), "r",stdin );
	freopen((s+".out").c_str(), "w",stdout);
}

int main() {
	int tc;
	scanf("%d",&tc);
	FOR(ii,0,tc) {
		int r,c;
		scanf("%d %d",&r,&c);
		vector<string> peta(r);
		bool detect[r][c];
		RESET(detect,false);
		FOR(i,0,r) {
			cin >> peta[i];
		}
		bool pos = true;
		FOR(i,0,r) {
			FOR(j,0,c) {
				if (peta[i][j] == '#' && !detect[i][j]) {
					if (i+1<r && j+1 <c && peta[i+1][j] == '#' && peta[i+1][j+1] == '#' && peta[i][j+1]=='#') {
						peta[i][j] = '/'; peta[i][j+1] = '\\';
						peta[i+1][j] = '\\';peta[i+1][j+1] = '/';
						detect[i][j] = true;detect[i][j+1] = true;
						detect[i+1][j] = true;detect[i+1][j+1] = true;
					} else {
						pos = false;
						break;
					}
				}
			}
			if (!pos) break;
		}
		printf("Case #%d:\n",ii+1);
		if (!pos) cout << "Impossible\n";
		else  {
			FOR(i,0,r) {
				cout << peta[i] << endl;
			}
		}
	}
	return 0;
}
