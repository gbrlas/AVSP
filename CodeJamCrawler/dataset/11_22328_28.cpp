#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int T, R, C,i,j;
	bool pos;
	char map[50][50];
	FILE * pf;
	pf = fopen("out.txt", "w");
	scanf("%i ", &T);
	for(int _=1; _<=T; _++){
		scanf("%i %i ", &R, &C);
		for(i=0;i<R;i++)
			cin >> map[i];
		pos=true;
		for(i=0;i<R && pos;i++){
			for(j=0;j<C;j++){
				if(map[i][j] == '#'){
					if(i+1<R && j+1<C && map[i+1][j] == '#' && map[i][j+1] == '#' && map[i+1][j+1] == '#'){
						map[i][j] = map[i+1][j+1] = '/';
						map[i+1][j] = map[i][j+1] = '\\';
					}
					else{
						pos = false;
						break;
					}
				}
			}
		}
		fprintf(pf, "Case #%i:\n",_);
		printf("Case #%i:\n",_);
		if(!pos){
			fprintf(pf, "Impossible\n");
			printf("Impossible\n");
		}
		else{
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					fprintf(pf, "%c",map[i][j]);
					printf("%c",map[i][j]);
				}
				fprintf(pf, "\n");
				printf("\n");
			}
		}
	}
	fclose(pf);
	return 0;
}
