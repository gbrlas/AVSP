#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int r;
char mat[200][200];
char novo[200][200];

bool read(){
	scanf("%d", &r);
	
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			mat[i][j] = 0;
	
	int x1,x2,y1,y2;
	
	for(int i = 0; i < r; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		
		for(int ii = x1; ii <= x2; ii++)
			for(int jj = y1; jj <= y2; jj++)
				mat[ii][jj] = 1;
			
	}

}

bool temVivas(){
	for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++)
				if(mat[i][j] == 1)return true;
	return false;
}

int caso = 1;
void process(){
	int c = 0;
	while(temVivas()){
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++){
				novo[i][j] = mat[i][j];
				if(!(i > 1 && mat[i-1][j] == 1) && !(j > 1 && mat[i][j-1] == 1)){
					novo[i][j] = 0;
				}
				if((i > 1 && mat[i-1][j] == 1) && (j > 1 && mat[i][j-1] == 1)){
					novo[i][j] = 1;
				}
			}
			
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++){
				mat[i][j] = novo[i][j];
			}
		
		c++;
	}
	printf("Case #%d: %d\n", caso++, c);
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
