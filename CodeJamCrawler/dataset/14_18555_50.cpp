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


int T, n;

int numOfNodes(vector<string> st){
	int ret = 1;
	REP(i, st.size()) ret += st[i].size();
	REP(i, st.size()){
		int maxcom = 0;
		REP(j, i){
			int k=0;
			for(;k<st[i].size()&&k<st[j].size()&&st[i][k]==st[j][k];k++);
			maxcom = max(maxcom, k);
		}
		ret -= maxcom;
	}
	return ret;
}

main(){
	cin >> T;
	REP(t, T){
		int N, M;
		cin >> M >> N;
		vector<string> str(M);
		REP(i, M) cin >> str[i];
		int maxans = 0, maxcnt = 0;
		REP(i, 1<<(2*M)){
			vector< vector<string> > b(N);
			int f = 1;
			REP(j, M){
				int tar = (i >> (j*2)) & 3;
				if(tar >= N){
					f = 0;
					break;
				}
				b[tar].push_back(str[j]);
			}
			if(!f) continue;
			int sum = 0;
			REP(j, N){
				if(b[j].size() == 0){
					f = 0;
					break;
				}
				sum += numOfNodes(b[j]);
			}
			if(!f) continue;
			if(maxans < sum){
				maxans = sum;
				maxcnt = 0;
			}
			if(maxans == sum){
				maxcnt ++;
			}
		}
		printf("Case #%d: %d %d\n", t+1, maxans, maxcnt);
	}
	return 0;
}
