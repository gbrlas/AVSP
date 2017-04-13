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
typedef pair<int, vector<char> > PV;



void runCase(int caseNum)
{
	int res = 0;
	int N;
	cin >> N;
	string line;
	vector<int>  num;
	getline(cin, line);

	REP(i, N) {
		getline(cin, line);
		int p = -1;
		REP(j, N) {
			if(line[j] == '1')
				p = j;
		}
		num.push_back(p);
	}

	REP(i, N) {
		FOR(j, i, N-1) {
			if(num[j] <= i) {
				res += j - i;
				FORN(k, j, i+1) {
					swap(num[k], num[k-1]);
				}
				break;
			}
		}
	}

	printf("Case #%d: %d\n",caseNum, res);
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


