#include<stdio.h>
#include<math.h>
__int64 a[1000];
void main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("OUTPUT.out", "w", stdout);
	int cas;
	scanf("%d",&cas);
	int cass=1;
	while(cas--)
	{
		int r,n,k;
		__int64 max=0;
		scanf("%d%d%d",&r,&k,&n);//r´În×é
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			max+=a[i];
		}
		int j=0;
		__int64 mm=0,result=0;
		for(int i = 0 ;i < r; i++)
		{
			while(mm+a[j]<=k&&mm+a[j]<=max)
			{
				mm+=a[j];
				result+=a[j];
				j++;
				j%=n;
			}
			mm=0;
		}
		printf("Case #%d: %d\n",cass++,result);

	}
}