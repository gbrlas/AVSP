#include <stdio.h>

int w, h, k;
int a [101][101], d [101][101];
int numT, sol;

void solve ()
{
     for (int i = 0; i < h; i++)
         d [i][0] = 0;
     for (int j = 0; j < w; j++)
         d [0][j] = 0;
     d [0][0] = 1;
     for (int i = 1; i < h; i++)
         for (int j = 1; j < w; j++)
         {
             d [i][j] = 0;
             if (a [i][j] != -1)
             {
                 if ((i > 1) && (j > 0))
                     d [i][j] = (d [i][j] + d [i - 2][j - 1]) % 10007;
                 if ((i > 0) && (j > 1))
                     d [i][j] = (d [i][j] + d [i - 1][j - 2]) % 10007;
             }
         }
     sol = d [h - 1][w - 1] % 10007;     
}

int main ()
{
	FILE *in;
	FILE *out;
	in = fopen ("D-small1.in", "r");
	out = fopen ("D-small1.out", "w");

	fscanf (in, "%d", &numT);
    printf ("%d\n", numT);
	for (int t = 0; t < numT; t++)
	{
        fscanf (in, "%d %d %d", &w, &h, &k);
        printf ("%d\n", t);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                a [i][j] = 0;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            fscanf (in, "%d %d", &y, &x);
            x--; 
            y--;
            a [x][y] = -1;
        }
        
		solve ();
		
		fprintf (out, "Case #%d: %d\n", (t + 1), sol);
	}

	fclose (in);
	fclose (out);
	return 0;
}
