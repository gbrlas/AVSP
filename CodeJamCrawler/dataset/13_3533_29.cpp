#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;

ll n, p;

bool low_can_win (ll val){
	ll nn = n, pp = p;
	//cout << "val = " << val << endl;
	while (nn > 1){
		if (val == 0) return true;
		ll lim = (1LL << nn);
		if (pp == lim) return true;
		if (val == lim-1) return false;
		if (pp <= lim/2) return false;
		val = (val - 1) / 2;
		if (val < 0) val = 0;
		pp -= lim/2;
		nn--;
		//cout << "nn = " << nn << ", pp = " << pp << ", val = " << val << endl;
	}
	return (pp == 2 || val == 0);
}

bool high_can_win (ll val){
	ll nn = n, pp = p;
	while (nn > 1){
		if (val == 0) return true;
		ll lim = (1LL << nn);
		if (pp == lim) return true;
		if (val == lim-1) return false;
		if (pp > lim/2){
			return true;
		}
		else{
			val = (val+1)/2;
			nn--;
		}
		
	}
	return (pp == 2 || val == 0);
}

int main(){
	int zz; cin >> zz;
	for (int tt = 1; tt <= zz; tt++){
		cin >> n >> p;
		ll lim = (1LL << n);
		
		int cnt = 0;
		for (int i = n-1; i >= 0; i--){
			if ((1 << i) & (p-1)){
				cnt++;
			}
			else break;
		}
		/*ll low = 1;
		while (cnt--){
			low = low * 2 + 1;
		}
		low--;
		
		ll high = (1LL <<n)-p;*/
		
		// binary search
		
		ll mi = 0, ma = lim-1;
		ll low = (mi + ma + 1)/2;
		ll high = (mi + ma + 1)/2;
		
		while (ma > mi){
			bool okay = low_can_win(low);
			if (okay){
				mi = low;
				low = (mi + ma + 1) / 2;
			}
			else{
				ma = low - 1;
				low = (mi + ma + 1) / 2;
			}
		}
		
		mi = 0, ma = lim - 1;
		
		while (ma > mi){
			bool okay = high_can_win(high);
			if (okay){
				mi = high;
				high = (mi + ma + 1) / 2;
			}
			else{
				ma = high - 1;
				high = (mi + ma + 1) / 2;
			}
		}
		
		cout << "Case #" << tt << ": " << low << " " << high << endl;
	}	
	
	return 0;
}
