#include <iostream>
using namespace std;

int main()
{
	freopen( "A-large.in", "r", stdin );
	freopen( "Aout.txt", "w", stdout );

	long long int n,k,cs=1;
	int ca;
	scanf("%d",&ca);
	while(ca--)
	{
		
		scanf("%lld%lld",&n,&k);
		long long int cnt = 1;
		bool T=true;
		for(long long int i=0;i<n;i++)
		{	
			if( (k/cnt)%2==0)
			{
				T=false;
				break;;
			}
			cnt*=2;
						
		}	
		printf("Case #%lld: ",cs++);
		if( T )
			printf("ON\n");
		else
			printf("OFF\n");	
	}
	return 0;	
}
