#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200;

char s[maxn][100], st[50];
bool fnd[maxn], hv[50];
int task, CASE=0, n, m;

int calc( int o ){
	memset( fnd, 0, sizeof(fnd) );
	for (int i=0; i<n; i++)
	if ( o==i || strlen( s[i] )!=strlen( s[o] ) )
		fnd[i] = true;
	int ret = 0;
	for (int j=0; j<26; j++){
		bool ok1=false, ok2=false;
		for (int i=0; s[o][i]; i++)
		if ( s[o][i]==st[j] ){
			ok1 = true;
			break;
		}
		for (int k=0; k<n; k++)if ( !fnd[k] ){
			for (int i=0; s[k][i]; i++)
			if ( s[k][i]==st[j] ){
				ok2 = true;
				break;
			}
			if ( ok2 ) break;
		}
		if ( ok1 && !ok2 ) return ret;
		if ( !ok1 && !ok2 ) continue;
		if ( !ok1 && ok2 ){
			ret++;
			for (int k=0; k<n; k++)if ( !fnd[k] ){
				for (int i=0; s[k][i]; i++)
				if ( s[k][i]==st[j] ){
					fnd[k] = true;
					break;
				}
			}
		}else{
			memset( hv, 0, sizeof(hv) );
			for (int i=0; s[o][i]; i++)
			if ( s[o][i]==st[j] )
				hv[i] = true;

			for (int k=0; k<n; k++)if ( !fnd[k] ){
				for (int i=0; s[o][i]; i++)
				if ( hv[i] && s[k][i]!=st[j] ){
					fnd[k] = true;
					break;					
				}
				if ( !fnd[k] )
				for (int i=0; s[k][i]; i++)
				if ( s[k][i]==st[j] && !hv[i] ){
					fnd[k] = true;
					break;					
				}
			}
		}
	}
	return ret;
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++)
			scanf("%s", s[i]);
		printf("Case #%d:", ++CASE);
		while ( m-- ){
			scanf("%s", st);
			int ret = -1, retp = 0;
			for (int i=0; i<n; i++){
				int cur = calc( i );
//				cout<<i<<' '<<cur<<endl;
				if ( ret<cur ){
					ret = cur;
					retp = i;
				}
			}
			printf(" %s", s[retp]);
		}
		printf("\n");
	}
	return 0;
}
