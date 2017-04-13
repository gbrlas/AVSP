#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int inf = 1000000000;
int next[1<<13];
int height[1<<13];

bool assign(int pos, int last, int slope){
	//cout << "assigning pos = " << pos << ", last = " << last << ", slope = " << slope << endl;
	if (pos == last) return true;
	if (next[pos] > last) return false;
	if (next[pos] == last){
		height[pos] = height[last] - slope*(last-pos) - 1;
		return assign(pos+1,last,slope);
	}
	int cx = next[pos];
	if (!assign(cx,last,slope)) return false;
	slope = (height[next[cx]]-height[cx] + next[cx]-cx -1)/(next[cx]-cx);
	height[pos] = height[cx] - slope*(cx-pos);
	return assign(pos+1,cx,slope);
}

int main(){
	int t; cin >> t;
	
	for (int zz = 1; zz <= t; zz++){
		int n; cin >> n;
		for (int i = 0; i < n-1; i++){
			cin >> next[i];
			next[i]--;
		}
		//cout << "here0; n = " << n << endl;
		memset(height,0,sizeof(height));
		bool okay = true;
		for (int i = 0; i < n-1; i = next[i]){
			height[i] = inf;
			height[next[i]] = inf;
			if (!assign(i+1,next[i],0)){
				okay = false;
				break;
			}
		}
		if (!okay)
			cout << "Case #" << zz << ": Impossible" << endl;
		else {
			cout << "Case #" << zz << ":";
			for (int i = 0; i < n; i++)
				cout << " " << height[i];
			cout << endl;
		}
		//cout << "here" << endl;
	}
	
	return 0;
}
