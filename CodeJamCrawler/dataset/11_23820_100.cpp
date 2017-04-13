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

int main() {
	int cases;

	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		int n;
		cin >> n;
		int p[2] = {1,1};
		int t[2] = {0,0};
		for( int i = 0; i < n; ++i ) {
			string rob;
			int pos;
			cin >> rob >> pos;
			int x = (rob[0]=='O');
			t[x] += abs(p[x]-pos)+1;
			t[x] = max(t[x],1+t[1-x]);
			p[x] = pos;
		}
		cout << "Case #" << caseid << ": " << max(t[0],t[1]) << endl;
	}
	return 0;
}
