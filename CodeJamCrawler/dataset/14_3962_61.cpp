#include <iostream>
#include <algorithm>

using namespace std;

int cap[1<<16];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> cap[i];
		sort(cap,cap+n);
		int cnt = 0, pos2 = n-1, pos1 = 0;
		while (pos1 <= pos2){
			if (cap[pos1] + cap[pos2] > x){
				pos2--;
			}
			else{
				pos2--;
				pos1++;
			}
			cnt++;
		}
		cout << "Case #" << zz << ": " << cnt << endl;
	}	
	
	return 0;
}
