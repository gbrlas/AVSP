#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// Problem-B

using namespace std;

void trier(int r[1000], int indice[1000], int N)
{
	int i, j, c;
	for(i = 1; i < N; i++)
	{
		j = i;
		while(j > 0 && r[j-1] < r[j])
		{
			c = r[j];
			r[j] = r[j-1];
			r[j-1] = c;
			c = indice[j];
			indice[j] = indice[j-1];
			indice[j-1] = c;
			j--;
		}
	}
}

void trier2(int x[1000], int y[1000], int indice[1000], int N)
{
	int i, j, c;
	for(i = 1; i < N; i++)
	{
		j = i;
		while(j > 0 && indice[j-1] > indice[j])
		{
			c = x[j];
			x[j] = x[j-1];
			x[j-1] = c;
			c = y[j];
			y[j] = y[j-1];
			y[j-1] = c;
			c = indice[j];
			indice[j] = indice[j-1];
			indice[j-1] = c;
			j--;
		}
	}
}

int main()
{
	int T, i, j, test, N, W, L, r[1000], indice[1000], x[1000], y[1000], limite[1000], dep;
	int xposs, ymin, erreur = 1, changement, c;
	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		scanf("%d %d %d\n", &N, &W, &L);
		changement = 0;
		if(W < L)
		{
			c = W;
			W = L;
			L = c;
			changement = 1;
		}
		erreur = 1;
		for(i = 0; i < N; i++)
		{
			scanf("%d", &r[i]);
			indice[i] = i;
		}
		trier(r, indice, N);
		
		x[0] = 0;
		y[0] = 0;
		dep = 0; // 0 pour dire qu'on va à droite, 1 à gauche
		for(i = 1; i < N && erreur; i++)
		{
			// On va placer le suivant à un endroit possible
			if(dep == 0)
			{
				xposs = x[i-1]+r[i-1]+r[i];
				if(xposs > W)
				{
					xposs = W;
					dep = 1;
					// On repartira dans l'autre sens
				}
				// On cherche le yminimum
				x[i] = xposs;
				ymin = 0;
				for(j = 0; j < i; j++)
				{
					if(x[j]+r[j] <= x[i]-r[i] || x[j]-r[j] >= x[i]+r[i])
					{
					}
					else
					{
						// Il va t'ennuyer et t'impose un y minimum de y[j]+r[j]+r[i];
						if(ymin < y[j]+r[j]+r[i]) ymin = y[j]+r[j]+r[i];
					}
				}
				y[i] = ymin;
				if(y[i] > L)
				{
					printf("Error ");
					erreur = 0;
				}
			}
			else
			{
				xposs = x[i-1]-r[i-1]-r[i];
				if(xposs > W)
				{
					xposs = 0;
					dep = 0;
					// On repartira dans l'autre sens
				}
				// On cherche le yminimum
				x[i] = xposs;
				ymin = 0;
				for(j = 0; j < i; j++)
				{
					if(x[j]+r[j] <= x[i]-r[i] || x[j]-r[j] >= x[i]+r[i])
					{
					}
					else
					{
						// Il va t'ennuyer et t'impose un y minimum de y[j]+r[j]+r[i];
						if(ymin < y[j]+r[j]+r[i]) ymin = y[j]+r[j]+r[i];
					}
				}
				y[i] = ymin;
				if(y[i] > L)
				{
					printf("Error ");
					erreur = 0;
				}
			}
		}
		
		if(erreur)
		{
			if(changement)
			{
				trier2(x, y, indice, N);
				printf("Case #%d: ", test);
				for(i = 0; i < N; i++)
				{
					printf("%d %d ", y[i], x[i]);
				}
				printf("\n");
			}
			else
			{
				trier2(x, y, indice, N);
				printf("Case #%d: ", test);
				for(i = 0; i < N; i++)
				{
					printf("%d %d ", x[i], y[i]);
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}
