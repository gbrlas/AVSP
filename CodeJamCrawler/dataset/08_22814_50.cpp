#include <stdio.h>
#include <string.h>

void main()
{
	int nocases;
	int noengines;
	int noqueries;

	char engines[100][100];

	int queryfound[100];

	char query[100];

	int count = 0;



	scanf("%d",&nocases);
	while(count < nocases)
	{
		++count;

		int noswitches = 0;
		int countfound = 0;

		int i=0;
		scanf("%d",&noengines);
		getchar();
		while(i<noengines)
		{
			int j=0;
			char c = getchar();
			while(!(c =='\n' || c==EOF))
			{
				engines[i][j] = c;
				c = getchar();
				++j;
			}
			engines[i][j] ='\0';
			queryfound[i] = 0;
			++i;
		}
;
		i=0;
		scanf("%d",&noqueries);
		getchar();
		while(i<noqueries)
		{
			int k=0;
			char c = getchar();
			while(!(c =='\n' || c==EOF))
			{
				query[k] = c;
				c = getchar();
				++k;
			}
			query[k] ='\0';

			int j=0;
			for(;j<noengines;++j)
			{
				if(strcmp(query,engines[j])==0)
				{
					if(queryfound[j]==0)
					{
						queryfound[j] = 1;
						++countfound;
					}
					break;
				}
			}
			if(countfound == noengines)
			{
				++noswitches;
				k=0;
				for(;k<noengines;++k)
				{
					queryfound[k] =0;
				}
				queryfound[j] = 1;
				countfound = 1;
			}
			++i;
		}

		printf("Case #%d: %d\n",count,noswitches);
	}

}
