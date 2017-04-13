#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int flag=1;
		int kali=2;
		int i,j;
		int has;
		int temp;
		for(i=0;i<n;i++)
		{
			temp=k%kali;
			if(temp<(kali/2))has=0;
			else has=1;
		//	printf("%d ",has);
			kali*=2;
			if(has==0)
			{
				flag=0;
				break;
			}
		}
		printf("Case #%d: ",it+1);
		if(flag==0)printf("OFF\n");
		else printf("ON\n");
	}
	return 0;
}
