#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 256;
struct SS {
	int s, e, flg;
} a[MAXN];
int na, nb;
int c1, c2;

inline int trans(int hh, int mm) {
	return hh * 60 + mm;
}

int link[MAXN],cover[MAXN];
vector <int> mp[MAXN];
int find(int k,int flg) {
	int i,q,j;
	for (i = 0 ; i < mp[k].size() ; i++) {
		j = mp[k][i];
		if (cover[j] != flg) {
			q = link[j];
			link[j] = k;
			cover[j] = flg;
			if (q == -1 || find(q,flg)) return 1;
			link[j] = q;
		}
	}
	return 0;
}

int solve(int m,int n) {
	int i, s = 0;
	memset(link,-1,sizeof(link));
	memset(cover,-1,sizeof(cover));
	for (i = 0 ; i < m ; i++)
		find(i,i);
	return s;
}

int main() {
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	int T, ca, t1, t2, t3, t4, i, j, tim;
	scanf("%d",&T);
	for (ca = 1 ; ca <= T ; ca++) {
		scanf("%d%d%d",&tim,&na,&nb);
		for (i = 0 ; i < na ; i++) {
			scanf("%d:%d %d:%d",&t1,&t2,&t3,&t4);
			a[i].s = trans(t1, t2);
			a[i].e = trans(t3, t4);
			a[i].flg = 0;
		}
		for (i = 0 ; i < nb ; i++) {
			scanf("%d:%d %d:%d",&t1,&t2,&t3,&t4);
			a[i+na].s = trans(t1, t2);
			a[i+na].e = trans(t3, t4);
			a[i+na].flg = 1;
		}

		for (i = 0 ; i < na + nb ; i++) {
			mp[i].clear();
			for (j = 0 ; j < na + nb ; j++) {
				if (a[i].flg + a[j].flg != 1) continue;
				//if (!a[i].flg && a[j].flg) {
					if (a[i].e + tim <= a[j].s) {
						//printf("i:%d j:%d\n",i,j);
						mp[i].push_back(j);
					}
				//} else if (a[i].flg && !a[j].flg) {
				//	if (a[j].e + tim <= a[i].s) {
				//		mp[i].push_back(j);
				//		printf("er?\n");
				//	}
				//}
			}
		}

		c1 = c2 = 0;
		solve(na+nb,na+nb);
		//for (i = 0 ; i < na+nb ; i++)
		//	printf("link[%d]:%d\n",i,link[i]);
		for (i = 0 ; i < na+nb ; i++)
			if (link[i] != -1) {
				if (a[i].flg == 0) ++c1;
				else ++c2;
			}
		printf("Case #%d: %d %d\n",ca,na-c1,nb-c2);
	}
	return 0;
}
