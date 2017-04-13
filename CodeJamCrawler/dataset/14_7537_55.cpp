#include<stdio.h>

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("outp.in","w",stdout);
	int t,num;
	scanf("%d",&t);
	num=t;
	while(t--)
	{
		
		int a,b,freq[16]={0},i,j,count1=0,count2=0;
		int mat1[4][4],mat2[4][4];
		scanf("%d",&a);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&mat1[i][j]);
				if(i==(a-1))
				{
					freq[mat1[i][j]-1]++;
				}
			}
		}
		
		scanf("%d",&b);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&mat2[i][j]);
				if(i==(b-1))
				{
					freq[mat2[i][j]-1]++;
				}
			}
		}
		
		for(i=0;i<16;i++)
		{
			if(freq[i]==1)
			{
				count1++;
			}
			if(freq[i]==2)
			{
				j=i+1;
				count2++;
			}
		}
		
		if(count2==1)
		{
			printf("Case #%d: %d\n",num-t,j);
		}
		else if(count2>1)
		{
			printf("Case #%d: Bad magician!\n",num-t);
		}
		else if(count2==0)
		{
			printf("Case #%d: Volunteer cheated!\n",num-t);
		}
	}
return 0;
}
