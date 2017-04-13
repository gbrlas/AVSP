#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

char wd[128][64];
int cnt[128][30];
const int MOD = 10009;
int ans[128];
int n;
int tt[30];
char buf[1024];
vector<int> form[128];
int len;
int tot;

void solve(int p, int k) {
	int i, j;
	if (p == k) {
		for (j = 0 ; j < 26 ; j++) {
			tt[j] = 0;
			for (i = 0 ; i < k ; i++) {
				tt[j] += cnt[ans[i]][j];
			}
		}
		for (i = 0 ; i < len ; i++) {
			int tmp = 1;
			for (j = 0 ; j < form[i].size() ; j++) {
				tmp *= tt[form[i][j]];
				tmp %= MOD;
			}
			tot += tmp;
			tot %= MOD;
		}
		return ;
	}
	for (i = 0 ; i < n ; i++) {
		ans[p] = i;
		solve(p+1, k);
	}
}

int main() {
	freopen("b-small.in","r",stdin);
	freopen("b-small.out","w",stdout);
	int T, ca = 0, i, j, k, K;
	scanf("%d",&T);
	while (T--) {
		scanf("%s%d",buf,&K);
		for (i = 0 ; i < 100 ; i++)
			form[i].clear();
		for (i = 0 , len = 0 ; buf[i] ; i++) {
			if (buf[i] == '+') {++len; continue;}
			form[len].push_back(buf[i]-'a');
		}
		++len;
		scanf("%d",&n);
		memset(cnt, 0, sizeof(cnt));
		for (i = 0 ; i < n ; i++) {
			scanf("%s",wd[i]);
			for (j = 0 ; wd[i][j] ; j++)
				++cnt[i][wd[i][j]-'a'];
		}
		printf("Case #%d:",++ca);
		for (k = 1 ; k <= K ; k++) {
			tot = 0;
			solve(0,k);
			printf(" %d",tot);
		}
		printf("\n");
	}
	return 0;
}
