//============================================================================
// Name        : Round2_B.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int orig[1011], d[1011], p[1011];

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		int n, maxNum = 0, maxIndex = -1;
		int ans = INT_MAX;
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> orig[i];
			if(maxNum < orig[i]) {
				maxNum = orig[i];
				maxIndex = i;
			}
		}
		memcpy(d, orig, sizeof(orig));
		sort(d, d+n);
		do {
			int t = 0, num = 0;
			while(t+1<n && d[t]<d[t+1]) ++t;
			while(t+1<n && d[t]>d[t+1]) ++t;
			if(t!=n-1) continue;
			memcpy(p, orig, sizeof(orig));
			for(int i=0; i<n; ++i) {
				if(p[i]==d[i]) continue;
				int j=i+1;
				while(p[j]!=d[i]) ++j;
				for(int k=j; k>i; --k) {
					++num;
					swap(p[k], p[k-1]);
				}
			}
			if(num<ans) ans = num;
		} while(next_permutation(d, d+n));
		/*int ans = INT_MAX;
		for(int t=0; t<n; ++t) {
			memcpy(d, orig, sizeof(orig));
			int num = 0;
			if(t<maxIndex) {
				for(int i=maxIndex; i>t; --i) swap(d[i], d[i-1]);
				num += (maxIndex-t);
			} else {
				for(int i=maxIndex; i<t; ++i) swap(d[i], d[i+1]);
				num += (t-maxIndex);
			}
			for(int i=0; i<t; ++i)
				for(int j=i+1; j<t; ++j)
					if(d[j-1]>d[j]) {
						swap(d[j-1], d[j]);
						++num;
					}
			for(int i=t+1; i<n; ++i)
				for(int j=i+1; j<n; ++j)
					if(d[j-1]<d[j]) {
						swap(d[j-1], d[j]);
						++num;
					}
			if(num < ans) ans = num;
		}*/
		printf("Case #%d: ", cid);
		cout << ans << endl;
	}
	return 0;
}
