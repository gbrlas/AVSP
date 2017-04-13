#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 107

char G[MAX+7][MAX+7];
long Row,Col;

bool Pos( void )
{
	long i,j;
	for( i=1;i<=Row;i++){
		for( j=1;j<=Col;j++){
			if( G[i][j]=='#') return false;
		}
	}
	return true;
}

int main( void )
{
	long i,j,Icase,k = 0;

	freopen("A.in","r",stdin );
	freopen("A.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld%ld",&Row,&Col );
		for( i=1;i<=Row;i++){
			for( j=1;j<=Col;j++){
				scanf(" %c",&G[i][j] );
			}
		}

		for( i=1;i<Row;i++){
			for( j=1;j<Col;j++){
				if( G[i][j]!='#') continue;
				if( G[i+1][j]!='#') continue;
				if( G[i][j+1]!='#') continue;
				if( G[i+1][j+1]!='#') continue;
				G[i][j] = '/';
				G[i+1][j] = '\\';
				G[i][j+1] = '\\';
				G[i+1][j+1] = '/';
			}
		}
		printf("Case #%ld:\n",++k );
		if( !Pos()){
			printf("Impossible\n");
			continue;
		}

		for( i=1;i<=Row;i++){
			for( j=1;j<=Col;j++){
				printf("%c",G[i][j]);
			}
			printf("\n");
		}

	
	}

	return 0;
}

