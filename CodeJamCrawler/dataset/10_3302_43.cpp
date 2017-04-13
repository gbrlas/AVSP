#include<stdio.h>
#include<math.h>
void main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("OUTPUT.out", "w", stdout);
	int cas;
	scanf("%d",&cas);
	int cass=1;
	while(cas--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int temp=(int)pow(2.0,n);
		if(k>=temp-1&&(k-temp+1)%temp==0)
			printf("Case #%d: ON\n",cass++);
		else 
			printf("Case #%d: OFF\n",cass++);
	}
}