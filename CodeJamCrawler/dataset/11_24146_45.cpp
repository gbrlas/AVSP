#include <stdio.h>

int main(){

	FILE *fr, *fw;
	int cases, T=0, N, posO, posB, time=0, pressed, index, O, B;
	int P[100], seqO[100], seqB[100];
	char R[100];
	fr = fopen("A-large.in", "r");
	fw = fopen("A-large.out", "w");

	fscanf(fr, "%d", &cases);

	while(!feof(fr)){
		time=0;
		O=0;
		B=0;
		index=0;
		posO=1;
		posB=1;
		pressed=0;
		T++;
		if(T>cases)
			break;
		fscanf(fr, "%d", &N);
		for(int i=0; i<N; i++){
			fscanf(fr, " %c %d", &R[i], &P[i]);
			if(R[i]=='O'){
				seqO[O]=P[i];
				O++;
			}
			else{
				seqB[B]=P[i];
				B++;
			}
		}
		O=0;
		B=0;
		while(pressed<N){
			time++;

			if(R[index]=='O'){
				if(posO==seqO[O]){
					pressed++;
					O++;
					index++;
				}
				else{
					if(posO<seqO[O])
						posO++;
					else
						posO--;
				}

				if(posB!=seqB[B]){
					if(posB<seqB[B])
						posB++;
					else
						posB--;
				}
				
			}
			else{

				if(posB==seqB[B]){
					pressed++;
					B++;
					index++;
				}
				else{
					if(posB<seqB[B])
						posB++;
					else
						posB--;
				}

				if(posO!=seqO[O]){
					if(posO<seqO[O])
						posO++;
					else
						posO--;
				}

			}
		}
		fprintf(fw, "Case #%d: %d\n", T, time);
	}


	fclose(fr);
	fclose(fw);
}