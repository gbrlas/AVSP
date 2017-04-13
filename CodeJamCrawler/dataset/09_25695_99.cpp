#include <cstdio>
#include <string>
using namespace std;

char wd[5010][20];
int mk[128][26];
char buf[100010];

int main() {
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int L, d, n, i, j, k, p;
	scanf("%d%d%d",&L,&d,&n);
	for (i = 0 ; i < d ; i++)
		scanf("%s",wd[i]);
	for (i = 0 ; i < n ; i++) {
		memset(mk, 0, sizeof(mk));
		scanf("%s",buf);
		for (j = p = 0 ; j < L ; j++)
			if (buf[p] != '(') {mk[j][buf[p]-'a'] = 1; p++;}
			else {
				++p;
				while (buf[p] != ')') {
					mk[j][buf[p]-'a'] = 1;
					++p;
				}
				++p;
			}
		int ans = 0;
		for (j = 0 ; j < d ; j++) {
			for (k = 0 ; k < L ; k++)
				if (mk[k][wd[j][k]-'a'] == 0) break;
			if (k == L) ++ans;
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
