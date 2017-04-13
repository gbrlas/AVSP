#include<stdio.h>
#include<string.h>

int f[2000001];

int main()
{
	int t,p;
	int a,b;
	int i,j,k;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&a,&b);
		memset(f,0,sizeof(f));
		for (i=a;i<=b;i++)
		{
			k=1;
			while (k<=i) k=k*10;
			int mm=i;
			for (j=1;k>=1;j=j*10,k=k/10)
			{
				int rr=(i%j)*k+i/j;
				if (rr<=b&&rr>mm) mm=rr;
			}
			f[mm]++;
		}
		int res=0;
		for (i=a;i<=b;i++)
			res=res+f[i]*(f[i]-1)/2;
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}
