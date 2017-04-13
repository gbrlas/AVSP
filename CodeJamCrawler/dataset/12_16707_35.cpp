#include<stdio.h>

int main()
{
	int t,n,s,p,i,cnt=1,max =0,surprise=0,num;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&s,&p);

			for(i =0;i<n;i++)
			{
				scanf("%d",&num);

				switch(num%3)
				{
					case 0 : 
						if(num/3 >= p)
							max++;
						else
							if(num > 0 && ((num/3) +1) >= p)
								surprise++;

						break;

					case 1:
						if((num/3) + 1>= p)
							max++;
						
						break;
					
					case 2:
						if((num/3) +1 >= p)
							max++;
						else
							if(num > 1 && ((num/3) + 2) >= p)
								surprise++;
						break;
					}
			}
	
	if(surprise > s)
		printf("Case #%d: %d\n",cnt,max + s);
	else
		printf("Case #%d: %d\n",cnt,max+surprise);

		cnt++; 
		max = 0; surprise = 0;
	
	}	
		
		return 0;
}