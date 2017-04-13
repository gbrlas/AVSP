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

string t;

void runCase(int caseNum)
{
	string line;
	while(SZ(line)==0)
		getline(cin, line);

	VII dp(SZ(t), VI(SZ(line), 0));

	REP(i, SZ(t)) REP(j, SZ(line)) {
		if(t[i] != line[j])
			continue;
		if(i == 0) {
			dp[i][j] = 1;
			continue;
		}
		REP(k, j) {
			dp[i][j] += dp[i-1][k];
		}
		dp[i][j] %= 10000;
	}

	int res = 0;

	REP(i, SZ(line)) {
		res += dp[SZ(t) -1][i];
	}

	res %= 10000;

	printf("Case #%d: %04d\n",caseNum, res);
}

int main(int argc, char* argv[])
{
	t = "welcome to code jam";


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


