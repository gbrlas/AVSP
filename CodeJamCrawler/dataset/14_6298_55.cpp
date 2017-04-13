#include<cstdio>
int main()
{
	int t, a1[4][4], a2[4][4], count, i, j, r1, r2, T, ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&r1);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a1[i][j]);
		scanf("%d",&r2);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a2[i][j]);
		count=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(a1[r1-1][i]==a2[r2-1][j])
				{
					ans=a1[r1-1][i];
					count++;
				}
		printf("Case #%d: ",t);
		if(count==1)
			printf("%d\n",ans);
		else if(count==0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}
	return 0;
}

