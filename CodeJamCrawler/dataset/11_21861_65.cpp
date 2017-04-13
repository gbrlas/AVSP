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

string s[55];

int main() {
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		int r, c; cin >> r >> c;
		for(int i=0; i<r; i++) cin >> s[i];
		bool ok = true;
		for(int j=0; j<c-1; j++)
			for(int i=0; i<r-1; i++) {
				if(s[i][j] == '#' && s[i+1][j] == '#' && s[i][j+1] == '#' && s[i+1][j+1] == '#') {
					s[i][j] = '/';
					s[i+1][j] ='\\';
					s[i][j+1] = '\\';
					s[i+1][j+1] = '/';
				}
			}
		for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(s[i][j] == '#') ok = false;
		cout << "Case #" << _ << ":" << endl;
		if(!ok)
			cout << "Impossible" << endl;
		else {
			for(int i=0; i<r; i++) cout << s[i] << endl;
		}
	}
	
	return 0;
}
