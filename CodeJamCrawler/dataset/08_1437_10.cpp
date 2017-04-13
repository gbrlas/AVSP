#include <stdio.h>

int minx[6000];
int maxx[6000];
int miny[6000];
int maxy[6000];

char map[6100][6100];

int main()
{
	int n;
	scanf("%d", &n);
	for (int cc=1; cc<=n; cc++)
	{
		int l;
		scanf("%d ", &l);

		int x = 0, y = 0, dir = 0;
		int area = 0;
		for (int i=0; i<6100; i++) minx[i] = miny[i] = 10000;
		for (int i=0; i<6100; i++) maxx[i] = maxy[i] = -10000;
		for (int i=0; i<l; i++)
		{
			char path[40];
			int rep;

			scanf("%s %d ", path, &rep);
			while(rep--)
				for (char *p = path; *p; p++)
				{
					if (*p == 'R') dir = (dir+1) % 4;
					else if (*p == 'L') dir = (dir+3) % 4;
					else switch(dir)
					{
						case 0: if (minx[3050+y] > x) minx[3050+y] = x; if (maxx[3050+y] < x) maxx[3050+y] = x; y++; break;
						case 1: if (miny[3050+x] > y) miny[3050+x] = y; if (maxy[3050+x] < y) maxy[3050+x] = y; x++; area += y; break;
						case 2: y--; if (minx[3050+y] > x) minx[3050+y] = x; if (maxx[3050+y] < x) maxx[3050+y] = x; break;
						case 3: x--; if (miny[3050+x] > y) miny[3050+x] = y; if (maxy[3050+x] < y) maxy[3050+x] = y; area -= y; break;
					}
				}
		}
		if (area < 0) area = -area;

		for (int x=-3000; x<=3000; x++) for (y=-3000; y<=3000; y++)
			if ((minx[3050+y] <= x && x < maxx[3050+y]) ||
			    (miny[3050+x] <= y && y < maxy[3050+x])) area--;
		printf("Case #%d: %d\n", cc, -area);
	}
	return 0;
}
