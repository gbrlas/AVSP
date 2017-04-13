#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000007

struct DATA{
	long Ind;
	double Prof;
	DATA( long i,double j )
	{
		Ind = i;
		Prof = j;
	}
};

bool operator<( const DATA &a,const DATA &b )
{
	return a.Prof > b.Prof;
}

long X,S,R,t,N;
long Spd[MAX+7];
vector<DATA> Vect;


int main( void )
{
	long i,j,u,v,w,Icase,k = 0;

	freopen("A.in","r",stdin );
	freopen("A.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld%ld%ld%ld%ld",&X,&S,&R,&t,&N );
		for( i=1;i<=X;i++){
			Spd[i] = 0;
		}
		for( i=1;i<=N;i++){
			scanf("%ld%ld%ld",&u,&v,&w );
			for( j=u+1;j<=v;j++){
				Spd[j] = w;
			}
		}

		for( i=1;i<=X;i++){
			Vect.push_back( DATA( i,(1.0/(Spd[i]+S))-(1.0/(Spd[i]+R)) ));
		}
		sort( Vect.begin(),Vect.end());

		double Ans = 0,C = t;
		for( i=0;i<Vect.size();i++){
			j = Vect[i].Ind;
			C -= 1.0/(Spd[j]+R);
			if( C<0){
				C += 1.0/(Spd[j]+R);		
				Ans += C;
				double D = 1 - C*(Spd[j]+R);
				Ans += D*(1.0/(Spd[j]+S));
				i++;
				break;
			}
			Ans += 1.0/(Spd[j]+R);
			//printf("%lf\n",Ans );
		}
		for( ;i<Vect.size();i++){
			j = Vect[i].Ind;
			Ans += 1.0/(Spd[j]+S);
		}
		printf("Case #%ld: %.9lf\n",++k,Ans );
		Vect.clear();
	
	}

	return 0;
}

