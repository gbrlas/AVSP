#include <cstdio>
#include <string>
#include <set>
using namespace std;

#define MP make_pair
const int MAXN = 2048;
struct SS {int len, left; set<pair<int,int> > req;} a[MAXN];
int ans[MAXN];
set<pair<int,int> >::iterator itr, tmp_itr;
int m, n;

inline void clear(int id, int t1, int t2) {
	int tmp1, tmp2;
	for (itr = a[id].req.begin() ; itr != a[id].req.end() ; ) {
		tmp1 = itr->first;
		tmp2 = itr->second;
		if (tmp1 == t1 && tmp2 == t2) {
			a[id].req.clear();
			return;
		} else if (tmp1 == t1 && a[id].req.size() > 1) {
			tmp_itr = itr;
			++itr;
			a[id].req.erase(tmp_itr);
		} else ++itr;
	}
}

void output() {
	int i;
	printf("*****\n");
	for (i = 0 ; i < m ; i++) {
		for (itr = a[i].req.begin() ; itr != a[i].req.end() ; ++itr)
			printf("[%d,%d]",itr->first,itr->second);
		printf("\n");
	}
}

int main() {
	int T, i, j, t1, t2, ca = 0;
	int solved;

	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		for (i = 0 ; i < m ; i++) {
			a[i].req.clear();
			scanf("%d",&a[i].len);
			for (j = 0 ; j < a[i].len ; j++) {
				scanf("%d%d",&t1,&t2);
				a[i].req.insert(MP(t1-1,t2));
			}
			a[i].left = a[i].len;
		}
		memset(ans, -1, sizeof(ans));
		solved = 0;
		while (1) {
			//output();
			for (i = 0 ; i < m ; i++)
				if (a[i].req.size() == 1) break;
			if (i == m) {solved = 1; break;}
			t1 = a[i].req.begin()->first;
			t2 = a[i].req.begin()->second;
			//printf("t1:%d t2:%d\n",t1,t2);
			//while (1);
			if (t2 == 0) {
				if (ans[t1] == 1) break;
				if (ans[t1] == -1) {
					ans[t1] = 0;
					for (i = 0 ; i < m ; i++)
						clear(i, t1, t2);
				}
			} else if (t2 == 1) {
				if (ans[t1] == 0) break;
				if (ans[t1] == -1) {
					ans[t1] = 1;
					for (i = 0 ; i < m ; i++)
						clear(i, t1, t2);
				}
			}
		}
		printf("Case #%d:",++ca);
		if (solved) {
			for (i = 0 ; i < n ; i++)
				if (ans[i] == -1) ans[i] = 0;
			for (i = 0 ; i < n ; i++)
				printf(" %d",ans[i]);
			printf("\n");
		} else printf(" IMPOSSIBLE\n");

	}
	return 0;
}
