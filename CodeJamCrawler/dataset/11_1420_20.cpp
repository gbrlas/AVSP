#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define X first
#define INF 1000000000
#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
vector<int> com;

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t=1,T; cin >> T;
	char s[10000];
	for (;t <= T;t++) {
		int n; scanf("%d\n", &n);
		vector<int> all(n);
		vector<int> won(n);
		vector<vector<int> > op(n);
		vector<double> wp(n), owp(n), oowp(n);
		vector<vector<int> > g(n, vector<int>(n, -1));
		for (int i=0; i<n; i++) {			
			gets(s);
			for (int j=0; j<n; j++) {
				if (s[j]=='1'){
					g[i][j]=1;
					all[i]++;
					won[i]++;
					op[i].PB(j);
				} else if (s[j]=='0'){
					g[i][j]=0;
					all[i]++;
					op[i].PB(j);
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (all[i]) {
				wp[i] = (double)won[i]/all[i];
			} else {
				wp[i] = 0;
			}
		}
		vector<vector<double> > _WP(n,vector<double>(n));
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int win=0, lose=0;
				for (int k=0; k<n; k++) {
					if ((j != k)) {
						if (g[i][k] == 1) {
							win++;
						} else if (g[i][k] == 0) {
							lose++;
						} 
					}
				}
				_WP[i][j] = (double)win/(lose+win);
			}
		}
		for (int i=0; i<n; i++) {
			owp[i]=0; int num=0;
			for(int j=0; j<op[i].size(); j++){
				owp[i] += _WP[ op[i][j] ][ i ];
			}
			if (op[i].size()){
				owp[i] /= op[i].size();
			}
		}
		for(int i=0; i<n; i++){
			oowp[i]=0;
			for(int j=0; j<op[i].size(); j++){
				oowp[i] += owp[ op[i][j] ];
			}
			if (op[i].size()){
				oowp[i] /= op[i].size();
			}
		}
		printf("Case #%d:\n", t);
		for (int i=0; i<n; i++) {
			double RPI = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
			printf("%lf\n", RPI);
		}
	}
	return 0;
}