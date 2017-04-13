#include <cstdio>
#include <cstring>

int main(){
	unsigned short T, C, D, N, i,m,j;
	char combine[256][256], flags[256];
	char in[101], out[101], a,b,c;
	char oppose[256][256];
	bool comb, change;
	FILE *pf;

	pf = fopen("open.txt", "w");
	scanf("%hu ", &T);
	for(int z=1; z<=T; z++){
		memset(combine, 0, sizeof(combine));
		memset(oppose, false, sizeof(oppose));
		memset(out, 0, sizeof(out));
		memset(flags, 0, sizeof(flags));

		scanf("%hu ", &C);
		while(C>0){
			scanf("%c%c%c ", &a, &b, &c);
			combine[a][b] = c;
			combine[b][a] = c;
			C--;
		}
		scanf("%hu ", &D);
		while(D>0){
			scanf("%c%c ", &a, &b);
			oppose[a][b] = true;
			oppose[b][a] = true;
			flags[a] = true;
			flags[b] = true;
			D--;
		}
		scanf("%hu ", &N);
		scanf("%s", in);
		for(i=0, m=0; i<N; i++){
			if(i-1>=0 && combine[in[i]][in[i-1]]){
				out[i-1]=combine[in[i]][in[i-1]];
				in[i-1] = in[i] = out[i-1];
			}
			else if(flags[in[i]]){
				change = false;
				for(j=m;j<i;j++){
					if(oppose[in[i]][in[j]]){
						if(combine[in[j]][in[j-1]] == 0){
							m=i+1;
							in[i] = ' ';
							change = true;
							memset(out, 0, sizeof(out));
							break;
						}
					}
				}
				if(!change)
					out[i]=in[i];
			}
			else
				out[i]=in[i];
		}
		if(i+1==N){
			out[N-1]=in[N-1];
		}
		fprintf(pf, "Case #%i: [", z);
		comb = true;
		for(i=0; i<N; i++){
			if(out[i] != 0){
				if(comb){
					fprintf(pf, "%c", out[i]);
					comb = false;
				}
				else
					fprintf(pf, ", %c", out[i]);
			}
		}
		fprintf(pf, "]\n");
	}
	fclose(pf);
	return 0;
}