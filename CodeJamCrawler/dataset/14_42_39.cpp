#include<stdio.h>
 
int main()
{
	float naomi1[1000],naomi[1000],ken[1000];
	float temp;
	int t,i,j,count=0,m=0,n;
	int a[100];
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%f",&naomi[i]);
		if(n>1)
			for(i=1;i<n;i++)
				for(j=0;j<(n-i);j++)
				{
					if(naomi[j]>naomi[j+1])
					{
						temp=naomi[j];
						naomi[j]=naomi[j+1];
						naomi[j+1]=temp;
					}
				}
		for(i=0;i<n;i++)
			naomi1[i]=naomi[i];
		for(i=0;i<n;i++)
			scanf("%f",&ken[i]);
		if(n>1)
			for(i=1;i<n;i++)
				for(j=0;j<(n-i);j++)
				{
					if(ken[j]>ken[j+1])
					{
						temp=ken[j];
						ken[j]=ken[j+1];
						ken[j+1]=temp;
					}
				}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(ken[i]<naomi[j])
				{
					count++;
					naomi[j]=0;
					break;
				}
		a[m]=count;
		m++;
		count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(naomi1[i]<ken[j])
				{
					count++;
					ken[j]=0;
					break;
				}
		a[m]=n-count;
		m++;
		count=0;
		t--;
	}
	j=1;
	for(i=0;i<m;i=i+2)
	{
		printf("Case #%d: ",j);
		printf("%d %d\n",a[i],a[i+1]);
		j++;
	}
}
