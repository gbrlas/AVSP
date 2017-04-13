#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 44;

char g[maxn][maxn];
int p[maxn];
int task, cs=0, n;

bool check(int x, int y){
	for (int j=x+1; j<n; j++)
	if ( g[ y ][ j ]=='1' ) return false;
	return true;
}

int main(){
	freopen("A-large.in","r",stdin);
//	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	for( scanf("%d", &task); task--; ){
			scanf("%d", &n);
			for (int i=0; i<n; i++){
				scanf("%s", g[i]);
				p[i] = i;
			}
			int ret = 0, nw;
			for (int i=0; i<n; i++){
				for (int j=i; j<n; j++)
				if ( check( i, j ) ){
					ret += j-i;

					for (int x=0; x<n; x++)
						g[n][x] = g[j][x];
					for (int y=j; y>=i+1; y--)
						for (int x=0; x<n; x++)
							g[y][x] = g[y-1][x];
					for (int x=0; x<n; x++)
						g[i][x] = g[n][x];

					break;
				}
			}
			printf("Case #%d: %d\n", ++cs, ret);
	}
	return 0;
}
