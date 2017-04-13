#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-11;
const double pi = acos(-1.0);

LL StrToLL(string s) {
	LL res = 0;
	REP(i, SZ(s)) {
		res += s[i];
		res *= 10;
	}
	return res / 10;
}

string LLToSrt(LL x) {
	string res;
	while(x) {
		res.push_back(x % 10);
		x /= 10;
	}
	reverse(ALL(res));
	return res;
}

string Shift(string s) {
	if (s.size() == 1) {
		return s;
	}
	string res =  s.substr(1, s.size() - 1);
	res.push_back(s[0]);
	return res;
}


const int N = 2000000;
int used[2000000 + 1];


int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	REP(t, T) {
		LL res = 0;
		LL l, r;
		cin >> l >> r;
		memset(used, 0, N + 1);
		map<int, int> m;
		int num = 0;
		FOR(i, l, r) {
			if (!used[i]) {
				++num;
				string tmp = LLToSrt(i);
				REP(j, SZ(tmp)) {
					tmp = Shift(tmp);
					used[StrToLL(tmp)] = num;
				}
			}
		}
		FOR(i, l, r) {
			m[used[i]]++;
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			res += it->second * (it->second - 1) / 2;
		}
		printf("Case #%lld: %d\n", t + 1, res);
	}
	return 0;
}