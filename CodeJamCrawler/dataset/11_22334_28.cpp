#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int T, N, H, L, f[10001], i, j, k;
	FILE * pf;
	bool pos;
	pf = fopen("out.txt", "w");
	scanf("%i ", &T);
	for(int _=1; _<=T; _++){
		scanf("%i %i %i ", &N, &L, &H);
		for(i=0;i<N;i++){
			scanf("%i", &f[i]);
		}
		for(i=L;i<=H;i++){
			pos=true;
			for(j=0;j<N;j++){
				if(f[j]%i != 0 && i%f[j] != 0){
					pos=false;
					break;
				}
			}
			if(pos){
				break;
			}
		}
		if(pos){
			fprintf(pf,"Case #%i: %i\n",_,i);
			printf("Case #%i: %i\n",_,i);
		}
		else{
			fprintf(pf,"Case #%i: NO\n",_);
			printf("Case #%i: NO\n",_);
		}
	}
	fclose(pf);
	return 0;
}
