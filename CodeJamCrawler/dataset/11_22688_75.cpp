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
		for ( int i = 0; i < n; i++){
			scanf("%d", &v[i]);
			v[i]--;
		}
		
		double res = 0.0;
		for ( int i = 0; i < n; i++ ){
			if ( v[i] != -1 ){
				int cur = v[i];
				
				int len = 1;
				v[i] = -1;
				while(cur != i ){
					len++;
					int next = v[cur];
					v[cur] = -1;
					cur = next;
				}
				if(len!=1) res += len;
			}
			
		}
		
		printf("Case #%d: %lf\n", testcase, res);

	}
	return 0;
}
