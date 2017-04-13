#include <cstdio>
#include <algorithm>
#define N 20
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, x;
double dp[1 << N], p;
char s[30];

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%s", s);
		x = 0;
		for(n = 0; s[n]; n++){
			if(s[n] == 'X') x |= 1 << n;
		}
		
		fi(i, 0, 1 << n) dp[i] = 0;
		dp[x] = 1;
		p = 0;
		
		fi(i, x, (1 << n) - 1){
			if((x & i) != x) continue;
			fi(j, 0, n){
				int w = n, t = j;
				while(i & (1 << t)) t = (t + 1) % n, w--;
				dp[i | 1 << t] += dp[i] / (double) n;
				p += dp[i] / (double) n * w;
			}
		}
		
		printf("Case #%d: %.10lf\n", z, p);
	}
	scanf("\n");
}
