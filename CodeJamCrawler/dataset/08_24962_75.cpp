#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
char name[128][128], q[1024][128];
char buf[128];
int dp[1024][128];
map<string,int> name2id;

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T, S, Q, i, j, k, ans, ca = 0;
	scanf("%d",&T);
	while (T--) {
		name2id.clear();
		scanf("%d",&S);
		gets(buf);
		for (i = 0 ; i < S ; i++) {
			gets(name[i]);
			name2id[(string)name[i]] = i;
		}
		memset(dp, 0x3f, sizeof(dp));
		scanf("%d",&Q);
		gets(buf);
		for (i = 0 ; i < Q ; i++) {
			gets(q[i]);
			if (i) {
				for (j = 0 ; j < S ; j++) {
					if (dp[i-1][j] >= INF) continue;
					for (k = 0 ; k < S ; k++) {
						if (name2id[(string)q[i]] != name2id[(string)name[k]])
							dp[i][k] <?= dp[i-1][j] + (j != k);
					}
				}
			} else {
				for (j = 0 ; j < S ; j++)
					if (name2id[(string)q[i]] != name2id[(string)name[j]])
						dp[i][j] = 0;
			}
		}
		if (Q == 0) {ans = 0;}
		else {
		ans = INF;
		for (j = 0 ; j < S ; j++)
			ans <?= dp[Q-1][j];
		}
		printf("Case #%d: %d\n",++ca,ans);
	}
	return 0;
}
