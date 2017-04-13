#include<stdio.h>
int main()
{
	int a,b,n,m,t,temp,count=0,mod,loopcount=1,div,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		count=0;
		if(b>11)
		{
			for(n=a;n<=b;n++)
			{
				
				for(m=n+1;m<=b;m++)
				{
					temp=0;mod=10;
					if(b>=10 && b<=100)  
						{loopcount=1;}
					else 
						loopcount=2;
					while(loopcount--)
					{
					div=n/mod;
					if(mod==10 && b>=100)
						temp=(n%mod)*100+div;
					else
						temp=(n%mod)*10+div;
					if(temp==m)
					{
						count++;
						//printf("%d ",temp);
						break;
					}
					else
						mod*=10;
					}
				}
			
			}
		}
		printf("Case #%d: %d\n",50-t,count);
	}
}
