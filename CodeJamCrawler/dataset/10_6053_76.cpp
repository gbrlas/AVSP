#include <iostream>
using namespace std;
long long int gcd(long long int x,long long int y)
{
	while( (x%=y) && (y%=x) );
	return x+y;
}
int main()
{
	freopen( "B-small-attempt1.in", "r", stdin );
	freopen( "Bout.txt", "w", stdout );

	int ca,cs=1;
	scanf("%d",&ca);
	long long int se[2000];
	while(ca--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&se[i]);
		
		long long int MOD = 0;
		
		
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(MOD == 0 )
					MOD = abs(se[j]-se[i]);
				else if( se[j]!=se[i])	
					MOD = gcd(MOD , abs(se[j]-se[i]) );
			}
		printf("Case #%d: ",cs++);
		if(se[0]%MOD !=0)
			printf("%lld\n",MOD - se[1]%MOD );
		else
			printf("0\n");	
	}
	return 0;
}
