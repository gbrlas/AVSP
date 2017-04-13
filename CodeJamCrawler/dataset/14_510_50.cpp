#include <cstdio>
#include <algorithm>
#define N 10005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int n, x, s, a, cnt[704], t;

void solve(){
	a = 0;
	scanf("%d %d", &n, &x);
	
	FI(i, 0, x) cnt[i] = 0;
	
	fi(i, 0, n){
		scanf("%d", &s);
		cnt[s]++;
	}

	FD(i, x, 1) while(cnt[i]){
		bool find = 0;
		FD(j, min(i, x - i), 1){
			if((j == i && cnt[j] > 1) || (j != i && cnt[j] > 0)){
				cnt[j]--;
				a++;
				find = 1;
				break;
			}
		}
		if(!find) a++;
		cnt[i]--;
	}
	
	printf("%d\n", a);
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
