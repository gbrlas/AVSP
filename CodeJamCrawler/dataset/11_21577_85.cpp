#include <stdio.h>

struct Zadanie
{
	int czas;
	int przycisk;
};

int abs(int x)
{
	return (x >= 0) ? x : -x;
}

Zadanie b[128];
Zadanie o[128];

int zb, zo;
int ib, io;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i != n; i++)
	{
		zb = 0;
		zo = 0;

		int k;
		scanf("%d", &k);

		for (int j = 0; j != k; j++)
		{
			char r[4];
			int p;
			scanf("%s %d", r, &p);
			if (r[0] == 'B')
			{
				b[zb].czas = j;
				b[zb++].przycisk = p;
			}
			else
			{
				o[zb].czas = j;
				o[zo++].przycisk = p;
			}
		}

		o[zb].czas = 1000;
		b[zb].czas = 1000;

		ib = 0;
		io = 0;
		int t = 0;
		int pb = 1;
		int po = 1;

		for (int j = 0; j != k; j++)
		{
			if (b[ib].czas == j)
			{
				int rt = abs(b[ib].przycisk - pb) + 1;
				t += rt;
				pb = b[ib++].przycisk;
				if (po > o[io].przycisk)
				{
					if (po - o[io].przycisk > rt) po -= rt;
					else po = o[io].przycisk;
				}
				else
				{
					if (o[io].przycisk - po > rt) po += rt;
					else po = o[io].przycisk;
				}
			}
			else
			{
				int rt = abs(o[io].przycisk - po) + 1;
				t += rt;
				po = o[io++].przycisk;
				if (pb > b[ib].przycisk)
				{
					if (pb - b[ib].przycisk > rt) pb -= rt;
					else pb = b[ib].przycisk;
				}
				else
				{
					if (b[ib].przycisk - pb > rt) pb += rt;
					else pb = b[ib].przycisk;
				}
			}
		}

		printf("Case #%d: %d\n", i+1, t);
	}

	return 0;
}
