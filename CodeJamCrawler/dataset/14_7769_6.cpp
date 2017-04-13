#include<stdio.h>
int main()
{
	int a[4][4],b[4][4],c[4],d[4],i,j,n,x,y,flag=0,no,nn;
	scanf("%d",&n);
	nn=n;
	for(nn=1;nn<=n;nn++)
	{
		scanf("%d",&x);
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
		scanf("%d",&y);
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		scanf("%d",&b[i][j]);
		for(i=0;i<4;i++)
		c[i]=a[x-1][i];
		for(i=0;i<4;i++)
		d[i]=b[y-1][i];
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(c[i]==d[j])
			{
				flag++;
				no=i;
			}
		}
		if(flag==0)
		printf("Case #%d: Volunteer cheated!\n",nn);
		else if(flag==1)
		printf("Case #%d: %d\n",nn,c[no]);
		else
		printf("Case #%d: Bad magician!\n",nn);


		flag=0;
	}
	return 0;

}