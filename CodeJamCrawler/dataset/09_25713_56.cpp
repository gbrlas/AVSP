#include <cstdio>
#include <string>
using namespace std;

char buf[128];
int cc[10];

int tryit(int pos) {
	int tcc[10], i, k;
	memcpy(tcc, cc, sizeof(cc));
	for (i = 0 ; i < pos ; i++)
		--tcc[buf[i]-'0'];
	for (k = buf[pos]-'0'+1 ; k < 10 ; k++)
		if (tcc[k]) break;
	if (k == 10) return 0;
	for (i = 0 ; i < pos ; i++)
		printf("%c",buf[i]);
	printf("%d",k);
	--tcc[k];
	for (i = 0 ; i < 10 ; i++)
		while (tcc[i]--)
			printf("%d",i);
	printf("\n");
	return 1;
}

int main() {
	freopen("b-small.in","r",stdin);
	freopen("b-small.out","w",stdout);
	int T, i, ca = 0;
	scanf("%d",&T);
	while (T--) {
		printf("Case #%d: ",++ca);
		scanf("%s",buf);
		memset(cc, 0, sizeof(cc));
		for (i = 0 ; buf[i] ; i++) {
			++cc[buf[i]-'0'];
		}
		int len = strlen(buf);
		for (i = len - 2 ; i >= 0 ; i--) {
			if (tryit(i)) break;
		}
		if (i < 0) {
			sort(buf, buf+len);
			for (i = 0 ; buf[i] == '0' ; i++) ;
			printf("%c",buf[i]);
			++cc[0];
			while (cc[0]--) printf("0");
			for (++i ; buf[i] ; i++)
				printf("%c",buf[i]);
			printf("\n");
		}
	}
	return 0;
}
