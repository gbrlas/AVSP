#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,u=1;
	scanf("%d",&t);
	while(t>0)
	{
		int i,n,c,p,count=0,wc=0;
		scanf("%d %d %d",&n,&c,&p);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			
			int m = a[i]/3,diff;
			diff = a[i] - (m*3);
			//printf("%d\n",diff);
			if(a[i]==0 && p==0)
				count++;
			else if(a[i]!=0)
			{
				int b[3];
				b[0]=b[1]=b[2]=m;
				if(diff == 2)
				{
					b[0]+=1;
					if(b[0]>=p)
						count++;
					else{
						b[0]+=1;
						//printf("b = %d\n",b[0]);
						if(b[0]>=p && c>0 && b[0]<11)
						{
							wc++;
							
						}
					}
				}
				else if(diff == 1)
				{
					b[0]+=1;
					if(b[0]>=p)
						count++;	
				}
				else if(diff == 0)
				{
					if(b[0]>=p)
						count++;
					else
					{
						b[0]+=1;
						if(b[0]>=p && c>0 && b[0]<11)
						{
							wc++;
							
						}
					}
				}
			}
		}
		if(c < wc)
			wc = c;
		printf("Case #%d: %d\n",u++,count+wc);
		t--;
	}
	return 0;
}
