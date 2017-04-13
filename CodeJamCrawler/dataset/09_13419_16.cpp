#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
char mat[100][100];
int prim[100];

int caso = 1;

bool read(){
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	
	return true;
}

void process(){
	for(int i = 0; i < N; i++){
		int j = N-1;
		while(j >= 0 && mat[i][j] == '0'){
			j--;
		}
		if(j==-1)
			j++;
		prim[i] = j;
	}
	int cost = 0;
	
	for(int i = 0; i < N; i++){
		int j = i;
		
		while(prim[j] > i){
			j++;
		}
		for(int k = j; k > i; k--){
			swap(prim[k], prim[k-1]);
			cost++;
		}
	}
	
	printf("Case #%d: %d\n", caso++, cost);
}

int main(){
	
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int casos;
	
	scanf("%d", &casos);
	
	while(casos-- && read()){
		process();
	}
	return 0;
}
