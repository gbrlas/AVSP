#include<stdio.h>
#include<math.h>
int main()
{
	int re,n,i;
	char r[101];
	int p[101];
	int k;
	int b,o;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&re);
	k=1;
	while(re--)
	{
		int time=0,tb=0,to=0;	
		scanf("%d",&n);
		getchar();
		b=o=1;
		for(i=0;i<n;i++)
		{
			scanf("%c",&r[i]);
			getchar();
			scanf("%d",&p[i]);
			getchar();
		}
		if(r[0]=='B')
		{
			tb=p[0];
			b=p[0];
		}
		else
		{
			to=p[0];
			o=p[0];
		}
		time+=p[0];
		for(i=1;i<n;i++)
		{
			if(r[i]=='B')
			{
				if(tb>=to)
				{
					time+=fabs(p[i]-b)+1;
					tb+=fabs(p[i]-b)+1;					
				}
				else
				{
					if(tb+fabs(p[i]-b)>to)
					{
						time+=tb+fabs(p[i]-b)+1-to;
						tb+=fabs(p[i]-b)+1;
					}
					else
					{
						time+=1;
						tb=to+1;
					}
		
				}
				b=p[i];
			}
			if(r[i]=='O')
			{
				if(to>=tb)
				{
					time+=fabs(p[i]-o)+1;
					to+=fabs(p[i]-o)+1;					
				}
				else
				{
					if(to+fabs(p[i]-o)>tb)
					{
						time+=to+fabs(p[i]-o)+1-tb;
						to+=fabs(p[i]-o)+1;
					}
					else
					{
						time+=1;
						to=tb+1;
					}
				}
				o=p[i];
			}
		}
		printf("Case #%d: ",k++);
		printf("%d\n",time);
	}
	return 0;
}