#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))

int fc(const void *e1, const void *e2)
{
	return 0;
}

#define MAX 8

int casos;
int n;

int x[MAX], y[MAX];
int foi[MAX];
int v[MAX];

int menor;

void bt(int prof)
{
	int i;
	int at;

	if (prof == n)
	{
		at = 0;
		for (i=0; i<n; i++)
		{
			at+=v[i]*y[i];
		}
		menor = MINI(at, menor);
		return;
	}

	for (i=0; i<n; i++)
	{
		if (!foi[i])
		{
			v[prof] = x[i];
			foi[i] = 1;
			bt(prof+1);
			foi[i] = 0;
		}
	}

}

int main()
{
	int cas, i;

	scanf("%d",&casos);

	for (cas=0; cas<casos; cas++)
	{
		scanf("%d",&n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &x[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &y[i]);
		}

		menor = 8*1000*1000 + 2;

		memset(foi, 0, sizeof(foi));

		bt(0);

		printf("Case #%d: %d\n", cas+1, menor);
	}

	return 0;
}
