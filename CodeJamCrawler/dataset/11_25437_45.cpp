#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int t, n, x;
int xorsum, sum, minsum;

int main()
{
	scanf("%d", &t);
	for(int e=1; e<=t; e++)
	{
		scanf("%d", &n);
		minsum = 1100100;
		xorsum = 0;
		sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &x);
			sum += x;
			xorsum ^= x;
			minsum = min(minsum, x);
		}
		if(xorsum == 0)
		{
			printf("Case #%d: %d\n", e, sum - minsum);
		}
		else
		{
			printf("Case #%d: NO\n", e);
		}
	}
	return 0;
}


/*
map <int, int> M;

int main()
{
	scanf("%d", &t);
	for(int e=1; e<=t; e++)
	{
		scanf("%d", &n);
		M.clear();
		M[0] = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &x);
			for(map <int, int>::iterator it = M.begin(); it != M.end(); it++)
			{
				
		printf("Case #%d: ", e);
	}
	return 0;
}
*/