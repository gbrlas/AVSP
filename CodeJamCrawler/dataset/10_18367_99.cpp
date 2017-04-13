#include<stdio.h>
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k%(1<<n) == ((1<<n)-1))printf("Case #%d: ON\n",tt);
		else printf("Case #%d: OFF\n",tt);
/*		bool onoff[11],out[11];
		onoff[0]=out[0]=true;
		for(int i = 1;i<=10;i++)onoff[i]=out[i]=false;
		while(k--)
		{
			for(int i=1;i<=n;i++)
			{
				onoff[i]=(out[i-1]^onoff[i]);
			}
			for(int i=1;i<=n;i++)
			{
				out[i]=(onoff[i]&out[i-1]);
			}
		}
		printf("Case #%d: %s\n",tt,(out[n]?"ON":"OFF"));*/
	}
}
