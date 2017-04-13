#include <cstdio>
#include <algorithm>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, m, n, ans, num, par[10], t[5][100][26], cnt[5];
char s[12][12];

void odp(int x){
	if(x == m){
		fi(i, 0, n){
			cnt[i] = 1;
			fi(j, 0, 26) t[i][1][j] = 0;
		}
		
		int use = 0;
		
		fi(i, 0, m){
			int r = 1;
			use |= 1 << par[i];
			for(int j = 0; s[i][j]; j++){
				if(!t[par[i]][r][s[i][j] - 'A']){
					t[par[i]][r][s[i][j] - 'A'] = ++cnt[par[i]];
					fi(j, 0, 26) t[par[i]][cnt[par[i]]][j] = 0;
				}
					
				r = t[par[i]][r][s[i][j] - 'A'];
			}
		}
		
		if(use + 1 != (1 << n)) return;
		
		int sum = 0;
		fi(i, 0, n) sum += cnt[i];
		
		if(sum == ans) num++;
		else if(sum > ans){
			num = 1;
			ans = sum;
		}
		
		return;
	}
	
	fi(i, 0, n){
		par[x] = i;
		odp(x + 1);
	}
}

void solve(){
	scanf("%d %d", &m, &n);
	fi(i, 0, m) scanf("%s", s[i]);
	
	ans = 0;
	odp(0);
	
	printf("%d %d\n", ans, num);
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
