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

const int maxn = 1<<10;
int arr[maxn];

int main() {
	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		cout << "Case #" << _ << ": ";
		int n; cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		int res = 0;
		for(int i=0; i<n; i++) res ^= arr[i];
		if(res) {
			cout << "NO" << endl;
			continue;
		}

		int sum = 0;
		for(int i=1; i<n; i++) sum += arr[i];
		cout << sum << endl;
	}
	
	return 0;
}
