#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#ifdef ILIKEGENTOO
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define E(x) { cerr << #x << " = " << (x) << "   "; }
#else
#define Eo(x)
#define E(x)
#endif
#if defined ILIKEGENTOO || !(defined __GNUC__ ) || (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6))
template<typename T, size_t N> struct array { T val[N]; T& operator[](size_t n) { if(n >= N) assert(false); return val[n]; } T* begin() { return &val[0]; } T* end() { return &val[0]+N; } };
#else
#include <array>
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;

#if 0
struct fen_t {
	static const int maxn = 1000*1000*1000 + 10;
	map<int, int> arr;

	void init() {
		arr.clear();
	}

	void get(int pos) {
		int res = -inf;
		for(; pos >= 0; pos = (pos & (pos+1)) - 1) {
			res = max(res, arr[pos]);
		}
		return res;
	}

	void set(int pos, int val) {
		for(; pos < maxn; pos |= pos+1) {
			arr[pos] = max(arr[pos], val);
		}
	}
} fen;
#endif

const int mn = 1010;
int r[mn];
int num[mn];
int pos[mn][2];


int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for(int i = 0; i < mn; i++) num[i] = i;
	for(int tnum = 1; tnum <= T; tnum++) {
		int n, w, h; cin >> n >> w >> h;
		for(int i =0; i < n; i++) cin >> r[i];
		bool ok = false;
		while(!ok) {
			bool fail = false;
			for(int i = 0; i < n; i++) {
				fail = true;
				for(int t = 0; t < 3; t++) {
					pos[i][0] = lrand48() % (w + 1);
					pos[i][1] = lrand48() % (h + 1);
					int rul = pos[i][0] - r[i];
					int rur = pos[i][0] + r[i];
					int ruu = pos[i][1] - r[i];
					int rub = pos[i][1] + r[i];
					for(int j = 0; j < i; j++) {
						int rol = pos[j][0] - r[j];
						int ror = pos[j][0] + r[j];
						int rou = pos[j][1] - r[j];
						int rob = pos[j][1] + r[j];
						if(max(rul, rol) < min(rur, ror) && max(ruu, rou) < min(rub, rob)) {
							goto rept;
						}
					}
					fail = false;
					break;
rept:
					continue;
				}
				if(fail) break;
			}
			if(!fail) ok = true;
		}

		cout << "Case #" << tnum << ":";
		for(int i = 0; i < n; i++) cout << ' ' << pos[i][0] << ".0 " << pos[i][1] << ".0";
		cout << endl;
	}

	return 0;
}
