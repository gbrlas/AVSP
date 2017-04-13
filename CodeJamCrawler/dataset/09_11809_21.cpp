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
typedef pair<int, pair<int, int> > PPII;



void runCase(int caseNum)
{
	double res = 0;

	int N;
	cin >> N;
	int X, Y, R;

	if(N == 1) {
		cin >> X >> Y >> R;
		res = R;
	}
	else if(N == 2) {
		double p;
		cin >> X >> Y >> R;
		p = R;
		cin >> X >> Y >> R;
		res = max(p, (double)R);
	}
	else if(N == 3) {
		int x1, x2, x3, y1, y2, y3, r1, r2, r3;
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		cin >> x3 >> y3 >> r3;
		double rr1, rr2, rr3;
		
		rr1 = max((double)r1, (r2 + r3 + sqrt((double)(x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)))/2.0);
		rr2 = max((double)r2, (r1 + r3 + sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)))/2.0);
		rr3 = max((double)r3, (r1 + r2 + sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))/2.0);

		res = min(rr1, rr2);
		res = min(res, rr3);
	}

	printf("Case #%d: %.6f\n",caseNum, res);
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


