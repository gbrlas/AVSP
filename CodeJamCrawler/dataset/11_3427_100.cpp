#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		int p1 = 1, p2 = 1;	
		int t1 = 0, t2 = 0;
		int ans = 0;
		int n; cin >> n;
		for (int i = 0; i < n; i++){
			char c; int pos; cin >> c >> pos;
			if (c == 'O'){
				int cost = abs(p1-pos) - t1 + 1;
				if (cost < 1) cost = 1;
				ans += cost; t2 += cost; p1 = pos;
				t1 = 0;
			}
			else{
				int cost = abs(p2-pos) - t2 + 1;
				if (cost < 1) cost = 1;
				ans += cost; t1 += cost; p2 = pos;
				t2 = 0;
			}
			//cout << "ans = " << ans << endl;
		}
		cout << "Case #" << zzz << ": " << ans << endl;
	}
	return 0;
}
