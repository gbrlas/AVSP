#include <cstdio>
#define REP(i,n) for(int i = 0;i<n;i++)

using namespace std;

char tab[6000][20];

int main() {
	int L, D, N;
	scanf("%d %d %d", &L, &D, &N);
	REP(i,D) scanf("%s", tab[i]);
	char s[2000];
	REP(i,N) {
		scanf("%s", s);
		int res=0;
		REP(j,D) {
			res++;
			for(int l=0,k=0;k<L;k++) {
				if(s[l]=='(') {
					bool g=false;
					while(s[l]!=')') {
						if(s[l]==tab[j][k]) {
							g=true;
						}
						l++;
					}
					if(g==false) {
						res--;
						break;
					}
					l++;
				}
				else if(s[l]!=tab[j][k]) {
					res--;
					break;
				}
				else {
					l++;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}
