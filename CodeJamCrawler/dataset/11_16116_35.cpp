#include <iostream>
using namespace std;

int main()
{
	int t, tt = 0;
	int n;
	char str[110][110];
	freopen("A-large.in", "r+", stdin);
	freopen("A-large.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		double wp[110] = {0};
		double wp2[110] = {0};
		double owp[110] = {0};
		double oowp[110] = {0};
		for (int i = 0; i < n; i++)
		{
			double a = 0, b = 0;
			for (int j = 0; j < n; j++)
			{
				if (str[i][j] != '.')
				{
					a++;
				}
				if (str[i][j] == '1')
				{
					b++;
				}
			}
			wp[i] = b / a;
		}
		for (int i = 0; i < n; i++)
		{
			double sum = 0, num = 0;
			for (int j = 0; j < n; j++)
			{
				double a = 0, b = 0;
				if (str[i][j] != '.')
				{
					for (int k = 0; k < n; k++)
					{
						if (k != i)
						{
							if (str[j][k] != '.')
							{
								a++;
								if (str[j][k] == '1')
								{
									b++;
								}
							}
						}
					}
					sum += b / a;
					num++;
				}
			}
			owp[i] = sum / num;
		}
		for (int i = 0; i < n; i++)
		{
			double sum = 0, num = 0;
			for (int j = 0; j < n; j++)
			{
				if (str[i][j] != '.')
				{
					sum += owp[j];
					num++;
				}
			}
			oowp[i] = sum / num;
		}
		printf("Case #%d:\n", ++tt);
		for (int i = 0; i < n; i++)
		{
			printf("%lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
		}
	}
	return 0;
}