#include <stdio.h>

int n, m;
char a [100][100];
bool possible;

int main ()
{
	FILE *in = fopen ("A-small.in", "r");
	FILE *out = fopen ("A-small.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int t = 0; t < numt; t++)
	{
		fscanf (in, "%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				char c = ' ';
				while ((c != '#') && (c != '.'))
					fscanf (in, "%c", &c);
				a [i][j] = c;
			}

		possible = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a [i][j] == '#')
				{
					if ((i < n - 1) && (j < m - 1) && (a [i][j + 1] == '#') && (a [i + 1][j] == '#') && (a [i + 1][j + 1] == '#'))
					{
						a [i][j] = '/';
						a [i][j + 1] = '\\';
						a [i + 1][j] = '\\';
						a [i + 1][j + 1] = '/';
					}
					else
					{
						possible = false;
						break;
					}
				}
		
		fprintf (out, "Case #%d:\n", t + 1);
		if (possible)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					fprintf (out, "%c", a [i][j]);
				fprintf (out, "\n");
			}
		}
		else
			fprintf (out, "Impossible\n");
	}
	fclose (in);
	fclose (out);
	return 0;
}
