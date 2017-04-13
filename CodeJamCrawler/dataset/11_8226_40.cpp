#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int TTT; cin >> TTT;
	for (int ZZZ=1;ZZZ<=TTT;ZZZ++) {
		long long L, t, N, C; cin >> L >> t >> N >> C;
		
		vector<long long> d;
		for (int i=0; i < C; i++) {
			long long temp; cin >> temp;
			temp *= 2;
			d.push_back(temp);
		}
		
		long long time = 0;
		int cutoff_idx = -1;
		int on_cutoff=0;
		
		for (int i=0; i < N; i++){
			time += d[i%C];
			if (cutoff_idx == -1 && time > t) {
				cutoff_idx = i+1;
				on_cutoff = d[i%C]-(t-(time-d[i%C]));
			}
		}
		
		if (cutoff_idx == -1) {
		} else {
			map<long long, int> ss;
			for (int i=0; i < C; i++) {
				ss[d[i]] = 0;
			}
			
			int j = 0, i;
			for (i=cutoff_idx%C; i != 0 && cutoff_idx+j<N; i = (i+1)%C, j++) {
				ss[d[i]] = 1;
			}
			int count = (N-(cutoff_idx+j))/C;
			for (int k=0; k < C; k++) {
				ss[d[k]]+=count;
			}
			for (i=cutoff_idx+j+C*count; i < N; i++) {
				ss[d[i%C]]++;
			}
			if (ss.find(on_cutoff) != ss.end()) {
				ss[on_cutoff]++;
			} else {
				ss[on_cutoff] = 1;
			}
			
			for (map<long long, int>::iterator it = ss.end(); it-- != ss.begin();) {
				time -= it->first/2*min(L, (long long)(it->second));
				L -= min(L, (long long)(it->second));
			}
		}
	
		cout << "Case #" << ZZZ << ": " << time << endl;
	}
}