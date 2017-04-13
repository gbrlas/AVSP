#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// Problem-B

using namespace std;

struct coord
{
	int x;
	int y;
};


int S, M, mo;
coord moves[6];

bool tableau[100][100];
bool deja_ami[100][100];
bool valeur[100][100];
vector<coord> friends;
coord entrain;
coord dernier[100][100];


bool dedans(coord point)
{
	if(point.x < 1 || point.y < 1) return false;
	if(point.y - point.x >= S) return false;
	if(point.x - point.y >= S) return false;
	if(point.x >= 2*S || point.y >= 2*S) return false;
	return true;
}

void cherche_amis(coord point)
{
	int i;
	coord ami;
	deja_ami[point.x][point.y] = true;
	friends.push_back(point);
	
	for(i = 0; i < 6; i++)
	{
		ami.x = point.x + moves[i].x;
		ami.y = point.y + moves[i].y;
		if(dedans(ami) && tableau[ami.x][ami.y] && !deja_ami[ami.x][ami.y])
		{
			cherche_amis(ami);
		}
	}
	
}

bool contour(coord point)
{
	if(point.x == 1 || point.y == 1) return true;
	if(point.x == 2*S-1 || point.y == 2*S-1) return true;
	if(point.x - point.y == S-1) return true;
	if(point.y - point.x == S-1) return true;
	return false;
}
/*
bool internalise(coord point)
{
	int i;
	coord ami;
	deja_ami[point.x][point.y] = true;
	valeur[point.x][point.y] = true;
	if(contour(point))
	{
		valeur[point.x][point.y] = false;
		return false;
	}
	for(i = 0; i < 6; i++)
	{
		ami.x = point.x + moves[i].x;
		ami.y = point.y + moves[i].y;
		if(!dedans(ami) || tableau[ami.x][ami.y])
		{
			// On s'en fout
		}
		else if(deja_ami[ami.x][ami.y])
		{
			if(!valeur[point.x][point.y]) return false;
		}
		else
		{
			if(!internalise(ami)) return false;
		}
	}
	return true;
}
*/


bool cercle(coord point)
{
	int i;
	bool final;
	coord ami;
	deja_ami[point.x][point.y] = true;
	
	if(contour(point)) return false;
	for(i = 0; i < 6; i++)
	{
		ami.x = point.x + moves[i].x;
		ami.y = point.y + moves[i].y;
		if(dedans(ami) && !tableau[ami.x][ami.y] && !deja_ami[ami.x][ami.y])
		{
			final = cercle(ami);
			if(!final) return false;
		}
	}
	return true;
}




bool checke(coord point)
{
	int i, j, k;
	bool corner[6];
	bool cote[6];
	int nombre_corner = 0, nombre_cote = 0;
	bool ring = false;
	coord pote;
	for(i = 0; i < 6; i++)
	{
		corner[i] = false;
		cote[i] = false;
	}
	cherche_amis(point);
	for(i = 0; i < 2*S; i++)
	{
		for(j = 0; j < 2*S; j++)
		{
			deja_ami[i][j] = false;
		}
	}
	
	friends.clear();
	cherche_amis(point);
	
	for(i = 0; i < friends.size(); i++)
	{
		if(!corner[0])
		{
			if(friends[i].x == 1 && friends[i].y == 1)
			{
				corner[0] = true;
				nombre_corner++;
			}
		}
		if(!corner[1])
		{
			if(friends[i].x == 1 && friends[i].y == S)
			{
				corner[1] = true;
				nombre_corner++;
			}
		}
		if(!corner[2])
		{
			if(friends[i].x == S && friends[i].y == 1)
			{
				corner[2] = true;
				nombre_corner++;
			}
		}
		if(!corner[3])
		{
			if(friends[i].x == S && friends[i].y == 2*S-1)
			{
				corner[3] = true;
				nombre_corner++;
			}
		}
		if(!corner[4])
		{
			if(friends[i].x == 2*S-1 && friends[i].y == S)
			{
				corner[4] = true;
				nombre_corner++;
			}
		}
		if(!corner[5])
		{
			if(friends[i].x == 2*S-1 && friends[i].y == 2*S-1)
			{
				corner[5] = true;
				nombre_corner++;
			}
		}
		
		
		if(!cote[0])
		{
			if(friends[i].x == 1 && friends[i].y > 1 && friends[i].y < S)
			{
				cote[0] = true;
				nombre_cote++;
			}
		}
		if(!cote[1])
		{
			if(friends[i].y == 1 && friends[i].x > 1 && friends[i].x < S)
			{
				cote[1] = true;
				nombre_cote++;
			}
		}
		if(!cote[2])
		{
			if(friends[i].y - friends[i].x == S-1 && friends[i].x > 1 && friends[i].x < S)
			{
				cote[2] = true;
				nombre_cote++;
			}
		}
		if(!cote[3])
		{
			if(friends[i].x - friends[i].y == S-1 && friends[i].y > 1 && friends[i].y < S)
			{
				cote[3] = true;
				nombre_cote++;
			}
		}
		if(!cote[4])
		{
			if(friends[i].y == 2*S-1 && friends[i].x > S && friends[i].x < 2*S-1)
			{
				cote[4] = true;
				nombre_cote++;
			}
		}
		if(!cote[5])
		{
			if(friends[i].x == 2*S-1 && friends[i].y > S && friends[i].y < 2*S-1)
			{
				cote[5] = true;
				nombre_cote++;
			}
		}
	}
	
	for(i = 0; i < 6 && !ring; i++)
	{
		pote.x = point.x + moves[i].x;
		pote.y = point.y + moves[i].y;

		if(dedans(pote) && !tableau[pote.x][pote.y])
		{
			for(k = 0; k < 100; k++)
			{
				for(j = 0; j < 100; j++)
				{
					deja_ami[k][j] = false;
				}
			}
			ring = cercle(pote);
		}

	}
	
	
	if(nombre_cote >= 3 && nombre_corner >= 2 && ring)
	{
		printf("bridge-fork-ring in move %d\n", mo+1);
		return false;
	}
	else if(nombre_cote >= 3 && ring)
	{
		printf("fork-ring in move %d\n", mo+1);
		return false;
	}
	else if(nombre_corner >= 2 && ring)
	{
		printf("bridge-ring in move %d\n", mo+1);
		return false;
	}
	else if(nombre_cote >= 3 && nombre_corner >= 2)
	{
		printf("bridge-fork in move %d\n", mo+1);
		return false;
	}
	else if(ring)
	{
		printf("ring in move %d\n", mo+1);
		return false;
	}
	else if(nombre_cote >= 3)
	{
		printf("fork in move %d\n", mo+1);
		return false;
	}
	else if(nombre_corner >= 2)
	{
		printf("bridge in move %d\n", mo+1);
		return false;
	}
	
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			deja_ami[i][j] = false;
		}
	}
	
	return true;
}

int main()
{
	int T, i, j, test;
	coord point;
	bool fini;
	scanf("%d", &T);
	moves[0].x = 1;
	moves[0].y = 1;
	moves[1].x = 1;
	moves[1].y = 0;
	moves[2].x = 0;
	moves[2].y = -1;
	moves[3].x = -1;
	moves[3].y = -1;
	moves[4].x = -1;
	moves[4].y = 0;
	moves[5].x = 0;
	moves[5].y = 1;
	for(test = 1; test <= T; test++)
	{
		printf("Case #%d: ", test);
		scanf("%d %d", &S, &M);
		for(i = 0; i < 100; i++)
		{
			for(j = 0; j < 100; j++) tableau[i][j] = false;
		}
		fini = true;
		for(mo = 0; mo < M; mo++)
		{
			scanf("%d %d\n", &point.x, &point.y);
			tableau[point.x][point.y] = true;
			if(fini) fini = checke(point);
		}
		if(fini) printf("none\n");
	}
	return 0;
}
