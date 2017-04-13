#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)
#define ll long long

using namespace std;

long long N, M, A;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> N >> M >> A;
		ll x1 = 0, y1 = 0;
		ll x2 = 0, y2 = 0;
		ll x3 = 0, y3 = 0;
		for(x2 = 0; x2 <= N; ++x2)
			for(y2 = 0; y2 <= M; ++y2)
				for(x3 = 0; x3 <= N; ++x3)
					for(y3 = 0; y3 <= M; ++y3) {
						ll AA = abs(x2 * y3 - y2 * x3);
						if(AA == A) {
							goto end;
						}
					}
		cout << "Case #" << (t + 1) << ": IMPOSSIBLE" << endl;
		continue;
		end:;
		cout << "Case #" << (t + 1) << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
	}
	return 0;
}
