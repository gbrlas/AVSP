#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(x,v) FOR(x,(v).begin(),(v).end())
#define sz size()
#define pb push_back
typedef pair<int,int> PII;
#define DBG(x) cout<< #x << " --> "<< x << "\t"
#define DBE(x) cout<< #x << " --> "<< x << "\n" 

int c, n, m , t, f, b;
int g[101][101]; // flav * cust
int main() {
	cin >> c;
	int k = 1;
	while(c--) {
		cin >> n; cin >> m;
	//	DBG(n); DBE(m);
		memset(g, -1, sizeof(g));
		REP(i, m) {
			cin >> t;
			REP(j, t) {
				cin >> f >> b;
				g[f-1][i] = b;
			}
		}// end of input
		int vis[101]; memset(vis, 0, sizeof(vis));
		int done = 0;
		REP(mask, (1<<n)) {
		memset(vis, 0, sizeof(vis));
			REP(f, n) {
				if((1<<f)&mask){//malted
					REP(i, m) if(g[f][i] == 1) vis[i]++;
				}
				else {
					REP(i, m) if(g[f][i] == 0) vis[i]++;
				}
			}
//			REP(i, m) cout << vis[i] << " "; cout << endl;
			int flag = 0;
			REP(i, m) if(vis[i] == 0) {flag = 1;break;}
			if(!flag) {
				cout << "Case #" << k << ":";
				int print[101];
				REP(i, n) if((1<<i)&mask) cout  << " 1"; else cout << " 0";
				cout << endl;			
				done = 1;
				break;
			}
		}
		
		if(done) {k++;continue;}
		cout << "Case #" << k << ": IMPOSSIBLE\n";			
		k++;
	}

	return 0;
}
