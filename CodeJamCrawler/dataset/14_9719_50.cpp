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

vector<int> debut;
vector<int> fin;

int inserer(int x)
{
	debut.push_back(x);
	int compteur = 0;
	for(int i = debut.size()-1; i >= 1; i--)
	{
		if(debut[i] < debut[i-1])
		{
			debut[i] ^= debut[i-1];
			debut[i-1] ^= debut[i];
			debut[i] ^= debut[i-1];
			compteur++;
		}
		else return compteur;
	}
	return compteur;
}

int inserer2(int x)
{
	fin.push_back(x);
	int compteur = 0;
	for(int i = fin.size()-1; i >= 1; i--)
	{
		if(fin[i] < fin[i-1])
		{
			fin[i] ^= fin[i-1];
			fin[i-1] ^= fin[i];
			fin[i] ^= fin[i-1];
			compteur++;
		}
		else return compteur;
	}
	return compteur;
}

int main()
{
	int T;
	int N;
	vector<int> a;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		a.resize(N);
		
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
		}

		int petit;
		int ou;
		int debut = 0;
		int fin = N-1;
		
		int rep = 0;
		
		for(int i = 0; i < N; i++)
		{
			petit = 1000000002;
			for(int j = debut; j <= fin; j++)
			{
				if(a[j] < petit)
				{
					ou = j;
					petit = a[j];
				}
			}
			
			if(ou - debut < fin - ou)
			{
				// On met au début
				for(int k = ou; k > debut; k--)
				{
					rep++;
					a[k] ^= a[k-1];
					a[k-1] ^= a[k];
					a[k] ^= a[k-1];
				}
				debut++;
			}
			else
			{
				// On met a la fin
				for(int k = ou; k < fin; k++)
				{
					rep++;
					a[k] ^= a[k+1];
					a[k+1] ^= a[k];
					a[k] ^= a[k+1];
				}
				fin--;
			}
		}
		
		printf("%d\n", rep);

	}

	return 0;
}
