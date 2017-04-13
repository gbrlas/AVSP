#include <cstdio>

int main()
{
	int tests;
	scanf("%d", &tests);
	
	for (int i = 0; i < tests; ++i)
	{
		int teams;
		scanf("%d", &teams);
		
		char table[101][101];
		double rpi[101][4];
		
		for (int j = 0; j < teams; ++j)
		{
			int wp = 0;
			int total = 0;
			
			for (int k = 0; k < teams; ++k)
			{
				char c;
				scanf(" %c ", &c);
				
				table[j][k] = c;
				
				if (c == '1')
					wp++;
				if (c != '.')
					total++;
			}
			
			rpi[j][0] = wp;
			rpi[j][3] = total;
		}
		
		for (int j = 0; j < teams; ++j)
		{
			double owp = 0;
			int teamsOut = 0;
			
			for (int k = 0; k < teams; ++k)
			{
				if (table[k][j] == '.')
				{
					teamsOut++;
					continue;
				}
					
				int upper = rpi[k][0];
				int lower = rpi[k][3] - 1;
				
				if (table[k][j] == '1')
					upper--;
					
				owp += upper / (double) lower;
			}
			
			rpi[j][1] = owp / (double) (teams - teamsOut);
		}
		
		for (int j = 0; j < teams; ++j)
		{
			double oowp = 0;
			int teamsOut = 0;
			
			for (int k = 0; k < teams; ++k)
			{
				if (table[k][j] == '.')
				{
					teamsOut++;
					continue;
				}
					
				oowp += rpi[k][1];
			}
			
			rpi[j][2] = oowp / (double) (teams - teamsOut);
		}
		
		printf("Case #%d:\n", i + 1);
		
		for (int k = 0; k < teams; ++k)
		{
			printf("%lf\n", 0.25 * rpi[k][0] / rpi[k][3] + 0.50 * rpi[k][1] + 0.25 * rpi[k][2]);
		}
	}
	
	return 0;
}
