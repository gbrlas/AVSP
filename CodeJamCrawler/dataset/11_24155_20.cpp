#include <stdio.h>
#include <math.h>

int main(){

	FILE *fr, *fw;
	int cases, T=0, N, owpCount, oowpCount;
	char table[100][100];
	float wins[100], games[100], WP[100], tempWP[100], RPI[100], OWP[100], OOWP[100];

	fr = fopen("A-small-attempt0.in", "r");
	fw = fopen("A-small-attempt0.out", "w");

	fscanf(fr, "%d\n", &cases);

	while(T<cases){
		T++;
		fscanf(fr, "%d\n", &N);

		fprintf(fw, "Case #%d:\n", T);

		for(int i=0; i<N; i++){
			wins[i]=0;
			games[i]=0;
			for(int j=0; j<N; j++){
				if(j==N-1)
					fscanf(fr, "%c\n", &table[i][j]);
				else
					fscanf(fr, "%c", &table[i][j]);
				if(table[i][j] == '1'){
					wins[i]++;
					games[i]++;
				}
				else if(table[i][j]=='0')
					games[i]++;


			}
			WP[i] = wins[i]/games[i];
		}

		for(int i=0; i<N; i++){
			OWP[i]=0;
			owpCount=0;

			for(int j=0; j<N; j++){
				if(j!=i && table[i][j]!='.'){
					if(WP[j]==0)
						tempWP[j] = 0;
					else{
						if(table[i][j]=='1')
							tempWP[j] = ((WP[j]*games[j]) - 0)/(games[j]-1);
						else
							tempWP[j] = ((WP[j]*games[j]) - 1)/(games[j]-1);
					}
					OWP[i]+=tempWP[j];
					owpCount++;
				}
			}
			OWP[i] = OWP[i]/owpCount;
		}

		for(int i=0; i<N; i++){
			OOWP[i]=0;
			oowpCount=0;
			for(int j=0; j<N; j++){
				if(j!=i && table[i][j]!='.'){
					OOWP[i]+=OWP[j];
					oowpCount++;
				}
			}
			OOWP[i] = OOWP[i]/oowpCount;
		}

		for(int i=0; i<N; i++){
			RPI[i] = 0.25*WP[i] + 0.5*OWP[i] + 0.25*OOWP[i];
			fprintf(fw, "%f\n", RPI[i]);
		}
		
		//fprintf(fw, "Case #%d: %s\n", T, winner);
	}


	fclose(fr);
	fclose(fw);
}