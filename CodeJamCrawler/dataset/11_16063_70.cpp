#include <iostream>
using namespace std;

int n;
struct node
{
	char color[2];
	int pos;
}hall[110];
int dp[110][2];

int lmax(int a, int b)
{
	return a > b ? a : b;
}

int Cha(int a, int b)
{
	return a > b ? a - b : b - a;
}

int main()
{
	int i, j, t;
	int id = 0;
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A-small-attempt3.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%s %d", hall[i].color, &hall[i].pos);
		}
		int lasto = 0;
		int lastb = 0;
		int preo = 1;
		int preb = 1;
		for (i = 1; i <= n; i++)
		{
			if (hall[i].color[0] == 'O')
			{
				if (lasto > lastb)
				{
					lasto += Cha(hall[i].pos, preo) + 1;
					preo= hall[i].pos;
				}
				else
				{
					lasto = lmax(lastb + 1, lasto + Cha(hall[i].pos, preo) + 1);
					preo= hall[i].pos;
				}
			}
			else if (hall[i].color[0] == 'B')
			{
				if (lastb > lasto)
				{
					lastb += Cha(hall[i].pos, preb) + 1;
					preb = hall[i].pos;
				}
				else
				{
					lastb = lmax(lasto + 1, lastb + Cha(hall[i].pos, preb) + 1);
					preb = hall[i].pos;
				}
			}
		}
		printf("Case #%d: %d\n", ++id, lmax(lasto, lastb));
	}
	return 0;
}
