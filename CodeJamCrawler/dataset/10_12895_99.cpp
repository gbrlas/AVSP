#include <stdio.h>
#include <string.h>



int n;
int secs[1010];
int sub_secs[1010];
int mint,gint;




void find_gcd(int m)
{
	int a,b,c;

	
	gint=sub_secs[0];
	
	for(int i=1;i<m;i++)
	{
		if(gint>sub_secs[i])
		{
			a=gint;
			b=sub_secs[i];
		}
		else
		{
			a=sub_secs[i];
			b=gint;
		}
		while(b!=0)
		{
			c=a%b;
			a=b;
			b=c;
		}
		gint=a;
	}
}


int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.out","w",stdout);

	int cases,icases;
	int i,k;


	scanf("%d",&cases);
	icases=1;


	while(icases<=cases)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&secs[i]);

		k=0;
		for(i=1;i<n;i++)
		{
			if(secs[k]>secs[i])
				k=i;
		}
		mint=secs[k];
		secs[k]=secs[0];
		secs[0]=mint;

		for(i=1;i<n;i++)
			sub_secs[i-1]=secs[i]-secs[0];

		find_gcd(n-1);

		k=secs[0]%gint;
		if(k!=0)
			k=gint-k;
		printf("Case #%d: %d\n",icases,k);
		icases++;
		

	}
	return 0;
}
