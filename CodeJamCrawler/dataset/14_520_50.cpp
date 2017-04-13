#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, a[N], b[N], ans, l, r;

bool cmp(int a, int b){
	return a > b;
}

void solve(){
	scanf("%d", &n);
	fi(i, 0, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b + n);
	fi(i, 0, n) a[i] = lower_bound(b, b + n, a[i]) - b;

	ans = 0;
	l = 0, r = n - 1;
	
	fi(i, 0, n){
		fi(j, 0, n) if(a[j] == i){
			if(abs(j - l) <= abs(j - r)){
				fd(k, j, l) swap(a[k], a[k - 1]);
				ans += abs(j - l);
				l++;
			}else{
				fi(k, j, r) swap(a[k], a[k + 1]);
				ans += abs(j - r);
				r--;
			}
			break;
		}
	}
	
	printf("%d\n", ans);
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.odp", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
