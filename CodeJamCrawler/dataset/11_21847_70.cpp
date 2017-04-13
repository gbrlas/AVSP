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
		map<char, char> cs[256];
		set<char> ds[256];

		int c; cin >> c;
		for(int i=0; i<c; i++) {
			string s; cin >> s;
			cs[s[0]][s[1]] = cs[s[1]][s[0]] = s[2];
		}

		int d; cin >> d;
		for(int i=0; i<d; i++) {
			string s; cin >> s;
			ds[s[0]].insert(s[1]);
			ds[s[1]].insert(s[0]);
		}

		int n; cin >> n;
		string s; cin >> s;
		vector<char> res;
		for(int i=0; i<n; i++) {
			res.push_back(s[i]);
			//Eo(s[i]);
			if(sz(res) >= 2) {
				char a = res[sz(res)-1];
				char b = res[sz(res)-2];
			//	Eo(a); Eo(b);
				if(cs[a].find(b) != cs[a].end()) {
					res.pop_back();
					res.pop_back();
					res.push_back(cs[a][b]);
					continue;
				}
				
				for(int j=0; j<sz(res)-1; j++) if(ds[a].find(res[j]) != ds[a].end()) {
					res.clear();
					break;
				}
			}
		}

		cout << "Case #" << _+1 << ": [";
		for(int i=0; i<sz(res); i++) {
			if(i) cout << ", ";
			cout << res[i];
		}
		cout << "]" << endl;
	}
	
	return 0;
}
