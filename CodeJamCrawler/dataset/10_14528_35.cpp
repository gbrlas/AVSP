#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int diamond[1000][1000];
int grande[2000][2000];
int mat[1000][1000];
int k;

void read(){
	scanf("%d", &k);
	int jj = k;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < i; j++){
			scanf("%d", &diamond[i][jj+2*j]);
		}
		jj--;
	}
	jj+=2;
	for(int i = k-1; i >= 1; i--){
		for(int j = 0; j < i; j++){
			scanf("%d", &diamond[2*k-i][jj+2*j]);
		}
		jj++;
	}
}


bool simetrico(int i, int j, int K){
	if(grande[j][i] != -1 && grande[j][i] != grande[i][j])return false;
	if(grande[K-j+1][K-i+1] != -1 && grande[K-j+1][K-i+1] != grande[i][j])return false;
	
	return true;
}

bool can(int K){
	
	for(int i = 1; i <= K; i++)
		for(int j = 1; j <= K; j++){
			grande[i][j] = -1;
		}
	
	for(int i = 1; i + k-1 <= K; i++){
		for(int j = 1; j +k-1 <= K; j++){
			
			bool pode = true;
			
			for(int ii= 1; ii <= k; ii++)
				for(int jj = 1; jj <= k; jj++){
					
					grande[i+ii-1][j+jj-1] = mat[ii][jj];
					
				}
			
			/*for(int ii= 1; ii <= K; ii++){
				for(int jj = 1; jj <= K; jj++){
					
					printf("%d ", grande[ii][jj]);
					
				}
				printf("\n");
			}
			printf("\n");*/
			
			for(int ii= 1; ii <= k; ii++)
				for(int jj = 1; jj <= k; jj++){
					if(!simetrico(i+ii-1, j+jj-1, K)){
						//printf("off %d %d\n", i+ii-1, j+jj-1);
						pode = false;
					}
				}
			
			
			
			if(pode)return true;
			
			
			for(int ii= 1; ii <= k; ii++)
				for(int jj = 1; jj <= k; jj++){
					
					grande[i+ii-1][j+jj-1] = -1;
					
				}
		}
	}
	
	return false;
}

int tot(int K){
	return K*K;
}

int caso = 1;
void process(){
	int jj = k;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < k; j++){
			mat[i][1+j] = diamond[i+j][jj+j];
		}
		jj--;
	}

	for(int K = k; K <= 5*k; K++){
		if(can(K)){
			printf("Case #%d: %d\n", caso++, tot(K)-tot(k));
			return;
		}
	}
}

int main(){
	int casos;
	
	scanf("%d", &casos);
	
	while(casos--){
		read();
		process();
	}
	
	return 0;
}
