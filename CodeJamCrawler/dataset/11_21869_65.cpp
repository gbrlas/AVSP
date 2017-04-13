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
	Eo(inf64);
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		int64 l, t, n, c; cin >> l >> t >> n >> c;
		Eo(_); Eo(l);
		for(int i=0; i<c; i++) cin >> a[i];
		for(int i=0; i<n; i++) dist[i] = a[i%c];

		int64 res = 0;
		if(l==0) {
			for(int i=0; i<n; i++) res += dist[i];
			res *= 2;
		} else if(l == 1) {
			res = inf64;
			for(int i=0; i<n; i++) {
				int64 curres = 0;
				for(int j=0; j<n; j++) {
					if(i != j)
						curres += dist[j]*2;
					else {
						int64 start = curres;
						int64 end = curres + dist[j]*2;
						if(t <= start)
							curres += dist[j];
						else if(t >= end)
							curres += dist[j]*2;
						else {
							int64 before = (t-start)/2;
							int64 last = dist[j]-before;
							curres += before*2 + last;
						}
					}
				}
				res = min(res, curres);
			}
		} else if(l == 2) {
			res = inf64;
			for(int i=0; i<n; i++) for(int k=0; k<n; k++) {
				int64 curres = 0;
				for(int j=0; j<n; j++) {
					if(i != j && j != k)
						curres += dist[j]*2;
					else {
						int64 start = curres;
						int64 end = curres + dist[j]*2;
						if(t <= start)
							curres += dist[j];
						else if(t >= end)
							curres += dist[j]*2;
						else {
							int64 before = (t-start)/2;
							int64 last = dist[j]-before;
							curres += before*2 + last;
						}
					}
				}
				res = min(res, curres);
			}
		}
		cout << "Case #" << _ << ": " << res << endl;
	}
	
	return 0;
}
