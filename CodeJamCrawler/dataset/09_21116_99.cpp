#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=5010;

char a[maxn][20], s[10000];
bool fnd[20][30];
int l, d, n, ret;
bool ok;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d", &l, &d, &n);
	for (int i=0; i<d; i++) scanf("%s", a[i]);
	for (int i=1; i<=n; i++){
		scanf("%s", s);
		memset( fnd, 0, sizeof(fnd) );
		for (int q=0, j=0; q<l; q++){
			if ( 'a'<=s[j] && s[j]<='z' ){
				fnd[q][ s[j]-'a' ] = true;
				j++;
				continue;
			}
			j++;
			while ( 'a'<=s[j] && s[j]<='z' ){
				fnd[q][ s[j]-'a' ] = true;
				j++;
			}
			j++;
		}
		ret = 0;
		for (int j=0; j<d; j++){
			ok = true;
			for (int k=0; k<l; k++)
			if ( !fnd[k][ a[j][k]-'a' ] ){
				ok = false; break;
			}
			if ( ok ) ret++;
		}
		printf("Case #%d: %d\n", i, ret);
	}
	return 0;
}
