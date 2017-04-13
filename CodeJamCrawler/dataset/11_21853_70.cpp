#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define sz(x) (int((x).size()))
#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename C> ostream& operator<<(ostream& os, const vector<C>& v) { foreach(__it, v) os << *(__it) << ' '; return os; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const real eps = 1e-5;

const int maxn = 16;
int arr[maxn];

int main() {
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		int n; cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];

		int res = -inf;
		for(int i=0; i<(1<<n); i++) {
			int sl, xl, sr, xr;
			sl = xl = sr = xr = 0;
			for(int j=0; j<n; j++)
				if(i&(1<<j)) {
					sl += arr[j];
					xl ^= arr[j];
				} else {
					sr += arr[j];
					xr ^= arr[j];
				}
			if(sl && sr && xl == xr && sr > res) res = sr;
		}
		cout << "Case #" << _ << ": ";
		if(res == -inf) {
			cout << "NO" << endl;
		} else
			cout << res << endl;
	}
	
	return 0;
}
