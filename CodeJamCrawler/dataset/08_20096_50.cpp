#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void
sort(int *a, int n)
{
	int i, j;
	int temp[100];
 	int count;
	int same;
	int s;

	memset(temp, 0, 100);

	for (i = 0; i < n; i++)
	{
		count = 0;
		same = 0;

		for (j = 0; j < n; j++)
		{
			if (a[i] > a[j])
				count++;

			if (a[i] == a[j])
				same++;

		}

		temp[count] = a[i];

		for (j = 0; j < same; j++)
		{
			temp[count + j] = a[i];
		}
	}

	memcpy(a, temp, sizeof(int) * n);
}


int
main(int argc, char **argv)
{
	int n, i, j ,k;
	FILE *fp, *fp_out;
	char filename[32];
	int na, nb, t;
	char t_a[8];
	char t_d[8];
	struct tm tm_aa[100];
	struct tm tm_ad[100];
	struct tm tm_ba[100];
	struct tm tm_bd[100];
	int t_aa[100], t_ad[100], t_ba[100], t_bd[100];
	int a_train, b_train;
	int a_count, b_count;


	sprintf(filename, "%s.txt", argv[1]);

	fp = fopen(argv[1], "r");
	fp_out = fopen(filename, "w");

	fscanf(fp, "%d\n", &n);
	printf("%d\n", n);

	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d\n", &t);
		printf("%d\n", t);
		fscanf(fp, "%d %d\n", &na, &nb);
		printf("%d %d\n", na, nb);

		for (j = 0; j < na; j++)
		{
			fscanf(fp, "%s %s\n", t_d, t_a);
			printf("%s %s\n", t_d, t_a);
			strptime(t_a, "%H:%M", &tm_aa[j]);
			strptime(t_d, "%H:%M", &tm_ad[j]);
			t_aa[j] = tm_aa[j].tm_hour * 60 + tm_aa[j].tm_min;
			t_ad[j] = tm_ad[j].tm_hour * 60 + tm_ad[j].tm_min;
			printf("%d %d\n", t_ad[j], t_aa[j]);
		}

		sort(t_ad, na);
		sort(t_aa, na);
		

		for (j = 0; j < na; j++)
			printf("%d\n", t_ad[j]);
		for (j = 0; j < na; j++)
			printf("%d\n", t_aa[j]);

		for (k = 0; k < nb; k++)
		{
			fscanf(fp, "%s %s\n", t_d, t_a);
			printf("%s %s\n", t_d, t_a);
			strptime(t_a, "%H:%M", &tm_ba[k]);
			strptime(t_d, "%H:%M", &tm_bd[k]);
			t_ba[k] = tm_ba[k].tm_hour * 60 + tm_ba[k].tm_min;
			t_bd[k] = tm_bd[k].tm_hour * 60 + tm_bd[k].tm_min;
			printf("%d %d\n", t_bd[k], t_ba[k]);
		}

		sort(t_bd, nb);
		sort(t_ba, nb);

		for (j = 0; j < nb; j++)
			printf("%d\n", t_bd[j]);
		for (j = 0; j < nb; j++)
			printf("%d\n", t_ba[j]);


		a_train = b_train = 0;

		for (j = 0; j < na; j++)
		{
			for (k = 0; k < nb; k++)
			{
				if (t_ad[j] < (t_ba[k] + t))
					continue;

				t_ba[k] = 60 * 25;
				break;
			}

			if (k != nb)
				continue;

			a_train++;
		}

		for (j = 0; j < nb; j++)
		{
			for (k = 0; k < na; k++)
			{
				if (t_bd[j] < (t_aa[k] + t))
					continue;

				t_aa[k] = 60 * 25;
				break;
			}

			if (k != na)
				continue;

			b_train++;
		}

		printf("%d %d\n", a_train, b_train);
		fprintf(fp_out, "Case #%d: %d %d\n", i+1, a_train, b_train);
	}	



	return 0;
}
