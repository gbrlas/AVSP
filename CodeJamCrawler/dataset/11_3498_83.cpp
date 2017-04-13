#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef double ld;

int x, s, r, t, n;

pair<ld,ld> walkway[1<<11];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> x >> s >> r >> t >> n;
		r -= s;
		int total = x;
		for (int i = 0; i < n; i++){
			int t1, t2, sp;
			cin >> t1 >> t2 >> sp;
			walkway[i] = make_pair(sp+s,t2-t1);
			x -= (t2-t1);
		}
		walkway[n] = make_pair(s,x);
		sort(walkway,walkway+n+1);
		ld left = t;
		ld ans = 0;
		for (int i = 0; i <= n; i++){
			if (left > 0){
				ld best = min(walkway[i].second/(ld)(walkway[i].first+r),left);
				left -= best;
				ans += best + (walkway[i].second - best*(walkway[i].first+r))/(ld)(walkway[i].first);
			}
			else{
				ans += walkway[i].second / (ld) walkway[i].first;
			}
		}
		cout << "Case #" << zz << ": " << setprecision(10) << ans << endl;
	}
	
	return 0;
}
