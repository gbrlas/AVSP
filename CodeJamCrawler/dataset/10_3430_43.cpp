#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
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

int M[1 << 10];
typedef pair<pair<int, int>, int> state_t;
map<state_t, int> mem;
map<pair<int, int>, int> cost;
int maxCost = 0x7fffffff;
int solve(int s, int t, int miss){
	state_t st = make_pair(make_pair(s, t), miss);
	if(mem.count(st)){
		return mem[st];
	}
	int &ref = mem[st];
	if(s + 1 == t){
		if(miss > M[s]) return ref = maxCost;
		else return ref = 0;
	}
	int tc = cost[make_pair(s, t)];
	int tmp1, tmp2;
	tmp1 = solve(s , (s + t) / 2, miss);
	tmp2 = solve((s + t) / 2, t, miss);
	if(tmp1 == maxCost || tmp2 == maxCost){
		ref = maxCost;
	}else ref = tc + tmp1 + tmp2;
	
	tmp1 = solve(s , (s + t) / 2, miss + 1);
	tmp2 = solve((s + t) / 2, t, miss + 1);
	if(tmp1 != maxCost && tmp2 != maxCost)
	ref = min(ref,tmp1 + tmp2);
	return ref;
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		int P;
		cin >> P;
		REP(i, 1 << P) cin >> M[i];
		REP(i, P){
			REP(j, 1 << (P - i - 1)){
				int tmp;
				cin >> tmp;
				int l = (1 << (i + 1)) * j;
				int r = (1 << (i + 1)) * (j + 1);
				cost[make_pair(l, r)] = tmp;
			}
		}
		mem.clear();
		PrintResult(cs + 1, solve(0, 1 << P, 0));
		cerr << cs + 1 << endl;
	}
	return 0;
}