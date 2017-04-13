#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int testcase = 1; testcase <= lz; testcase++){
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for ( int i = 0; i < n; i++) scanf("%d", &v[i]);
		
		int smallest = 1000000000;
		int sum = 0;
		int ksor = 0;

		for ( int i =0; i < n; i++){
			ksor ^= v[i];
			smallest = min(smallest, v[i]);
			sum += v[i];
		}
		
		if ( ksor != 0 ){
			printf("Case #%d: NO\n", testcase);
		}
		else {
			printf("Case #%d: %d\n", testcase, sum-smallest);
		}
	}
	return 0;
}
