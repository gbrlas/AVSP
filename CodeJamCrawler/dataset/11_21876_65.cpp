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

int a[123];

int main() {
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		int n, l, h; cin >> n >> l >> h;
		for(int i=0; i<n; i++) cin >> a[i];
		bool ok = false;
		int ans = 0;
		for(int i=l; i<=h; i++) {
			bool fail = false;
			for(int j=0; j<n; j++) if(i%a[j] != 0 && a[j]%i != 0) {
				fail = true;
				break;
			}
			if(!fail) {
				ok =true;
				ans = i;
				break;
			}
		}
		cout << "Case #" << _ << ": ";
		if(ok)
			cout << ans << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
