#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, a[N], b[N], p[N], bit[N], seq[N], cur[N], ans;

bool cmp(int a, int b){
	return a > b;
}

bool check(){
	bool mode = 0;
	fi(i, 0, n - 1){
		if(seq[i] < seq[i + 1]){
			if(mode) return 0;
		}else{
			mode = 1;
		}
	}
	
	return 1;
}

void solve(){
	scanf("%d", &n);
	fi(i, 0, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b + n);
	fi(i, 0, n) a[i] = lower_bound(b, b + n, a[i]) - b;
	/*
	fi(i, 0, n) printf("%d ", a[i]);
	puts("");
	*/
	ans = 1e9;
	fi(i, 0, n) seq[i] = i;
	do{
		if(!check()) continue;
		
		fi(j, 0, n) p[seq[j]] = j;
		
		fi(j, 0, n) cur[j] = p[a[j]];
		
		FI(j, 1, n) bit[j] = 0;
		int cal = n * (n - 1) / 2;
		fi(j, 0, n){
			for(int x = cur[j]; x; x -= x & -x) cal -= bit[x];
			for(int x = cur[j] + 1; x <= n; x += x & -x) bit[x]++;
		}
		
		ans = min(cal, ans);
		
	}while(next_permutation(seq, seq + n));
	
	printf("%d\n", ans);
}

int main(){
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
