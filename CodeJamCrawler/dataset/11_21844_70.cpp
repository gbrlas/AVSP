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



int main() {
	int T; cin >> T;
	for(int _=0; _<T; _++) {
		int n; cin >> n;

		int res = 0;
		int lasto, lastb;
		lasto = lastb = 0;
		int o, b;
		o = b = 1;

		for(int i=0; i<n; i++) {
			char r; cin >> r;
			int but; cin >> but;
			if(r == 'O') {
				int req = abs(o-but);
				Eo(req);
				if(lasto > req)
					lasto -= req;
				else {
					req -= lasto;
					res += req;
					lastb += req;
				}
				lasto = 0;
				lastb++;
				o = but;
			} else {
				int req = abs(b-but);
				if(lastb > req)
					lastb -= req;
				else {
					req -= lastb;
					res += req;
					lasto += req;
				}
				lastb = 0;
				lasto++;
				b = but;
			}
			res++;
		}
		cout << "Case #" << _+1 << ": " << res << endl;
	}

	return 0;
}
