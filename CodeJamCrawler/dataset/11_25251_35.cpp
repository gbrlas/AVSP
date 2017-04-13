#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 107

char G[MAX+7][MAX+7];
long N;

double WP[MAX+7],OWP[MAX+7],OOWP[MAX+7];
long AG[MAX+7];

int main( void )
{
	long i,j,k,Icase,Kse = 0;

	freopen("A.in","r",stdin );
	freopen("A.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld",&N );
		for( i=1;i<=N;i++){
			for( j=1;j<=N;j++){
				scanf(" %c",&G[i][j] );
			}
		}

		for( i=1;i<=N;i++){
			long C=0,W=0;
			for( j=1;j<=N;j++){
				if( G[i][j]=='.') continue;
				C++;
				if( G[i][j]=='1') W++;
			}
			WP[i] = (double)W/C;
			AG[i] = C;
		}

		for( i=1;i<=N;i++){
			OWP[i] = 0;
			for( j=1;j<=N;j++){
				bool Played = false;
				long C = 0,W = 0;
				for( k=1;k<=N;k++){
					if( G[j][k]=='.') continue;
					if( k==i){
						Played = true;
						continue;
					}
					C++;
					if( G[j][k]=='1') W++;
				}
				if( Played) OWP[i] += (double)W/C;


			}
			OWP[i] /= AG[i];
		}

		for( i=1;i<=N;i++){
			OOWP[i] = 0;
			for( j=1;j<=N;j++){
				if( G[i][j]=='.') continue;
				OOWP[i] += OWP[j];
			}
			OOWP[i] /= AG[i];
		}

		printf("Case #%ld:\n",++Kse );
		for( i=1;i<=N;i++){
			double Ans = 0.25*WP[i] + 0.50*OWP[i] + 0.25*OOWP[i];
			printf("%.12lf\n",Ans );
		}
	}

	return 0;
}

