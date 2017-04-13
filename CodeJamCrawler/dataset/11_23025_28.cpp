#include <stdio.h>
#include <memory.h>
#define MAX 51

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int n,m;
		int arr[MAX][MAX];
		int bc=0;
		memset(arr,0,sizeof(arr));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("\n");
			for(int j=0;j<m;j++)
			{
				char a;
				scanf("%c",&a);
				if( a == '.' ) arr[i][j] = 0;
				if( a == '#' ) arr[i][j] = 1,bc++;
			}
		}
		int rflag=0;
		int rc=0;
		if( bc%4 == 0 )
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if( arr[i][j] == 1 ) 
					{
						if( arr[i][j+1] == 1 && arr[i+1][j] == 1 && arr[i+1][j+1] == 1 )
						{
							arr[i][j] = 1; arr[i][j+1] = 2; arr[i+1][j] = 3; arr[i+1][j+1] = 4;
							rc+=4;
						}
						else
						{
							rflag=1;
							break;
						}
					}
				}
				if( rflag == 1 ) break;
			}
		}
		else
			rflag=1;
		if( rc != bc )
			rflag=1;

		printf("Case #%d:\n",t+1);
		if( rflag == 0 )
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if( arr[i][j] == 0 ) printf(".");
					if( arr[i][j] == 1 ) printf("/");
					if( arr[i][j] == 2 ) printf("\\");
					if( arr[i][j] == 3 ) printf("\\");
					if( arr[i][j] == 4 ) printf("/");
				}
				printf("\n");
			}
		}
		else
			printf("Impossible\n");
	}
	return 0;
}