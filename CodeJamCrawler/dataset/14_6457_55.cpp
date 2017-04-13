#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int i,t,j,a,n=1;
	int x[5][5];
	scanf("%d",&t);
	while(t--)
	{
		int m[18]={0};
		int count=0,ans;
		scanf("%d",&a);
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&x[i][j]);
		for(j=0;j<4;j++)
			m[x[a-1][j]]++;
		scanf("%d",&a);
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&x[i][j]);
		for(j=0;j<4;j++)
		{
			m[x[a-1][j]]++;
			if(m[x[a-1][j]]==2)
				count++,ans=x[a-1][j];
		}
		printf("Case #%d: ",n++);
		if(count==1)
		printf("%d\n",ans);
		else if(count==0)
		printf("Volunteer cheated!\n");
		else
		printf("Bad magician!\n");
	}
	return 0;
}
