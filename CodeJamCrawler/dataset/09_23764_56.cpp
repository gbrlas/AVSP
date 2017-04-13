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

#define MAX 32

int v[MAX];
int v2[MAX];


char n[MAX];
char resp[MAX];


void vai()
{
	int i, j;
	int t;

	t = strlen(n);

	for (i = t-2; i >= 0; i--)
	{
		if (n[i] < n[i+1])
		{
			break;
		}
	}

	if (i < 0)
	{
		char ttt;
		for (j=t-1; j>=0; j--)
		{
			if (n[j]!='0')
			{
				ttt = n[j];
				n[j] = n[t-1];
				n[t-1] = ttt;
				break;
			}
		}
		
		putchar(n[t-1]);
		putchar('0');
		for (i=t-2; i>=0; i--)
		{
			putchar (n[i]);
		}
		putchar ('\n');
		return;
	}


	char menor = n[i+1];
	int q = i+1;

	for (j=i+2; n[j]; j++)
	{
		if (n[j] > n[i] && n[j] < menor)
		{
			menor = n[j];
			q = j;
		}
	}

	int a;

	for (a=0; a<i; a++)
	{
//		putchar('.');
		putchar(n[a]);
//			putchar('.');
	}

	putchar(menor);

	char v[MAX];
	int qq = 0;

	for (a = t-1; a > q; a--)
	{
		v[qq] = n[a];
		qq++;
	}

	v[qq] = n[i];
		qq++;

	for (a = q-1; a > i; a--)
	{
		v[qq] = n[a];
		qq++;
	}

	v[qq] = 0;

	sort(v, v+qq);

	printf("%s", v);

	putchar ('\n');


}


int main()
{
	int cas, casos;

	scanf("%d", &casos);

	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d: ", cas);
//		break;
		scanf("%s", n);
		vai();
	}

	return 0;
}
