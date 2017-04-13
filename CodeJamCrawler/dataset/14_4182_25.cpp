#include<stdio.h>
int main()
{
	int i,t,start,end,a,hash[16],d,c,p,n=1;
	scanf("%d",&t);
	while(n<=t)
	{
		c=0;
		for(i=0;i<=15;i++)
			hash[i]=0;
		scanf("%d",&a);
		start=4*(a-1)+1;
		end=start+4;
		for(i=1;i<=16;i++)
		{
			scanf("%d",&d);
			if(i>=start && i<end)
			{
				hash[d-1]++;
			}
		}
		scanf("%d",&a);
                start=4*(a-1)+1;
                end=start+4;
                for(i=1;i<=16;i++)
                {
                        scanf("%d",&d);
                        if(i>=start && i<end)
                        {
                                hash[d-1]++;
				if(hash[d-1]==2)
				{
					c++;
					p=d;
				}
                        }
                }
		if(c==0)
			printf("Case #%d: Volunteer cheated!\n",n);		
		else if(c==1)
			printf("Case #%d: %d\n",n,p);
		else
			printf("Case #%d: Bad magician!\n",n);
		n++;
	}
}

