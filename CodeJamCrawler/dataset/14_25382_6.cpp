#include <cstdio>

int main()
{
	int row,i,j,t,count,n=0,num;
	int mat[4][4],arr[4];
	scanf("%d",&t);
	while(t--)
	{
		n++;
		count=0;
		scanf("%d",&row);
		for(i=0; i<4; i++)
			for(j=0;j<4;j++)
				scanf("%d",&mat[i][j]);
		for(i=0;i<4;i++)
			arr[i]=mat[row-1][i];
		scanf("%d",&row);
		for(i=0; i<4; i++)
			for(j=0;j<4;j++)
				scanf("%d",&mat[i][j]);
		for(i=0;i<4 && count<2;i++)
			for(j=0;j<4;j++)
				if(arr[j] == mat[row-1][i])
				{
					count++;
					num = arr[j];
					break;
				}
		if(count==0)
			printf("Case #%d: Volunteer cheated!\n",n);
		else if(count ==1 )
			printf("Case #%d: %d\n",n,num);
		else 
			printf("Case #%d: Bad magician!\n",n);
	}
	return 0;
}
