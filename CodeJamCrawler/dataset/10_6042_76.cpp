#include <iostream>
using namespace std;

int main()
{
	freopen( "A-small-attempt1.in", "r", stdin );
	freopen( "Aout.txt", "w", stdout );

	int n,k,ca,cs=1;
	scanf("%d",&ca);
	while(ca--)
	{
		
		scanf("%d%d",&n,&k);
		int cnt = 1;
		bool T=true;
		for(int i=0;i<n;i++)
		{	
			if( (k/cnt)%2==0)
			{
				T=false;
				break;;
			}
			cnt*=2;
						
		}	
		printf("Case #%d: ",cs++);
		if( T )
			printf("ON\n");
		else
			printf("OFF\n");	
	}
	return 0;	
}
