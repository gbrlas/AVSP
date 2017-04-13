#include <stdio.h>
#include <stdlib.h>

#define MAX 128

int na, nb;

typedef struct
{
	int x, y;
	int ori;
}tipo;

tipo va[MAX], vb[MAX];
tipo v[MAX+MAX];
int r[2];

int fc(const void *e1, const void *e2)
{
	tipo *p1, *p2;

	p1 = (tipo*)e1;
	p2 = (tipo*)e2;

	return p1->x - p2->x;
}

int tem[2][MAX];
int q[2];

int testa(tipo a)
{
	int min, qual;

	int i;

	if (q[a.ori] == 0)
		return 0;
	min = tem[a.ori][0];
	qual = 0;

	for (i=1; i<q[a.ori]; i++)
	{
		if (tem[a.ori][i] < min)
		{
			min = tem[a.ori][i];
			qual = i;
		}
	}

	if (min <= a.x)
	{
		tem[a.ori][qual]=tem[a.ori][q[a.ori]-1];
		q[a.ori]--;
		return 1;
	}
	return 0;
}

int main()
{
	int cas, casos, a, b, i, t;

	scanf("%d",&casos);

	for (cas=1; cas<=casos; cas++)
	{

		printf("Case #%d: ",cas);
		scanf("%d",&t);

		scanf("%d %d",&na, &nb);

		for (i=0; i<na; i++)
		{
			scanf("%d:%d", &a, &b);
			va[i].x = 60*a + b;
			scanf("%d:%d", &a, &b);
			va[i].y = 60*a + b;
			va[i].ori = 0;
		}

		for (i=0; i<nb; i++)
		{
			scanf("%d:%d", &a, &b);
			vb[i].x = 60*a + b;
			scanf("%d:%d", &a, &b);
			vb[i].y = 60*a + b;
			vb[i].ori = 1;
		}

		r[0] = r[1] = 0;

		for (i=0; i<na; i++)
		{
			v[i] = va[i];
		}

		for (i=0; i<nb; i++)
		{
			v[i+na] = vb[i];
		}

		qsort(v, na+nb, sizeof(v[0]), fc);

		q[0] = q[1] = 0;

		for (i=0; i<na+nb; i++)
		{
			if (!testa(v[i]))
			{
				r[v[i].ori]++;
			}
/*			printf("%d %d\n", i, v[i].ori);
*/			tem[(v[i].ori+1)%2][q[(v[i].ori+1)%2]] = v[i].y+t;
			q[(v[i].ori+1)%2]++;
		}
		printf("%d %d\n",r[0], r[1]);

	}
	return 0;
}
