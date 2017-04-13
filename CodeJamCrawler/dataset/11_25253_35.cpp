#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
using namespace std;

#define MAX 107

typedef __int64 Long;

vector<Long> Pos;
Long C,D;

bool IsPos( double d )
{
	vector<double> Tmp;
	Tmp.push_back( Pos[0]-d );
	double Last;
	Long i;
	for( i=1;i<Pos.size();i++){
		Last = Tmp[Tmp.size()-1];
		double t = Last + D;

		if( fabs( t-Pos[i]) <= d ){
			Tmp.push_back( t );
			continue;
		}
		else if( t > Pos[i] ) return false;
		else{
			Tmp.push_back( Pos[i]-d );
		}
	}
	return true;
}




int main( void )
{
	Long i,P,V,Icase,k=0;

	freopen("B.in","r",stdin );
	freopen("B.out","w",stdout );

	scanf("%I64d",&Icase );
	while( Icase--){
		scanf("%I64d%I64d",&C,&D );
		Pos.clear();
		for( i=1;i<=C;i++){
			scanf("%I64d%I64d",&P,&V );
			while( V-- ){
				Pos.push_back( P );
			}
		}

		double u = 1e14;
		double l = 0;
		while( u-l > 1e-7 ){//printf("%lf %lf\n",l,u );
			double m = (l+u)/2;
			if( IsPos( m )) u = m;
			else l = m;
		}
		printf("Case #%I64d: %.7lf\n",++k,(l+u)/2 );
		
	}

	return 0;
}



