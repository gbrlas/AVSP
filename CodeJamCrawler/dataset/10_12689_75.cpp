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
#include <ext/hash_map>
// C++ Big Integer Library
// http://mattmccutchen.net/bigint/
//#include "BigIntegerLibrary.hh"


using namespace std;
using namespace __gnu_cxx;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;


void runCase(int caseNum) {
	int N, K;
	cin >> N >> K;
	vector<string> bd;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		bd.push_back(s);
	}
//	for (int i = 0; i < N; ++i)
//		cout << bd[i] << endl;
	vector<string> nb(N, string(N, '.'));
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = N - 1; j >= 0; --j) {
			if (bd[i][j] != '.') {
				++cnt;
				nb[N - cnt][N - 1 - i] = bd[i][j];
			}
		}
	}
//	for (int i = 0; i < N; ++i)
//		cout << nb[i] << endl;

	bool bOK = false;
	bool rOK = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (nb[i][j] == '.')
				continue;
			if (nb[i][j] == 'R' && rOK)
				continue;
			if (nb[i][j] == 'B' && bOK)
				continue;
			bool a = true, b = true, c = true, d = true;
			if (j < K - 1)
				d = false;
			for (int k = 1; k < K; ++k) {
//				if (i == 1 && j == 0)
//					cout << nb[i][j] << " " << nb[i + k][j + k] << endl;
				if (i + k >= N) {
					b = c = d = false;
				}
				if (j + k >= N) {
					a = false;
					b = false;
				} else {
					if (nb[i][j + k] != nb[i][j])
						a = false;
					if (i + k < N && nb[i + k][j + k] != nb[i][j])
						b = false;
				}
				if (i + k < N && nb[i + k][j] != nb[i][j])
					c = false;
				if (i + k < N && d && nb[i + k][j - k] != nb[i][j])
					d = false;
			}
//			if (i == 1 && j == 0)
//				cout << b << endl;
			if (a || b || c || d) {
				if (nb[i][j] == 'R')
					rOK = true;
				else
					bOK = true;
			}
//			if (i == 1 && j == 0)
//				cout << b << " " << rOK << " " << bOK << endl;
		}
	}
	cout << "Case #" << caseNum << ": ";
	if (bOK && rOK)
		cout << "Both";
	else if (!bOK && !rOK)
		cout << "Neither";
	else if (bOK)
		cout << "Blue";
	else
		cout << "Red";
	cout << endl;
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		runCase(i + 1);

//	runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

