#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		int n; cin >> n;	
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			if (x != i) cnt++;
		}
		cout << "Case #" << zzz << ": " << cnt << endl;
	}
	
	return 0;
}
