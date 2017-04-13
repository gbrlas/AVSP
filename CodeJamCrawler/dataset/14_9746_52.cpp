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
	long long int N, p, q, r, s;
	long long int a[1000000];
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "--- Case #%d ---\n", t);
		printf("Case #%d: ", t);
		
		scanf("%lld %lld %lld %lld %lld\n", &N, &p, &q, &r, &s);
		
		long long int total = 0;
		
		for(int i = 0; i < N; i++)
		{
			a[i] = ((long long int)i*p + q)%r + s;
			total += a[i];
		}
		
		long long int prems = 0;
		long long int poss;
		long long int best = -1;
		int ou = -1;
		
		for(int i = 0; i < N; i++)
		{
			prems += a[i];
			if(3*prems <= total) ou = i;
		}
		
		int ou2 = N;
		prems = 0;
		for(int i = N-1; i >= 0; i--)
		{
			prems += a[i];
			if(3*prems <= total) ou2 = i;
		}
		
		// Soit on prend [0, ou] et [ou+1, x]
		
		long long int x = 0, y = 0, z = 0;
		
		for(int i = 0; i <= ou; i++)
		{
			x += a[i];
		}
		
		for(int i = ou+1; i < N; i++)
		{
			y += a[i];
			z = total - x - y;
			poss = max(x, max(y, z));
			if(best == -1 || best > poss) best = poss;
		}
		
		// Soit on prend de l'autre coté
		
		x = 0;
		y = 0;
		z = 0;
		
		for(int i = N-1; i >= ou2; i--)
		{
			x += a[i];
		}
		
		for(int i = ou2-1; i >= 0; i--)
		{
			y += a[i];
			z = total - x - y;
			poss = max(x, max(y, z));
			if(best == -1 || best > poss) best = poss;
		}
		
		// Soit autre
		x = 0;
		y = 0;
		z = 0;
		
		if(ou+1 < ou2-1)
		{
			for(int i = 0; i <= ou+1; i++) x += a[i];
			for(int i = N-1; i >= ou2-1; i--) y += a[i];
			z = total-x-y;
			poss = max(x, max(y, z));
			if(best == -1 || best > poss) best = poss;
		}
		
		printf("%.12lf\n", (double)(total-best)/(double)total);
	}

	return 0;
}
