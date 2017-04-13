#include <cstdio>
#include <cstring>

using namespace std;

const int a[4]={-1, 0, 0, 1};
const int b[4]={0, -1, 1, 0};

int num[200][200];
int fa[20000];
int wh[20000];
int h[200][200];
int n, m;
int tot;

int get_fa( int x ){
	int ff=x;
	while ( fa[ff]>=0 ) ff=fa[ff];
	while ( fa[x]>=0 ){
		int t=fa[x]; fa[x]=ff; x=t;
	}
	return ff;
}

void combine( int x, int y ){
	int fax=get_fa(x), fay=get_fa(y);
	if ( fax!=fay )
		fa[fax]=fay;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for ( int T=1; T<=test; T++ ){
		printf("Case #%d:\n", T);
		scanf("%d %d", &n, &m);
		tot=0;
		memset( fa, -1, sizeof( fa ) );
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<m; j++ ){
				scanf("%d", &h[i][j]);
				num[i][j]=tot++;
			}
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<m; j++ ){
				int minn=100000, t=0;
				for ( int k=0; k<4; k++ ){
					int x=i+a[k], y=j+b[k];
					if ( x>=0 && x<n && y>=0 && y<m && h[x][y]<minn){
						minn=h[x][y]; t=num[x][y];
					}
				}
				if ( minn<h[i][j] )
					combine( num[i][j], t );
			}
		memset( wh, -1 ,sizeof( wh ) );
		tot=0;
		for ( int i=0; i<n; i++ ){
			for ( int j=0; j<m; j++ ){
				int t=get_fa(num[i][j]);
				if ( wh[t]==-1 ) wh[t]=tot++;
				if ( j!=0 ) printf(" ");
				printf("%c", 'a'+wh[t]);
			}
			printf("\n");
		}
	}
}
