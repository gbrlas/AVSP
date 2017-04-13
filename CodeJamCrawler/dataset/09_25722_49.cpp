#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 128;
vector<int> mp[MAXN];
int link[MAXN],cover[MAXN];

int find(int k,int flg)
{
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

int solve(int m,int n)
{
	int i, s = 0;
	memset(link,-1,sizeof(link));
	memset(cover,-1,sizeof(cover));
	for (i = 0 ; i < m ; i++) {
		if (find(i,i)) ++s;
	}
	return s;
}

int a[MAXN][MAXN];
int main() {
	freopen("c-small.in","r",stdin);
	freopen("c-small.out","w",stdout);
	int T, n, k, i, j, t, ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		for (i = 0 ; i < n ; i++)
			for (j = 0 ; j < k ; j++)
				scanf("%d",&a[i][j]);
		for (i = 0 ; i < n ; i++) {
			mp[i].clear();
			for (j = 0 ; j < n ; j++) {
				for (t = 0 ; t < k ; t++)
					if (a[i][t] >= a[j][t]) break;
				if (t == k) mp[i].push_back(j);
			}
		}
		printf("Case #%d: ",++ca);
		printf("%d\n",n-solve(n,n));
	}
	return 0;
}
