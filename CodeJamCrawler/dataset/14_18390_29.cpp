//============================================================================
// Name        : Round2_A.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d[10011];

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		int n, cap;
		cin >> n >> cap;
		for(int i=0; i<n; ++i) cin >> d[i];
		sort(d, d+n);
		int a = 0, b = n-1, ans = 0;
		while(a <= b) {
			while(a<b && d[a]+d[b]>cap) {
				--b;
				++ans;
			}
			if(a<b) {
				--b;
			}
			++ans;
			++a;
		}
		printf("Case #%d: ", cid);
		cout << ans << endl;
	}
	return 0;
}
