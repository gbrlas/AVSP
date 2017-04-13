#include<stdio.h>
double multiple(int );

double multiple(int j)
{	double a=1;
	for(int i=1;i<=j;i++)
		a= 10*a;
	return a;
}
	
int main(void)
{	int testcases, A, B;
	int temp, raise, rem, div, n, m, count ; 
	scanf("%d",&testcases);
	
	for(int i=1;i<=testcases;i++)
	{	scanf("%d",&A);
		scanf("%d",&B);
		raise=0; count=0;
		
		temp=A;
		while(temp!=0)
		{	temp=temp/10;
			raise++;
		}
		raise--;
		//printf("The value of raise is %d\n", raise);
		
		for(int j=A;j<=B;j++)
		{	n=j; m=n;
			//printf("n=j=%d\n", j);
			
						
			for(int k=1;k<=raise;k++)
			{	
				
				rem=m%10;
				//printf("rem= %d\n", rem);
				div=m/10;
				//printf("div = %d\n", div);
				m=(int)(multiple(raise)*rem + div);
				//printf("m = %d\n", m);
				
				if(m>n && m<=B)
				{	count++;
					//printf("Counted\n\n");
				}
				//printf("\n");
				
				
				
			}
		}
		printf("Case #%d: %d\n", i, count);
	}
	return 0;
}


