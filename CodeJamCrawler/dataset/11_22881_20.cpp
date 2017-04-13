#include <cstdio>
#include <cstring>

int T,N;
char table[100][100];
int win[100], total[100];
double WP[100], OWP[100], OOWP[100];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	int i,j,k;
	for (i = 1; i <= T; i++)
	{
		scanf("%d\n",&N);
		memset(total, 0, sizeof(total));
		memset(win, 0, sizeof(win));
		
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				table[j][k] = getchar();
				if (table[j][k] != '.')
					total[j]++;
				if (table[j][k] == '1')
					win[j]++;
			}
			WP[j] = OWP[j] = OOWP[j] =0;
			getchar();
		}

		for (j = 0; j < N; j++)
		{
			WP[j] = double(win[j])/total[j];
			int count = 0;
			for (k = 0; k < N; k++)
			{
				if (table[j][k] == '1')
				{
					OWP[j] += double(win[k])/(total[k] - 1);
					count++;
				}
				else if (table[j][k] == '0')
				{
					OWP[j] += double(win[k] - 1)/(total[k] - 1);
					count++;
				}			
			}
			OWP[j] /= count;
		}

		for (j = 0; j < N; j++)
		{
			int count = 0;
			for (k = 0; k < N; k++)
				if (table[j][k]!='.')
				{
					OOWP[j] += OWP[k];
					count++;
				}
			OOWP[j] /= count;
		}

		printf("Case #%d:\n", i);
		for (j = 0; j < N; j++)
			printf("%g\n", 0.25*WP[j] + 0.50 * OWP[j] + 0.25 * OOWP[j]);
	}
	return 0;
}