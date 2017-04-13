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

long long int puissance(long long int n)
{
	long long int res = 1;
	while(n > 0)
	{
		res *= 2;
		n--;
	}
	return res;
}

long long int minimum(long long int a, long long int b)
{
	if(a > b) return b;
	return a;
}

int main()
{
	int i, j, T, t;
	scanf("%d\n", &T);
	long long int N;
	long long int P;
	long long int etremin;
	long long int total;
	
	long long int puis[51];
	long long int start;
	long long int qui;
	
	for(i = 0; i < 51; i++)
	{
		puis[i] = puissance(i);
	}
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%lld %lld\n", &N, &P);
		total = puis[N];
		etremin = total - P;
		// Le score à effectuer pour avoir un prix, type 110100 = WWLWLL
		//printf("%lld\n", etremin);
		
		// quel truc du style 000111 est au dessus de 110100
		
		long long int encours = 0;
		int nb_uns = 0;
		
		
		for(i = 0; i <= N-1; i++)
		{
			encours = puis[i];
			if(encours <= etremin) nb_uns++;
		}
		//printf("%d\n", nb_uns);
		long long int res = 0;
		for(i = 0; i < N - nb_uns; i++)
		{
			res += puis[i+1];
		}
		
		printf("%lld ", minimum(res, total - 1));
		
		// quel truc du style 111000 est au dessus de 110100
		
		encours = 0;
		nb_uns = 0;
		
		if(encours >= etremin) nb_uns++;
		
		for(i = N-1; i >= 0; i--)
		{
			encours += puis[i];
			if(encours >= etremin) nb_uns++;
		}
		
		//printf("-- %d --\n", nb_uns);
		
		res = 0;
		for(i = 0; i < nb_uns - 1; i++)
		{
			res += puis[N-i-1];
		}
		printf("%lld\n", res);
	}

	return 0;
}
