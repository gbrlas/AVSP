#include <stdio.h>

void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubblesort(int list[],int n){
	int i,j;
	for(i=0;i<(n-1);i++)
		for(j=0;j<(n-(i+1));j++)
			if(list[j] > list[j+1])
				swap(&list[j],&list[j+1]);
}

int main(){

	FILE *fr, *fw;
	int cases, T=0, N, seq[1000], pile1, PatPile1, PatPile2, pile2, index;
	long long max=0;

	fr = fopen("C-large.in", "r");
	fw = fopen("C-large.out", "w");

	fscanf(fr, "%d", &cases);

	while(!feof(fr)){
		pile1=0;
		pile2=0;
		PatPile1=0;
		PatPile2=0;
		index=0;
		T++;
		max=0;
		if(T>cases)
			break;
		fscanf(fr, "%d", &N);

		for(int i=0; i<N; i++){
			fscanf(fr, "%d ", &seq[i]);
		}

		bubblesort(seq, N);

		for(int i=0; i<N-1; i++){
			pile1=0;
			pile2=0;
			PatPile1=0;
			PatPile2=0;
			for(index=0; index<=i; index++){
				PatPile1 = PatPile1^seq[index];
				pile1 += seq[index];
			}
			for(;index<N; index++){
				PatPile2 = PatPile2^seq[index];
				pile2 += seq[index];
			}

			if(PatPile1==PatPile2 && (pile1>max || pile2>max)){
				if (pile1>pile2)
					max = pile1;
				else
					max = pile2;
			}
		}

		if(max==0)
			fprintf(fw, "Case #%d: NO\n", T);
		else
			fprintf(fw, "Case #%d: %d\n", T, max);
	}


	fclose(fr);
	fclose(fw);
}