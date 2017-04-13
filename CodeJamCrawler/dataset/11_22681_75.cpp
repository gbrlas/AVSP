#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

char tab[10];

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int testcase = 1; testcase <= lz; testcase++){
		int n;
		scanf("%d", &n);
		int posO = 1;
		int posB = 1;
		int accO = 0;
		int accB = 0;
		int res = 0;
		for ( int i =0; i < n; i++){
			int x;
			scanf("%s %d", tab, &x);
			if ( tab[0] == 'O' ){
				int req = abs(posO-x);
				int passed = max(0, req-accO)+1;
				accO = 0;
				accB += passed;
				res += passed;
				posO = x;
			} 
			else if ( tab[0] == 'B'){
				int req = abs(posB-x);
				int passed = max(0, req-accB)+1;
				accB = 0;
				accO += passed;
				res += passed;
				posB = x;			
			}
			else {
				assert(false);
			}
			
		}
		printf("Case #%d: %d\n", testcase, res);
	}
	return 0;
}
