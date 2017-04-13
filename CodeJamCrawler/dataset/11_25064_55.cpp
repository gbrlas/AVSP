#include <iostream>

using namespace std;

typedef unsigned int uint;

int value(uint m, int n, int* v) {
	int r = 0;
	for(int i = 0; i < n; ++i) {
		if (m & (1 << i)) {
			r ^= v[i];
		}
	}
	return r;
}

int sum(uint m, int n, int* v) {
	int r = 0;
	for(int i = 0; i < n; ++i) {
		if (m & (1 << i)) {
			r += v[i];
		}
	}
	return r;
}

const int N = 1000;

void solve(int case_i) {
    int n;
    int v[N] = {};
    cin >> n;
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    }
    uint mask = (1 << (n)) - 1;
    int max_sum = -1;
    for(uint m = 1; m < mask; ++m) {
    	uint mo = ((~m) & mask);	   	
    	if (value(m, n, v) == value(mo, n, v)) {
    		int s = sum(m, n, v);
    		if (s > max_sum) {
    			max_sum = s;
    		}
    	}
    }
	cout << "Case #" << case_i << ": ";
	if (max_sum < 0) {
		cout << "NO";
	} else {
		cout << max_sum;
	}
	endl(cout);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		solve(i+1);
	}
	
}