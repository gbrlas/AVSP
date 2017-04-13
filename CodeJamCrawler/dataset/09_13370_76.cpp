#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>

using namespace std;

int H,W;
int mat[120][120];
int rep[120][120];
int nrep;
char mapa[30];
int incX[4] = {-1,0,0,1};
int incY[4] = {0,-1,1,0};


int go(int i, int j){
	int ni, nj, menor = -1, imenor=-1;
	
	if(rep[i][j] != -1){
		return rep[i][j];
	}
	for(int k = 0; k < 4; k++){
		ni = i + incX[k];
		nj = j + incY[k];
		if(ni >= 0 && ni < H && nj >= 0 && nj < W){
			if(mat[ni][nj] < mat[i][j]){
				if(mat[ni][nj] < menor || menor == -1){
					menor = mat[ni][nj];
					imenor = k;
				}
			}
		}
	}
	if(menor == -1){
		rep[i][j] = nrep;
	}else{
		rep[i][j] = go(i+incX[imenor], j + incY[imenor]);
	}
	return rep[i][j];
}

int main(){
	
	freopen("data.in","r", stdin);
	freopen("data.out","w", stdout);
	int casos;
	
	scanf("%d", &casos);
	
	for(int i = 1; i <= casos; i++){
		printf("Case #%d:\n", i);
		
		scanf("%d%d", &H,&W);
		nrep = 0;
		for(int i = 0;  i< H; i++){
			for(int j = 0; j < W; j++){
				scanf("%d", &mat[i][j]);
				rep[i][j] = -1;
			}
		}
		
		for(int i = 0;  i< H; i++){
			for(int j = 0; j < W; j++){
				if(rep[i][j] == -1){
					go(i,j);
					mapa[nrep] = -1;
					nrep++;
				}
			}
		}
		nrep = 0;
		for(int i = 0;  i< H; i++){
			for(int j = 0; j < W; j++){
				if(mapa[rep[i][j]] == -1){
					mapa[rep[i][j]] = 'a'+nrep;
					nrep++;
				}
				if(j > 0)
					printf(" ");
				printf("%c", mapa[rep[i][j]]);
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
