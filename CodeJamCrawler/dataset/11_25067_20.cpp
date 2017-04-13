#include <iostream>
#include <cmath>

using namespace std;

#ifdef DEBUG
#define WATCH(x) (cerr << #x << '=' << (x) << endl)
#define TRACE(x) (cerr << (x) << endl)
#else
#define WATCH(x) /*()*/
#define TRACE(x) /*()*/
#endif

#define long long long

void factor(int v, int& c2, int& c5) {
	while (v % 2 == 0 && c2 < 2) {
		v /= 2;
		++c2;
	}
	while (v % 5 == 0 && c5 < 2) {
		v /= 5;
		++c5;
	}

}

bool solve() {
	long n, pd, pg;
	cin >> n >> pd >> pg;
	int c2=0, c5=0;
	factor(pd, c2, c5);
	int d = 1;
	while (c2 < 2) {
		d *= 2;
		++c2;
	}
	while (c5 < 2) {
		d *= 5;
		++c5;
	}	
	if (d > n) {
		return false;
	}	
	if (pg == 0) return pd == 0;
	if (pg == 100) return pd == 100;
	return true;
}
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cout << "Case #" << i+1 << ": ";
	  	if (solve()) {
	  		cout << "Possible";
	  	} else {
	  		cout << "Broken";
	  	}
	  	endl(cout);
	}
}