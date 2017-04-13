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

double money[1048576];
int N;

double howmany(int x)
{
	if(money[x] >= -0.5)
	{
		return money[x];
	}
	
	if(x == (1 << N) - 1) return 0;
	
	double total = 0;
	double c;
	for(int i = 0; i < N; i++)
	{
		// arrive in i
		c = N;
		int j = i;
		while(x & (1 << j))
		{
			j = (j + N - 1)%N;
			c--;
		}
		
		c += howmany(x | (1 << j));
		total += (double)c;

	}
	
	money[x] = total/(double)N;

	return money[x];
	
}

int main()
{
	int i, j, k, T, t;
	
	scanf("%d\n", &T);
	
	string s;
	
	int start;
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		cin >> s;
		
		N = s.size();
		
		start = 0;
		
		for(i = 0; i < N; i++)
		{
			if(s[i] == 'X')
			{
				start++;
			}
			start *= 2;
		}
		start /= 2;
		
		for(i = 0; i < (1 << N); i++)
		{
			money[i] = -1;
		}
	
		//fprintf(stderr, "Start : %d\n", start);
		printf("%.12lf\n", howmany(start));
		
		
		
		
	}

	return 0;
}
