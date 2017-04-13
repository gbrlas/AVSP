#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 44;

char g[maxn][maxn];
int p[maxn];
int task, cs=0, n;

bool check(){
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if ( g[ p[i] ][ j ]=='1' ) return false;
	return true;
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for( scanf("%d", &task); task--; ){
			scanf("%d", &n);
			for (int i=0; i<n; i++){
				scanf("%s", g[i]);
				p[i] = i;
			}
			int ret = 1000000000, nw;
			do{
				if ( !check() ) continue;
				nw = 0;
				for (int i=0; i<n; i++)
				for (int j=i+1;j<n; j++)
				if ( p[i]>p[j] ) nw++;
				ret = min( ret, nw );
			}while( next_permutation( p, p+n ) );
			printf("Case #%d: %d\n", ++cs, ret);
	}
	return 0;
}
