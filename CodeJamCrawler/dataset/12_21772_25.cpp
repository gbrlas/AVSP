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


string from = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvqz";
string to   = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupzq";

const int maxn = 3000;
int cnt[maxn+10];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; cin >> T;
	for(int _ = 1; _ <= T; _++) {
		memset(cnt, 0, sizeof(cnt));
		int a, b;
		cin >> a >> b;
		for(int i = a; i <= b; i++) {
			stringstream ss;
			ss << i;
			string t = ss.str();
			string best = t;
			for(int j = 0; j < Sz(best); j++) {
				string s = t.substr(j) + t.substr(0, j);
				if(s[0] != '0' && s < best) best = s;
			}

			stringstream sss(best);
			int q;
			sss >> q;
			cnt[q]++;
		}
		int res = 0;
		for(int i = 0; i < maxn; i++) res += cnt[i] * (cnt[i] - 1) / 2;
		cout << "Case #" << _ << ": " << res << endl;
	}

	return 0;
}

