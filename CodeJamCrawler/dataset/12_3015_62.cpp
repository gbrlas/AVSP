#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

typedef int ld;

int n;
ld l, w;
pair<ld,int> circ[1<<12];
ld solx[1<<12];
ld soly[1<<12];

int main(){
	int t; cin >> t;
	
	for (int zz = 1; zz <= t; zz++){
		cin >> n >> l >> w;
		for (int i = 0; i < n; i++){
			ld temp; cin >> temp;
			circ[i] = make_pair(temp,-i);
		}
		sort(circ,circ+n);
		
		ld cx = 0;
		ld cy = 0;
		ld nx = -circ[n-1].first;
		ld ny = circ[n-1].first;
		for (int i = n-1; i >= 0; i--){
			cx = nx + circ[i].first;
			if (cx > l) { //start a new line
				cx = 0;
				cy = ny + circ[i].first;
				nx = cx + circ[i].first;
				ny = cy + circ[i].first;
			}
			else{
				cx = nx + circ[i].first;
				nx = cx + circ[i].first;
			}
			assert(cx <= l);
			assert(cy <= w);
			solx[-circ[i].second] = cx;
			soly[-circ[i].second] = cy;
		}
		cout << "Case #" << zz << ":";
		for (int i = 0; i < n; i++){
			cout << " " << solx[i] << " " << soly[i];
		}
		cout << endl;
	}

	return 0;
}
