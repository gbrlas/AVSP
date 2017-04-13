#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char **argv)
{
	int n, i, j, k;
	FILE *fp;
	FILE *fp_out;
	char engine[100][101];
	char query[1000][101];
	int check[100];
	int e_num;
	int q_num;
	int match, sw;
	char filename[32];

	sprintf(filename, "%s.txt", argv[1]);

	fp = fopen(argv[1], "r");
	fp_out = fopen(filename, "w");

	fscanf(fp, "%d\n", &n);
	printf("%d\n", n);

	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d\n", &e_num);
		printf("%d\n", e_num);

		for (j = 0; j < e_num; j++)
		{
			fgets(engine[j], 100, fp);
			printf("%s", engine[j]);
		}

		fscanf(fp, "%d\n", &q_num);
		printf("%d\n", q_num);

		for (k = 0; k < q_num; k++)
		{
			fgets(query[k], 100, fp);
			printf("%s", query[k]);
		}

		memset(check, 0, sizeof(check));
		match = 0;
		sw = 0;

		for (k = 0; k < q_num; k++)
		{
			for (j = 0; j < e_num; j++)
			{
				if (strcmp(engine[j], query[k]) != 0)
					continue;

				if (check[j] == 1)
					break;

				check[j] = 1;

				match++;

				break;
			}

			if (match  != e_num)
				continue;

			sw++;

			memset(check, 0, sizeof(check));
			match = 1;
			check[j] = 1;
		}

		fprintf(fp_out, "Case #%d: %d\n", i+1, sw);
	}

	return 0;
}
