#include<stdio.h>
int main()
{
	int t,a[4][4],b[4][4],c,n1,n2,i,j,m=1,v,f,k;
	scanf("%d",&t);
	while(t--)
{
    	c=0;
		scanf("%d",&n1);
		n1--;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d",&n2);
		n2--;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
			 scanf("%d",&b[i][j]);
			}
		}
		for(f=0;f<4;f++)
		{
		
		  for(k=0;k<4;k++)
		  {
			if(a[n1][f]==b[n2][k])
			  {
			  c++;
			  v=a[n1][f];
		     }
		}
	}
		printf("Case #");
		printf("%d",m);
		if(c==0)
		printf(": Volunteer cheated!\n");
        else
		{
		if(c==1)
        {
        printf(": ");
		printf("%d\n",v);
	    }
		else
		printf(": Bad magician!\n");
	    } 
		m++;
	}
}
