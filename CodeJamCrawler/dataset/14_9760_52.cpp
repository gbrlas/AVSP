#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
	int T;
	int P, Q, N;
	int H[100], G[100];
	
	int best[101][2000]; // Avant d'envisager le numéro x, avec y coups d'avance
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "--- Case #%d ---\n", t);
		printf("Case #%d: ", t);
		
		scanf("%d %d %d", &P, &Q, &N);
		
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d", &H[i], &G[i]);
			H[i]--;
		}
		
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j < 2000; j++) best[i][j] = -1;
		}
		
		best[0][1] = 0; // Au début on a 1 coup d'avance comme on commence
		
		for(int i = 0; i < N; i++)
		{
			// On envisage le numéro i
			for(int j = 0; j < 2000; j++)
			{
				if(best[i][j] >= 0)
				{
					//printf("On peut envisager le %d-eme avec %d coups d'avance et %d en poche\n", i, j, best[i][j]);
					// On peut ou pas tuer le numéro i, et on possède j coups d'avance
					// Soit on le tue pas :
					int k = H[i]/Q + 1; // nombre de coups pour la tour pour tuer le i
					best[i+1][j+k] = max(best[i+1][j+k], best[i][j]);
					
					int test;
					int test2;
					int y;
					bool trouve = false;
					int vraix;
					int vraiy;
					
					for(int x = 0; x <= 10 && !trouve; x++)
					{
						// On tire x coups avant : 
						test = H[i] - x*P;
						test2 = test % Q;
						y = (test-test2)/Q; // Le robot va tirer y coups, et puis on fait le coup fatal
						if(test2 < P && x <= y-1+j)
						{
							trouve = true;
							vraix = x;
							vraiy = y;
						}
					}
					
					if(trouve)
					{
						best[i+1][j+vraiy-1-vraix] = max(best[i+1][j+vraiy-1-vraix], best[i][j] + G[i]);
					}
				}
			}
		}
		
		int bbest = 0;
		
		for(int i = 0; i < 2000; i++)
		{
			//if(best[N][i] >= 0) printf("On peut finir avec %d coups d'avance et %d en poche\n", i, best[N][i]);
			bbest = max(bbest, best[N][i]);
		}
		printf("%lld\n", bbest);
	}


	return 0;
}
