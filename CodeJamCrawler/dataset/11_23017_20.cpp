#include <stdio.h>
#include <memory.h>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int n;
		double arr[105][105];
		double result[105][3];
		memset(arr,0,sizeof(arr));
		memset(result,0,sizeof(result));
		scanf("%d",&n);
		printf("Case #%d:\n",t+1);
		for(int i=0;i<n;i++)
		{
			scanf("\n");
			for(int j=0;j<n;j++)
			{
				char c;
				scanf("%c",&c);
				if( c == '1' ) arr[i][j]=1;
				if( c == '0' ) arr[i][j]=0;
				if( c == '.' ) arr[i][j]=-1;
			}
		}
		double ta,tb,tc,td;

		//WP
		for(int i=0;i<n;i++)
		{
			ta = tb =0;
			for(int j=0;j<n;j++)
			{
				if( arr[i][j] != -1 ) tb++;
				if( arr[i][j] == 1 ) ta++;
			}
			if( tb != 0 )
				result[i][0] = (ta/tb);
		}

		for(int i=0;i<n;i++)
		{
			ta = tb = tc = td = 0;
			for(int j=0;j<n;j++)
			{
				if( arr[i][j] != -1 )
				{
					ta = tb = 0;
					tc++;
					for(int k=0;k<n;k++)
					{
						if( k == i ) continue;
						if( arr[j][k] != -1 ) tb++;
						if( arr[j][k] == 1 ) ta++;
					}
					if( tb != 0)
						td += ta/tb;
				}
			}
			if( tc != 0 )
				result[i][1] = td/tc;
		}

		for(int i=0;i<n;i++)
		{
			ta = tb = 0;
			for(int j=0;j<n;j++)
			{
				if( arr[i][j] != -1 ) 
				{
					tb++;
					ta += result[j][1];
				}
			}
			if( tb != 0 )
				result[i][2] = ta/tb;
			printf("%lf\n",0.25*result[i][0]+0.5*result[i][1]+0.25*result[i][2]);
		}
	}
	return 0;
}