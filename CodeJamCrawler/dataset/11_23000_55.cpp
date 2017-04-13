#include <stdio.h>
#include <algorithm>
using namespace std;
#define Max(a,b)(((a)>(b))?(a):(b))

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		int ot,bt;
		int op,bp;
		ot=bt=0;
		op=bp=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char a;
			int b;
			scanf(" %c %d",&a,&b);
			if( a == 'O' )
			{
				ot = ot+abs(op-b)+1;
				if ( bt >= ot ) ot = bt+1;
				op = b;
			}
			if( a == 'B' )
			{
				bt = bt+abs(bp-b)+1;
				if ( ot >= bt ) bt = ot+1;
				bp = b;
			}
		}
		printf("Case #%d: %d\n",t,Max(ot,bt));
	}
	return 0;
}
