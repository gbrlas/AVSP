#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[111];
int main(){
	//freopen("c.in","r",stdin);
	//freopen("c_s.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		int n, l, h;
		memset(a, 0, sizeof(a));
		scanf("%d %d %d", &n, &l, &h);
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		int ans = 12345678;
		for(int val = l; val <= h; val++){
			bool ok = true;
			for(int i=0; i<n; i++){
				if(!(val%a[i] == 0 || a[i]%val == 0))
					ok = false;
			}
			if(ok) ans = min(ans, val);
		}
		printf("Case #%d: ", tc);
		if(ans == 12345678) printf("NO\n");
		else printf("%d\n", ans);
	}
	return 0;
}