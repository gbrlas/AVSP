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

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<pair<int, int> > VPII;


void preProcess()
{}

void runCase(int caseNum) {
	LL R, k, N;

	cin >> R >> k >> N;

	vector<LL> vals;

	for (int i = 0; i < N; ++i) {
		LL g;
		cin >> g;
		vals.push_back(g);
	}

	vector<pair<LL, int> > mem(N, pair<LL, int>(-1, -1));
	mem[0].first = 0;
	mem[0].second = 0;

	LL res = 0;
	int c = 0;
	int cur = 0;
	LL g = 0;
	bool cy = false;
	while (1) {
		if (g + vals[cur] > k || c >= N) {
			res += g;
			g = 0;
			--R;
			if (!cy && mem[cur].first > 0) {
				cy = true;
				LL r = mem[cur].second - R;
				LL t = res - mem[cur].first;
				res += t * LL(R / r);
				R %= r;
			}
			mem[cur].first = res;
			mem[cur].second = R;
			c = 0;
			if (R <= 0)
				break;
		}
		g += vals[cur];
		++cur;
		++c;
		if (cur >= N)
			cur = 0;
	}


	cout << "Case #" << caseNum << ": " << res << endl;
}

int main(int argc, char* argv[])
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	void preProcess();

	int K;
	cin >> K;
	for (int k = 0; k < K; ++k) {
		runCase(k+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

