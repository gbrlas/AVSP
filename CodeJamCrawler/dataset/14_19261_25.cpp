#include<stdio.h>
int main()
{
	freopen("C:\\Users\\jehovah\\Downloads\\test.in","r",stdin);
	freopen("C:\\Users\\jehovah\\Downloads\\output.txt","w",stdout);
	int i,j,m,n,o,c,l=0,p,g;
	int a[100][100];
	int b[100][100];
	scanf("%d",&c);
	p=c;
	while(c!=0)
	{
		scanf("%d",&m);
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d",&n);
		for(i=1;i<=4;i++)
		{
			
			
			for(j=1;j<=4;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(i=1;i<=4;i++)
	//	g=a[m][i];
		{
			for(j=1;j<=4;j++)
			{
				//printf("%d",a[m][i]);
				if(a[m][i]-b[n][j]==0)
				{
					l++;
					o=b[n][j];
					//printf("\n%d",l);					
				}
			}
		}
		if(l==1)
		printf("Case #%d: %d\n",p-c+1,o);
		else if (l>1)
		printf("Case #%d: Bad magician!\n",p-c+1);
		else
		printf("Case #%d: Volunteer cheated!\n",p-c+1);
		o=0;l=0;
		c--;
		
	}
	
}
