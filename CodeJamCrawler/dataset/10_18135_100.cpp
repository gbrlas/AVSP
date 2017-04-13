#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;
LL x[55];
LL v[55];

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n_chicks, n_req_chicks;
		LL barn, time;
		cin >> n_chicks >> n_req_chicks >> barn >> time;
		for( int i = 0; i < n_chicks; ++i ) {
			cin >> x[i];
		}
		for( int i = 0; i < n_chicks; ++i ) {
			cin >> v[i];
		}
		int n_fin_chicks = 0;
		int n_slower_chicks = 0;
		int n_swaps = 0;
		for( int i = n_chicks-1; i >= 0 && n_fin_chicks < n_req_chicks; --i ) {
			LL pos = x[i] + time * v[i];
			if( pos >= barn ) {
				n_swaps += n_slower_chicks;
				++n_fin_chicks;
			} else {
				++n_slower_chicks;
			}
		}
		cout << "Case #" << caseid << ": ";
		if( n_fin_chicks >= n_req_chicks ) cout << n_swaps << endl;
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
