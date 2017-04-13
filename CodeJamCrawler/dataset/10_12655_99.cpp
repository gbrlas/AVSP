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
	int N;
	LL K;
	cin >> N >> K;

	bool OK = true;

	for (int i = 0; i < N; ++i) {
		if (!(K & (1LL << i))) {
			OK = false;
			break;
		}
	}

	cout << "Case #" << caseNum << ": " << (OK ? "ON" : "OFF") << endl;
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

