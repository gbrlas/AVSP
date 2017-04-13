#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Problem-A

using namespace std;

int d[10001], l[10001], N, D, cordeactuelle, endroitactuel, plusdelan[100001];

int main()
{
	int T, i, j, k, test, elan;
	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &d[i], &l[i]);
			plusdelan[i] = -1;
		}
		scanf("%d", &D);
		d[N] = D;
		l[N] = 0;
		plusdelan[N] = -1;
		plusdelan[0] = d[0];
		for(i = 0; i < 150 && plusdelan[N] == -1; i++)
		{
			for(j = 0; j <= N; j++)
			{
				// La corde j peut nous amener où?
				if(plusdelan[j] > 0)
				{
					for(k = j+1; k <= N && d[k] <= d[j]+plusdelan[j]; k++)
					{
						// Nouvel elan possible
						elan = d[k]-d[j];
						if(elan > l[k]) elan = l[k];
						if(elan > plusdelan[k]) plusdelan[k] = elan;
					}
				}
			}
		}
		if(plusdelan[N] == -1) printf("Case #%d: NO\n", test);
		else printf("Case #%d: YES\n", test);
		
		
		
		
	}
	return 0;
}
