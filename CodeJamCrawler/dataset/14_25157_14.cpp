#include<stdio.h>
FILE *in, *out;
int main(){
	
	double  c, f, x, n ,o;
	int i,cnt,j,t;

	in = fopen("B-small-attempt0.in", "r");
	out = fopen("B-small-attempt0.out", "w");

	fscanf(in, "%d", &t);
	for (i = 0; i < t; i++){
		fscanf(in, "%lf %lf %lf", &c, &f, &x);
		o = x / 2; cnt = 0;
		while (1){
			cnt++; n = 0.;
			for (j = 0; j <=cnt; j++){
				if (j == 0)
					n += c / 2;
				else if (j == cnt)
					n += x / (2 + cnt*f);
				else
					n += c / (2 + j*f);
			}
			if (o < n) break;
			o = n;
		}
		fprintf(out, "Case #%d: %.7lf\n", i + 1, o);
	}


	fclose(in);
	fclose(out);
}