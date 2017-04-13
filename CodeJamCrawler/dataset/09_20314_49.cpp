#include <cstdio>

int m[50][50];
int n;

void change( int i, int j ){
	int t[50];
	for ( int k=0; k<n; k++ )
		t[k]=m[j][k];
	for ( int k=j; k>i; k-- )
		for ( int p=0; p<n; p++ )
			m[k][p]=m[k-1][p];
	for ( int k=0; k<n; k++ )
		m[i][k]=t[k];
}

int main(){
	int test=0;
	scanf("%d", &test);
	for ( int T=1; T<=test; T++ ){
		scanf("%d", &n);
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ ){
				char c;
				scanf(" %c", &c);
				m[i][j]=(c=='1');
			}
		int ans=0;
		for ( int i=0; i<n; i++ )
			for ( int j=i; j<n; j++ ){
				bool ok=true;
				for ( int k=i+1; k<n; k++ )
					if ( m[j][k] ){
						ok=false; break;
					}
				if ( ok ){
					//printf("%d\n", j);
					change( i, j );
					ans+=j-i;
					break;
				}
			}
		printf("Case #%d: %d\n", T, ans);
	}
}
