#include<stdio.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,s,p,sum,x,y,z,count=0;
		scanf("%d%d%d",&n,&s,&p);
		for(j=0;j<n;j++)
		{
			scanf("%d",&sum);
			int flag=0;
			for(x=0;x<=10;x++)
			{
				for(y=0;y<=10;y++)
				{
					for(z=0;z<=10;z++)
					{
						if((x+y+z)==sum && ( x>=p || y>=p || z>=p ) &&  abs(x-y)<3 && abs(y-z)<3 && abs(z-x)<3 && flag!=1)
						{
							if( abs(x-y)<2 && abs(y-z)<2 && abs(z-x)<2 )
							{
								count++;
								if(flag==2)
								{
									count--;
									s++;
								}
								flag=1;
							}
							else if (flag==0)
							{
								flag=2;
								count++;
								s--;
							}
						}
					}
				}
			}
		}
		if(s>0)
			s=0;
		printf("Case #%d: %d\n",i+1,count+s);
	}
	return 0;
}



