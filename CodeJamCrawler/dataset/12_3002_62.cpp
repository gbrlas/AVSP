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

int n;
pair<int,int> vines[1<<14];
int d[1<<14];
int l[1<<14];
bool reached[1<<14];
int len[1<<14];

bool dfs(int pos){
	reached[pos] = true;
	if (pos == n) return true;
	for (int i = 0; i < n; i++)
		if (!reached[pos] && l[i]>=abs(d[i]-d[pos])){
			if (dfs(i)) return true;
		}
	return false;
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			vines[i].first = x;
			vines[i].second = y;
		}
		sort(vines,vines+n);
		int D; cin >> D;
		vines[n].first = D; vines[n].second = 0;
		for (int i = 0; i <= n; i++){
			d[i] = vines[i].first;
			l[i] = vines[i].second;
		}
		memset(reached,false,sizeof(reached));
		memset(len,0,sizeof(len));
		
		len[0] = d[0];
		
		bool okay = false;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j <= n; j++){
				if (d[i]+len[i] < d[j]) break;
				if (j == n) okay = true;
				len[j] = max(len[j],min(l[j],d[j]-d[i]));
			}
			if (okay) {
				break;
			}
		}
		/*for (int i = 0; i < n; i++)
			cout << len[i] << " ";
		cout << endl;*/
		cout << "Case #" << zz << ": ";
		if (okay) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
