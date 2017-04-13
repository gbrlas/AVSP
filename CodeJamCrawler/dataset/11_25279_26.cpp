#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


#define MAX 107

long Grid[MAX+7][MAX+7];
long R,C,D;

inline long min( long a,long b )
{
	return a<b ? a:b;
}

inline long max( long a,long b )
{
	return a>b ? a:b;
}

long FindODD( void )
{
	long l,i,j,m,n;
	for( l = min( R,C );l>=1;l--){
		//printf("%ld\n",l );
		for( i=1;i<=R;i++){
			for( j=1;j<=C;j++){
				long R1 = i-l;
				long R2 = i+l;
				long C1 = j-l;
				long C2 = j+l;
				if( R1<1 || R2>R || C1<1 || C2>C ) continue;
				long X=0,Y=0;//printf("%ld %ld %ld %ld %ld\n",R1,R2,C1,C2,l );
				for( m=R1;m<=R2;m++){
					for( n=C1;n<=C2;n++){
						if( m==R1 && n==C1 ) continue;
						if( m==R1 && n==C2 ) continue;
						if( m==R2 && n==C1 ) continue;
						if( m==R2 && n==C2 ) continue;
						X += (m-i)*Grid[m][n];
						Y += (n-j)*Grid[m][n];
					}
				}
				if( X==0 && Y==0 ) return 2*l+1;
			}
		}
	}
	return 0;
}


long FindEVEN( void )
{
	long l,i,j,m,n;
	for( l = min( R,C );l>=2;l--){
		//printf("%ld\n",l );
		for( i=1;i<=R;i++){
			for( j=1;j<=C;j++){
				long R1 = i-l+1;
				long R2 = i+l;
				long C1 = j-l+1;
				long C2 = j+l;
				if( R1<1 || R2>R || C1<1 || C2>C ) continue;
				long X=0,Y=0;//printf("%ld %ld %ld %ld %ld %ld %ld\n",R1,R2,C1,C2,l,i,j );
				for( m=R1;m<=R2;m++){
					for( n=C1;n<=C2;n++){
						if( m==R1 && n==C1 ) continue;
						if( m==R1 && n==C2 ) continue;
						if( m==R2 && n==C1 ) continue;
						if( m==R2 && n==C2 ) continue;
						if( m<=i ) X += (m-i-1)*Grid[m][n];
						else X += (m-i)*Grid[m][n];
						if( n<=j) Y += (n-j-1)*Grid[m][n];
						else Y += (n-j)*Grid[m][n];
						//printf("%ld %ld\n",X,Y );
					}
				}
				if( X==0 && Y==0 ) return 2*l;
			}
		}
	}
	return 0;
}
int main( void )
{
	long i,j,Icase,k=0;

	freopen("B.in","r",stdin );
	freopen("B.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld%ld%ld",&R,&C,&D );
		for( i=1;i<=R;i++){
			for( j=1;j<=C;j++){
				scanf("%1ld",&Grid[i][j] );
			}
		}
		long Ans = max( FindODD(),FindEVEN());
		if( Ans ) printf("Case #%ld: %ld\n",++k,Ans);
		else printf("Case #%ld: IMPOSSIBLE\n",++k );
		
	}

	return 0;
}

