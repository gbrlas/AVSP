#include<stdio.h>
int a[4][4];
int b[17],c[17];
int main(){

	int t, i, j, k, n, cnt = 0,y;
	FILE *input, *output;
	input = fopen("A-small-attempt1.in", "r");
	output = fopen("A-small-attempt1.out", "w");

	fscanf(input, "%d", &t);
	for (i = 0; i < t; i++){
		
		fscanf(input, "%d", &n);
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				fscanf(input, "%d ", &a[j][k]);
				if (j == n - 1)
					b[a[j][k]] = 1;
			}
		}
		fscanf(input, "%d", &n);
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++){
				fscanf(input, "%d", &a[j][k]);
				if (j == n - 1)
					c[a[j][k]] = 1;
			}
		}
		y = 0; cnt = 0;
		for (j = 1; j <= 16; j++){
			if (b[j] == 1 && c[j] == 1){
				if (cnt == 0){
					cnt++;
					y = j;
				}
				else{
					fprintf(output, "Case #%d: Bad magician!\n", i+1);
					cnt++;
					break;
				}
			}
		}
		if (cnt == 0)
			fprintf(output, "Case #%d: Volunteer cheated!\n", i+1);
		else if (cnt == 1)
			fprintf(output, "Case #%d: %d\n",i+1, y);
		for (j = 1; j <= 16; j++){
			b[j] = 0; c[j] = 0;
		}
	}
	fclose(input);
	fclose(output);

	return 0;
}