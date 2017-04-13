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
#include <gmpxx.h>

using namespace std;

vector<pair<pair<int, int>, pair<int,int> > > voisins[21];

int saroute[20];
bool visited[21];
bool quelle[20];
vector<pair<int, int> > pred[21];
int dist[21];

int main()
{
	int i, j, k, T, t;
	
	int N, M, P;
	scanf("%d\n", &T);

	int u, v, a, b;
	
	int bestbon = -1;
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		fprintf(stderr, "Cas %d\n", t);
		bestbon = -1;
		scanf("%d %d %d", &N, &M, &P);
		
		for(i = 1; i <= N; i++) voisins[i].clear();
		
		for(i = 0; i < M; i++)
		{
			scanf("%d %d %d %d", &u, &v, &a, &b);
			
			voisins[v].push_back(make_pair(make_pair(i+1, u), make_pair(a, b)));
		}
		
		for(i = 0; i < P; i++)
		{
			scanf("%d", &saroute[i]);
		}
		
		for(i = 0; i < (1 << M); i++)
		{
			// combinaison i.
			// On part en 2, on doit arriver en 1, et on doit si possible emprunter la route indiquée par saroute
			
			//fprintf(stderr, "Test %d\n", i);
			
			for(j = 1; j <= M; j++)
			{
				quelle[j] = i & (1 << (j-1));
				//fprintf(stderr, "%d", quelle[j]);
			}
			//fprintf(stderr, "\n");
			for(j = 1; j <= N; j++)
			{
				visited[j] = false;
				pred[j].clear();
				dist[j] = 1000000000;
			}
			dist[2] = 0;
			
			int encours;
			int fini = false;
			while(!fini)
			{
				int distmin = 1000000000;
				int quimin = -1;
				for(j = 1; j <= N; j++)
				{
					if(dist[j] < distmin && !visited[j])
					{
						distmin = dist[j];
						quimin = j;
					}
				}
				encours = quimin;
				if(quimin == -1) fini = true;
				else
				{
					visited[encours] = true;
					//fprintf(stderr, "Le meilleur est %d avec %d\n", encours, distmin);
					for(j = 0; j < voisins[encours].size(); j++)
					{
						int route = voisins[encours][j].first.first;
						int suivant = voisins[encours][j].first.second;
						int longueur;
						if(quelle[route]) longueur = voisins[encours][j].second.first;
						else longueur = voisins[encours][j].second.second;
					
						if(dist[suivant] >= dist[encours] + longueur)
						{
							if(dist[suivant] > dist[encours] + longueur) pred[suivant].clear();
							pred[suivant].push_back(make_pair(route, encours));
							dist[suivant] = dist[encours] + longueur;
						}
					}
				}
			}
			
			encours = 1;
			
			for(j = 0; j < P; j++)
			{
				bool rate = true;
				for(k = 0; k < pred[encours].size() && rate; k++)
				{
					//fprintf(stderr, "%d %d\n", pred[encours][k].first, pred[encours][k].second);
					if(pred[encours][k].first == saroute[j])
					{
						rate = false;
						encours = pred[encours][k].second;
					}
				}
				
				if(rate) j = P;
				else
				{
					bestbon = max(bestbon, j);
				}
			}
			
		}
		
		
		if(bestbon == P-1)
		{
			printf("Looks Good To Me\n");
		}
		else
		{
			printf("%d\n", saroute[bestbon+1]);
		}
		
	}

	return 0;
}
