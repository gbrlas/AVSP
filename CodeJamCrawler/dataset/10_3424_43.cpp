#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i, s, e) for(int i = (s); i < (e); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SQR(x) ((x)*(x))
#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;

template<class T>
inline void PrintResult(int caseNum, T res){
	cout <<"Case #" << caseNum << ": " << res << endl;
}

int diam[128][128];
int k;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		REP(i, 128) REP(j, 128) diam[i][j] = -1;;
		cin >> k;
		REP(i, k){
			REP(j, i + 1){
				cin >> diam[i][k - i - 1 + 2 * j];		
			}
		}
		REP(i, k - 1){
			REP(j, k - i - 1){
				cin >> diam[i + k][i + 1 + 2 * j];	
			}
		}
		int minV = 1000, minH = 1000;
		REP(v, 2 * k - 1){
			bool sym = true;
			REP(i, 2 * k - 1){
				REP(j, v){
					if(diam[i][j] == -1) continue;
					int n = 2 * v - j;
					if(n >= 2 * k - 1 || diam[i][n] == -1) continue;
					if(diam[i][j] != diam[i][n]){
						sym = false;
						break;
					}
				}
				if(!sym) break;
			}
			if(sym) minV = min(abs(v - k + 1), minV);

		}

		REP(h, 2 * k - 1){
			bool sym = true;
			REP(i, 2 * k - 1){
				REP(j, h){
					if(diam[j][i] == -1) continue;
					int n = 2 * h - j;
					if(n >= 2 * k - 1 || diam[n][i] == -1) continue;
					if(diam[j][i] != diam[n][i]){
						sym = false;
						break;
					}
				}
				if(!sym) break;
			}
			if(sym) minH = min(abs(h - k + 1), minH);

		}
		PrintResult(cs + 1, (k + minH + minV) * (k + minH + minV) - k * k);
	}
	return 0;
}