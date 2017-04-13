#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int nwd(int a, int b){
	if ( a == 0 ) return b;
	else return nwd( b%a, a);
}

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int test = 1; test <= lz; test++){
		int n, l, h;
		scanf("%d%d%d", &n, &l, &h);
		vector<int> playa(n);
		for ( int i = 0; i < n; i++){
			scanf("%d", &playa[i]);
		}
		
		int res = -1;
		for ( int s = l; s <= h && res == -1; s++){
			bool good = true;
			for ( int i = 0; i < n && good; i++){
				if ( playa[i]%s != 0 && s%playa[i] != 0) good = false;
			}
			if ( good) res = s;
		}
		
		if ( res == -1) printf("Case #%d: NO\n", test);
		else printf("Case #%d: %d\n", test, res);
		
		
	}
	return 0;
}
