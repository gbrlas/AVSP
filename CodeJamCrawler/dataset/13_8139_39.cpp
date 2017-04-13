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

set<long long int> endpoints;
set<long long int>::iterator it;
map<long long int,long long int> m;
long long int N, M;

long long int modulo = 1000002013;

long long int minimum(long long int a, long long int b)
{
	if(a > b) return b;
	else return a;
}

long long int prix(long long int x)
{
	return (x*N - x*(x-1)/2) % modulo;
}

int main()
{
	int T, t;
	long long int i, j;
	priority_queue<pair<pair<int,int>, int> > q;
	pair<pair<long long int,long long int>, long long int> encours;
	long long int ou;
	long long int o, e, p;
	long long int station[2000], comb;
	long long int dela[2000];
	long long int pour[2000];
	long long int debarquement;
	long long int total, autre;
	scanf("%d\n", &T);
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%lld %lld", &N, &M);
		total = 0;
		autre = 0;
		endpoints.clear();
		m.clear();
		comb = 0;
		for(i = 0; i < M; i++)
		{
			scanf("%lld %lld %lld", &o, &e, &p);
			q.push(make_pair(make_pair(0-o, e), p));
			endpoints.insert(o);
			endpoints.insert(e);
			autre = (autre + prix(e-o)*p)%modulo;
		}
		
		for(it = endpoints.begin(); it != endpoints.end(); it++)
		{
			ou = *it;
			station[comb] = ou;
			m[ou] = comb;
			dela[comb] = 0;
			pour[comb] = 0;
			comb++;
		}
		
		for(i = 0; i < comb; i++)
		{
			// On est à la station i, le nombre de gens venant de j < i est dela[j]
			// Le nombre de gens qui doivent s'arreter à j >= i est pour[j]
			
			// On commence par embarquer les gens qui doivent embarquer
			while(!q.empty() && q.top().first.first == 0 - station[i])
			{
				encours = q.top();
				q.pop();
				dela[i] += encours.second;
				pour[m[encours.first.second]] += encours.second;
				//printf("On est en %d (%d), on embarque %d gens pour %d (%d)\n", i, station[i], encours.second, m[encours.first.second], encours.first.second);
			}
			
			// On a embarqué, maintenant on débarque pour[i] personnes. Autant débarquer celles qui ont embarqué le plus tard
			
			for(j = i; j >= 0 && pour[i] > 0; j--)
			{
				if(dela[j] > 0)
				{
					debarquement = minimum(pour[i], dela[j]);
					pour[i] -= debarquement;
					dela[j] -= debarquement;
					// On doit payer tous les voyages de station[j] à station[i]
					total = (total + debarquement * prix(station[i]-station[j])) % modulo;
				}
			}
		}
		
		printf("%lld\n", (modulo + autre - total)%modulo);
		
	}

	return 0;
}
