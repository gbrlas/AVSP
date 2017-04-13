#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn =  2010;

int task, p[maxn], ret[maxn];
int g[maxn][maxn], cur[maxn], n;
bool fnsh;

int gethight( int x, int lefti, int lefth, int righti, int righth ){
	int ss = (int)( righth-(double)(righth-lefth)*(double)(righti-x)/(double)(righti-lefti) )-1;		
	if (ss<0) while (true);
	return ss;
}

void doit(int s, int t, int lefti, int lefth, int righti, int righth){
	if ( fnsh ) return;
	if ( s>t ) return;

	if ( g[t][0]==0 ){
		if ( ret[t]<0 ) ret[t] = 0;
		doit( s, t-1, lefti, lefth, righti, righth );
		return;
	}
	if ( cur[t]>g[t][0] ){
		doit( s, t-1, lefti, lefth, righti, righth );
		return;
	}
	int x = g[t][cur[t]];
	cur[t]++;
	if ( !(s<=x && x<=t) ){
		fnsh = true;
		return;
	}
	if ( ret[t]<0 )
		ret[t] = gethight( t, lefti, lefth, righti, righth );
	if ( ret[x]<0 )
		ret[x] = gethight( x, lefti, lefth, righti, righth );

	doit( s, x, x, ret[x], t, ret[t] );
	doit( x, t, x, ret[x], t, ret[t] );
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%d", &n);
		fnsh = false;
		for (int i=1; i<=n; i++)
			g[i][0] = 0;
		for (int i=1; i<n; i++){
			scanf("%d", p+i);
			if ( p[i]<=i ) fnsh = true;
			g[p[i]][ ++g[p[i]][0] ] = i;
		}
		if ( fnsh ){
			printf("Case #%d: Impossible\n", cs);
			continue;
		}
		for (int i=1; i<=n; i++)
			cur[i] = 1;
		memset( ret, 255, sizeof(ret) );
		ret[0] = ret[n+1] = 1000000000;
		doit( 1, n, 0,1000000000, n+1, 1000000000 );
		if ( fnsh ){
			printf("Case #%d: Impossible\n", cs);
			continue;
		}
		printf("Case #%d: ", cs);
		for (int i=1; i<=n; i++){
			if ( i!=1 ) printf(" ");
			if ( ret[i]<0 ) while (true);
			printf("%d", ret[i]);
		}
		printf("\n");
	}
	return 0;
}
