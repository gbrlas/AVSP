#include <stdio.h>

int main()
{
	int cases;
	int first, second;
	int card1[4][4];
	int card2[4][4];

	int i, j, k;

	scanf("%d", &cases);

	for(i=1; i<=cases; i++)
	{
		scanf("%d", &first);

		for(j=0; j<4; j++)
		{
			for(k=0; k<4; k++)
				scanf("%d", &card1[j][k]);
		}

		scanf("%d", &second);
		
		for(j=0; j<4; j++)
		{
			for(k=0; k<4; k++)
				scanf("%d", &card2[j][k]);
		}

		int MATCH=0;
		int ele;
		for(j=0; j<4; j++)
		{
			for(k=0; k<4; k++)
			{
				if ( card1[first-1][j] == card2[second-1][k] )
				{
					MATCH++;
					ele = card1[first-1][j];
				}
			}
		}

		printf("Case #%d: ",i); 
		if ( MATCH == 0 )
			printf("Volunteer cheated!\n");
		else if ( MATCH == 1 )
			printf("%d\n", ele);
		else
			printf("Bad magician!\n");
	}

	return 0;
}
