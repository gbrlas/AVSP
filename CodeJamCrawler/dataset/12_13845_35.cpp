#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int bil[105];
int sel(int a,int b)
{
	if(a<b)return (b-a);
	else return (a-b);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int n,s,p;
		scanf("%d %d %d",&n,&s,&p);
		for(int i=0;i<n;i++)scanf("%d",&bil[i]);
		int jum = 0;
		int maks;
		for(int i=0;i<n;i++)
		{
			
			if(bil[i]%3==0)
			{
				if((bil[i]/3)>=p)jum++;
				else if(s>0 &&bil[i]!=0)
				{
					maks = (bil[i]/3) + 1;
					if(maks>=p)
					{
						jum++;
						s--;
					
					}
				}
			}
			else if(bil[i]%3==1) 
			{
				
				maks = (bil[i]-1)/3+1;
				if(maks>=p) jum++;
				
			}
			else 
			{
				
				maks = (bil[i]+1)/3;
				if(maks>=p)jum++;
				else if(s>0&&maks+1>=p)
				{
					jum++;
					s--;
				
				}
			}
		}
		printf("Case #%d: %d\n",it+1,jum);
	}
	return 0;
}
