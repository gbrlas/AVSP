#include <iostream>
#include <cmath>

using namespace std;


const int N = 100;
const int INF = 1000000000;

int o[N]; // next for o
int on[N+1]; // index for b
int b[N]; // next for b
int bn[N+1]; // index for b

inline int sgn(int i) {
	return (i > 0) ? 1 : -1;
}
void do_action(int& p, int* next, int& i) {
	if (p == next[i]) {
		// push the button
		++i;
	} else {
		// move to next
		p += sgn(next[i] - p);
	}
}

void do_move(int& p, int* next, int& i) {
	if (p != next[i]) {
		// move to next
		p += sgn(next[i] - p);
	}
}
void solve(int case_i) {
	int n;
	cin >> n;
	int n_o = 0, n_b = 0;
	for(int i = 0; i <= n; ++i) {
		on[i] = bn[i] = INF;
	}		
	
	for(int i = 0; i < n; ++i) {
		char c; int but;
		cin >> c >> but;
		switch (c) {
		case 'O':
			o[n_o] = but;
			on[n_o] = i;
			++n_o;
			break;
		case 'B':
			b[n_b] = but;
			bn[n_b] = i;
			++n_b;
			break;		
		}
	}
	int total = 0;
	int p_o = 1;
	int p_b = 1;
	int i_o = 0;
	int i_b = 0;
	while (i_o < n_o || i_b < n_b) {
		++total;
		if (on[i_o] < bn[i_b]) {
			do_action(p_o, o, i_o);
			do_move(p_b, b, i_b);	
		} else {
			do_action(p_b, b, i_b);
			do_move(p_o, o, i_o);
		}
	}
	cout << "Case #" << case_i << ": " << total << endl;
}
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		solve(i+1);
	}
	
}