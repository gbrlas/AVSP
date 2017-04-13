#include <iostream>
#include <algorithm>

using namespace std;

struct
{
	long time;
	bool inA;
} tr[256];

struct TRIP
{
	long be;
	long en;
};

long t, A, B, mtr, pause;
TRIP tA[128], tB[128];
long ta, tb, reA, reB;

bool le(TRIP t1, TRIP t2)
{ return t1.be < t2.be; }

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &t);
	for (long a = 0; a < t; a ++)
	{
		// init
		mtr = 0;
		ta = tb = 0;
		reA = reB = 0;

		// input
		scanf("%d", &pause);
		scanf("%d %d", &A, &B);
		long x1, y1, x2, y2;
		for (long b = 0; b < A; b ++)
		{
			scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
			tA[b].be = x1*60+y1;
			tA[b].en = x2*60+y2;
		}
		for (long b = 0; b < B; b ++)
		{
			scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
			tB[b].be = x1*60+y1;
			tB[b].en = x2*60+y2;
		}
		sort(&tA[0], &tA[A], le);
		sort(&tB[0], &tB[B], le);
		tA[A].be = -1;
		tB[B].be = -1;

		// algo
		for (long b = 0; b < 24*60; b ++)
		{
			while (tA[ta].be == b)
			{
				bool f = 0;
				for (long c = 0; c < mtr; c ++)
					if (tr[c].inA && !tr[c].time)
					{
						tr[c].inA = 0;
						tr[c].time = tA[ta].en - tA[ta].be + pause;
						f = 1;
						break;
					}
				if (!f)
				{
					reA++;
					mtr++;
					tr[mtr-1].inA = 0;
					tr[mtr-1].time = tA[ta].en - tA[ta].be + pause;
				}
				ta++;
			}

			while (tB[tb].be == b)
			{
				bool f = 0;
				for (long c = 0; c < mtr; c ++)
					if (!tr[c].inA && !tr[c].time)
					{
						tr[c].inA = 1;
						tr[c].time = tB[tb].en - tB[tb].be + pause;
						f = 1;
						break;
					}
				if (!f)
				{
					reB++;
					mtr++;
					tr[mtr-1].inA = 1;
					tr[mtr-1].time = tB[tb].en - tB[tb].be + pause;
				}
				tb++;
			}

			for (long c = 0; c < mtr; c ++)
				if (tr[c].time) tr[c].time--;
		}

		// output
		printf("Case #%d: %d %d\n", a+1, reA, reB);
	}
	return 0;
}