//============================================================================
// Name        : Round2_D.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, p, worst, num;
int partitions[10];
string s[10];

void dfs(int cur, int used) {
	if(cur == p) {
		if(used != (1<<n)-1) return;
		int size = 0;
		for(int q=0; q<p; ++q) {
			//cout << partitions[q] << ' ';
			set<string> strset;
			for(int i=0; i<n; ++i)
				if((partitions[q]>>i)&1) {
					for(int j=1; j<=s[i].size(); ++j) strset.insert(s[i].substr(0, j));
				}
			//for(set<string>::iterator it = strset.begin(); it != strset.end(); ++it) cout<< *it << " ";
			size += strset.size()+1;
			//cout << strset.size() << "  ";
		}
		//cout << endl;
		if(worst<size) {
			worst = size;
			num = 1;
		} else if(worst==size) {
			++num;
		}
		return;
	}
	for(int pat = 1; pat<(1<<n); ++pat) {
		if(used & pat)
			continue;
		partitions[cur] = pat;
		dfs(cur+1, used|pat);
	}
}

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		cin >> n >> p;
		for(int i=0; i<n; ++i) cin >> s[i];
		worst = -1;
		num = 0;
		dfs(0, 0);
		printf("Case #%d: %d %d\n", cid, worst, num);
	}
	return 0;
}
