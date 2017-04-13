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

int mem[256][128];

int D, I, M, N;
int seq[128];
int solve(int pre, int pos){
	if(pos == N) return 0;
	if(pre < 0){
		//delete
		int cost = solve(-1, pos + 1) + D;
		//change
		REP(next, 256){
			cost = min(cost, solve(next, pos + 1) + abs(next - seq[pos]));
		}
		return cost;
	}
	int &cost = mem[pre][pos];
	if(cost >= 0) return cost;
	cost = 0x7fffffff;
	//do nothing
	//if(abs(seq[pos] - pre) <= M) cost = solve(seq[pos], pos + 1);

	//change and insert
	REP(next, 256){
		int addn;
		if(M == 0 && next != pre) continue;
		if(next == pre) addn = 0;
		else addn = (abs(next - pre) - 1) / M;
		cost = min(cost, solve(next, pos + 1) + addn * I + abs(next - seq[pos]));
	}
	//delete
	cost = min(cost, solve(pre, pos + 1) + D);
	return cost;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		cin >> D >> I >> M >> N;

		REP(i, N) cin >> seq[i];
		memset(mem, 0xff, sizeof(mem));
		int res = solve(-1, 0);
		PrintResult(cs + 1, res);
		cerr << cs + 1 << endl;
	}
	return 0;
}