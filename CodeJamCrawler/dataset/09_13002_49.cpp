#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 300
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

int mat[300][300];
int match[2][300];
int sgn( int );
main(){
	freopen( "C.in", "r", stdin );
	freopen( "C.out", "w", stdout );
	
	int T, tt = 0;
	int i, j, k, n;
	int m;
	int a[100][100];
	int ret;
	
	scanf ( "%d", &T );
	while( T -- ){
		scanf ( "%d %d", &n, &m );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < m; j ++ )
				scanf ( "%d", &a[i][j] );
		
		memset ( mat, 0, sizeof ( mat ) );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < n; j ++ ){
				for ( k = 1; k < m; k ++ )
					if ( sgn( a[i][k] - a[j][k] ) * sgn( a[i][ k - 1 ] - a[j][ k - 1 ] ) <= 0 )
						break;
				if ( k == m && a[i][0] > a[j][0] )
					mat[i][j] = 1;
				else
					mat[i][j] = 0;
			}
		
		printf( "Case #%d: %d\n", ++ tt, n - hungary( n, n, mat, match[0], match[1] ) );
	}
	
	return 0;
}

int sgn( int x ){
	if ( x == 0 )
		return 0;
	if ( x < 0 )
		return -1;
	return 1;
}
