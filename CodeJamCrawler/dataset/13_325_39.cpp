#include <cstdio>
#include <algorithm>
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n;
LL m;

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		scanf("%d %I64d", &n, &m);
		
		if(m == 1LL << n) printf("%I64d %I64d\n", m - 1, m - 1);
		else{
			m--;
			
			int ans = 1;
			for(int i = n - 1; i >= 0; i--){
				if(m & 1LL << i) ans++;
				else break;
			}
			printf("%I64d ", (1LL << ans) - 2);
			
			m = (1LL << n) - 1 - m;
			ans = 0;
			LL tmp = 0;
			for(; ; ans++){
				if(tmp >= m) break;
				tmp += 1LL << n - ans - 1;
			}
			printf("%I64d\n", (1LL << n) - (1LL << ans));
		}
	}
	scanf("\n");
}
