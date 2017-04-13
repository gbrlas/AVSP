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

int N;
int C[80];
vector<int> voisins[80];
bool visited[80];
vector<pair<int, int> > fils[80];
pair<int, int> parent[80];
int compteur;
bool Abloque, Bbloque;

bool vis[80];

int minimise(int a, int b);

void construire(int x)
{
	visited[x] = true;
	for(int i = 0; i < voisins[x].size(); i++)
	{
		//printf("%d et %d voisins\n", x, voisins[x][i]);
		if(!visited[voisins[x][i]])
		{
			fils[x].push_back(make_pair(voisins[x][i], compteur));
			//printf("Fils de %d : %d\n", x, voisins[x][i]);
			parent[voisins[x][i]] = make_pair(x, compteur);
			compteur++;
			construire(voisins[x][i]);
		}
	}
}

int maximise(int a, int b)
{
	// C'est à a de jouer pour maximiser sa cote
	// printf("On est en (%d %d) et A joue\n", a, b);
	
	if(Abloque)
	{
		if(Bbloque) return 0;
		else return minimise(a, b);
	}
	
	int best = -1000000000;
	int poss;
	bool peutbouger = false;
	for(int i = 0; i < fils[a].size(); i++)
	{
		int j = fils[a][i].first;
		int e = fils[a][i].second;
		if(!vis[e])
		{
			peutbouger = true;
			vis[e] = true;
			if(visited[a])
			{
				poss = minimise(j, b);
			}
			else
			{
				visited[a] = true;
				poss = C[a] + minimise(j, b);
				visited[a] = false;
			}
			best = max(best, poss);
			vis[e] = false;
		}
	}
	if(!peutbouger)
	{
		Abloque = true;
		if(visited[a])
		{
			best = minimise(a, b);
		}
		else
		{
			visited[a] = true;
			best = C[a] + minimise(a, b);
			visited[a] = false;
		}
		Abloque = false;
	}
	return best;
}

int minimise(int a, int b)
{
	// C'est à b de jouer pour maximiser sa cote
	// printf("On est en (%d %d) et B joue\n", a, b);
	
	if(Bbloque)
	{
		if(Abloque) return 0;
		else return maximise(a, b);
	}
	
	int best = 1000000000;
	int poss;
	bool peutbouger = false;
	for(int i = 0; i < fils[b].size(); i++)
	{
		int j = fils[b][i].first;
		int e = fils[b][i].second;
		if(!vis[e])
		{
			peutbouger = true;
			vis[e] = true;
			if(visited[b])
			{
				poss = maximise(a, j);
			}
			else
			{
				visited[b] = true;
				poss = -C[b] + maximise(a, j);
				visited[b] = false;
			}
			best = min(best, poss);
			vis[e] = false;
		}
	}
	
	int j = parent[b].first;
	int e = parent[b].second;
	
	if(j >= 0 && !vis[e])
	{
		peutbouger = true;
		vis[e] = true;
		if(visited[b])
		{
			poss = maximise(a, j);
		}
		else
		{
			visited[b] = true;
			poss = -C[b] + maximise(a, j);
			visited[b] = false;
		}
		best = min(best, poss);
		vis[e] = false;
	}
	
	if(!peutbouger)
	{
		Bbloque = true;
		if(visited[b])
		{
			best = maximise(a, b);
		}
		else
		{
			visited[b] = true;
			best = -C[b] + maximise(a, b);
			visited[b] = false;
		}
		Bbloque = false;
	}
	return best;
}

int main()
{
	int T;
	int a, b;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "--- Case #%d ---\n", t);
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		
		for(int i = 0; i < N; i++) voisins[i].clear();
		
		for(int i = 0; i < N; i++) scanf("%d", &C[i]);
		
		for(int i = 0; i < N-1; i++)
		{
			scanf("%d", &a);
			a--;
			//printf("[%d et %d]\n", i, a);
			voisins[i].push_back(a);
			voisins[a].push_back(i);
		}
		
		int best = -1000000000;
		
		for(int depart = 0; depart < N; depart++)
		{
			for(int i = 0; i < N; i++)
			{
				visited[i] = false;
				fils[i].clear();
			}
			compteur = 0;
			construire(depart);
			parent[depart] = make_pair(-1, -1);
			
			int best1 = 1000000000;
			for(int depart2 = 0; depart2 < N; depart2++)
			{
				for(int i = 0; i < N-1; i++) vis[i] = false;
				for(int i = 0; i < N; i++) visited[i] = false;
				Abloque = false;
				Bbloque = false;
				int resultat = maximise(depart, depart2);
				
				//printf("En choisissant %d et %d : %d\n", depart, depart2, resultat);
				
				best1 = min(best1, resultat);
			}
			best = max(best, best1);
		}
		
		printf("%d\n", best);
	}

	return 0;
}
