#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define MAX 16

int v[MAX];
int v2[MAX];


int n;

int vai(int n)
{
//	int i;
	memset(v, 0, sizeof(v));

	while (n)
	{
		v[n%10]++;
		n/=10;
	}
	return 0;
}

int eh(int k)
{
	int i;
	memset(v2, 0, sizeof(v2));

	while (k)
	{
		v2[k%10]++;
		k/=10;
	}

	for (i=1; i<=9; i++)
	{
		if (v2[i]!=v[i])
		{
			return 0;
		}
	}
	return 1;

}

int main()
{
	int cas, casos;

	scanf("%d", &casos);

	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d: ", cas);

		scanf("%d", &n);
		vai(n);
		int i;

		for (i=n+1; ; i++)
		{
			if (eh(i))
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}
