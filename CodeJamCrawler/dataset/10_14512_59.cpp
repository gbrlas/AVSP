 #include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int N;
char mat2[100][100], mat[100][100];
int K;

bool read(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%s", mat2[i]);
	return true;
}
int cont[200][200];

bool ganha(char color){

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(j > 0 && mat[i][j] == color){
				cont[i][j] = cont[i][j-1]+1;
				if(cont[i][j] >= K)
					return true;
			}else if(mat[i][j] == color)
				cont[i][j] = 1;
			else
				cont[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i > 0 && mat[i][j] == color){
				cont[i][j] = cont[i-1][j]+1;
				if(cont[i][j] >= K)
					return true;
			}else if(mat[i][j] == color)
				cont[i][j] = 1;
			else
				cont[i][j] = 0;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i > 0 && j > 0 && mat[i][j] == color){
				cont[i][j] = cont[i-1][j-1]+1;
				if(cont[i][j] >= K)
					return true;
			}else if(mat[i][j] == color)
				cont[i][j] = 1;
			else
				cont[i][j] = 0;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i > 0 && j < N-1 && mat[i][j] == color){
				cont[i][j] = cont[i-1][j+1]+1;
				if(cont[i][j] >= K)
					return true;
			}else if(mat[i][j] == color)
				cont[i][j] = 1;
			else
				cont[i][j] = 0;
		}
	}
	return false;
}

void process(){
	
	for(int i = 0; i <N; i++)
		for(int j = 0; j < N; j++){
			mat[j][N-i-1] = mat2[i][j]; 
		}
	
	for(int j = 0; j < N; j++){
		
		for(int i = N-1; i >= 0; i--){
			if(mat[i][j] == '.'){
				for(int k = i-1; k >= 0; k--){
					if(mat[k][j] != '.'){
						mat[i][j] = mat[k][j];
						mat[k][j] = '.';
						break;
					}
				}
			}
		}
	}
	
	bool b1 = ganha('B');
	bool b2 = ganha('R');
	
	if(b1 && b2){
		printf("Both\n");
	}else if(!b1 && !b2){
		printf("Neither\n");
	}else if(b1)
		printf("Blue\n");
	else
		printf("Red\n");
}

int main(){
	
	int casos;
	int i = 1;
	scanf("%d", &casos);
	
	while(casos-- && read()){
		printf("Case #%d: ", i++);
		process();
	}
	
	return 0;
}
