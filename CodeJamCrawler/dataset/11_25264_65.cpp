#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000007

typedef __int64 Long;

Long L,t,N,C;

Long Time[MAX+7];
Long Prof[MAX+7];

bool Cmp( Long a,Long b )
{
	return a>b;
}

int main( void )
{
	Long i,j,v,Icase,k=0;

	freopen("B.in","r",stdin );
	freopen("B.out","w",stdout );

	scanf("%I64d",&Icase );
	while( Icase--){
		scanf("%I64d%I64d%I64d%I64d",&L,&t,&N,&C );
		Long Ans = 0;
		for( i=0;i<C;i++){
			scanf("%I64d",&v );
			for( j=i;j<N;j+=C ){
				Time[j] = v*2;
				Ans += Time[j];
			}
		}

		Long Sum = 0,Pre = 0;
		for( i=0;i<N;i++){
			Sum += Time[i];
			if( Sum >t ){
				Long Ext = t-Pre;
				Prof[i] = Time[i] - (Ext+(Time[i]-Ext)/2);
				break;	
			}
			Prof[i] = 0;
			Pre = Sum;
		}
		

		for( i++;i<N;i++){
			Prof[i] = Time[i] - Time[i]/2;
		}

		sort( &Prof[0],&Prof[N],Cmp  );

		for( i=0;i<L;i++){
			Ans -= Prof[i];
		}

		printf("Case #%I64d: %I64d\n",++k,Ans );
		
	}

	return 0;
}

