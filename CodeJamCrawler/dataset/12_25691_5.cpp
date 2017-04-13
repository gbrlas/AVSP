#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n, d;	

#define MAX (1<<14)

int v[MAX];
int l[MAX];



int busca()
{
	queue<pair<int,int> > fila;

	if (2*v[0] >= d)
		return 1;
		
	while (!fila.empty())
	{
		fila.pop();
	}	
	fila.push(make_pair(0, v[0]));
	
	int i;
	
	while (!fila.empty())
	{
		if (fila.front().second + v[fila.front().first] >= d)
			return 1;
		for (i=fila.front().first+1; i<n && v[i] <= fila.front().second + v[fila.front().first]; i++)
		{
			fila.push(make_pair (i, min(l[i], v[i]-v[fila.front().first])));
		}
		fila.pop();
	}
	return 0;
}

int main()
{
	int casos;
	int cas;
	int i;
		
	scanf("%d", &casos);
	
	for (cas = 1; cas <= casos; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d %d", &v[i], &l[i]);
		}	
		scanf("%d", &d);
		
		if (busca())
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
	
}
