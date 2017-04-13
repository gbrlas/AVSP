#include <iostream>

using namespace std;

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		int n; cin >> n;
		int sum = 0;
		int val = 0;	
		int min = 1000000000;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			sum += x; val ^= x;
			if (min > x) min = x;	
		}
		cout << "Case #" << zzz << ": ";
		if (val) cout << "NO" << endl;
		else cout << (sum-min) << endl;
	}
	
	return 0;
}
