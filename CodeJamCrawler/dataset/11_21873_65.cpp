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
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-5;

const int maxn = 1000500;
int64 dist[maxn], a[maxn];


int main() {
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		Eo(_);
		int64 l, t, n, c; cin >> l >> t >> n >> c;
		for(int i=0; i<c; i++) cin >> a[i];
		for(int i=0; i<n; i++) dist[i] = a[i%c];

		int64 res = 0;
		multiset<int64> other;
		for(int i=0; i<n; i++) {
			int64 end = res+dist[i]*2;
			if(end <= t)
				res = end;
			else {
				int64 before = (t-res)/2;
				int64 last = dist[i]-before;
				res += before*2;
				other.insert(last);
				for(int j=i+1; j<n; j++) other.insert(dist[j]);
				int tt = other.size()-l;
				for(multiset<int64>::iterator j = other.begin(); j != other.end(); j++, tt--) {
					if(tt > 0) {
						res += (*j)*2;
					} else
						res += (*j);
				}
				break;
			}
		}
		cout << "Case #" << _ << ": " << res << endl;
	}
	
	return 0;
}
