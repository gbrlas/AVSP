#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))

#define MAX (50000+10)
#define MM 16

char buff[MAX];
char b[MAX];

int tam;
int menor;
int k;
int foi[MM];
int v[MM];

void testa()
{
	int i, j;

	for (i=0; i < tam; i+=k)
	{
		for (j=0; j<k; j++)
		{
			b[i+j] = buff[i+v[j]];
		}
	}

	j = 1;
	for (i=1; i<tam ;i++)
	{
		if (b[i]!=b[i-1])
		{
			j++;
		}
	}
	if (j < menor)
		menor = j;
}

void bt(int p)
{
	int i;

	if (p==k)
	{
		for (i=0; i<k; i++)
		{
	//		printf("%d ", v[i]);
		}

		testa();
		return;
	}

	for (i=0; i<k; i++)
	{
		if (!foi[i])
		{
			v[p] = i;
			foi[i] = 1;
			bt(p+1);
			foi[i] = 0;
		}
	}

}

int main()
{
	int casos, cas;

	scanf("%d",&casos);

	for (cas = 1; cas <= casos; cas++)
	{
		printf("Case #%d: ",cas);

		scanf("%d %s", &k, buff);

		menor = 50000+10;
		memset(foi, 0, sizeof(foi));
		tam = strlen(buff);
		bt(0);

		printf("%d\n", menor);

	}

	return 0;
}
