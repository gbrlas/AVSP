#include <stdio.h>
#include <stdlib.h>
void sort (int arr[], int n) {
	int x,y, tmp ;
	for (x = 0; x < n; x ++) {
		for ( y = 0; y < n - 1; y ++) {
			if ( arr[y] < arr[y+1]) {
				tmp = arr[y];
				arr[y] = arr[y+1];
				arr[y+1] = tmp;
			}
		}
	}
}
void operation (char *filename) {
	FILE *fpin = fopen (filename,"r");
	FILE *fpout = fopen ("output", "w");
	if (!fpin && !fpout) {
		printf ("Enable to open file.\n");
		exit (1);
	}
	int count, iter, p, k, l, letters [1000], index;
	fscanf (fpin, "%d", &count);
	for (iter = 0 ; iter < count; iter ++) {
		fscanf (fpin, "%d %d %d", &p, &k, &l);
		if ( p * k < l ) {
			fprintf (fpout, "Case #%d: Impossible\n", iter + 1);
			continue;
		}
		for (index = 0; index < l; index ++) {
			fscanf (fpin,"%d",&letters [index]);
		}
		sort (letters, l); int multiply = 1, sum = 0;
		for (index = 0; index < l; index ++) {
			sum += letters [index] * multiply;
			if ((index + 1) % k == 0)
				multiply ++;
		}
		fprintf (fpout, "Case #%d: %d\n",iter + 1, sum);	
	}
	fclose (fpin); fclose (fpout);
}

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf ("Invalid arguments.\n");
		exit (1);
	}
	operation (argv[1]);
} 
