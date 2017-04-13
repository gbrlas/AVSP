#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
char data[100][100];
char yes[10] = "YES";
char no[10] = "NO";


void main()
{
	freopen("C:\\Users\\Administrator\\Downloads\\B-large.in", "r", stdin);
	freopen("c:\\b_output_large.txt", "w", stdout);

	char result[100];
	int count = 0;

	scanf("%d", &count);

	for(int i = 0; i<count; i++)
	{
		// 입력
		scanf("%d%d",&n,&m);
		for(int j=0; j<n;j++)
		{
			for(int k =0; k<m ;k++)
				scanf("%d", &data[j][k]);
		}

		// 처리
		int isok = 1;
		for(int y =0; y<n; y++)
		{
			
			for(int x=0; x<m; x++)
			{
				for(int xx = 0; xx<m ; xx++)
				{
					if(data[y][x] < data[y][xx])
					{
						isok = 0;
						break;
					}

				}
				if(isok !=1)
				{
					isok = 1;
					for(int yy = 0; yy<n ; yy++)
					{
						if(data[y][x] < data[yy][x])
						{
							isok = 0 ;
							break;
						}
					}
				}
				if(isok == 0) break;
			}
			if(isok == 0) break;
		}

		if(isok == 0) strcpy(result, no);
		if(isok == 1) strcpy(result, yes);

		printf("Case #%d: %s\n", i+1, result);
	}
}