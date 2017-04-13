#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int P;
int M[1 << 11];
int pd[1 << 12][12];
int price[12][1 << 12];
int val[1 << 12];
int minimo[1 << 12];
bool folha[1 << 12];

bool read(){
	scanf("%d", &P);
	
	for(int i = 0; i < (1 << P); i++){
		scanf("%d", &M[i]);
	}
	
	for(int i = P-1; i >= 0; i--){
		for(int j = 0; j < (1 << i); j++){
			scanf("%d", &price[i][j]);
		}
	}

}

int go(int no, int faltas){
	int  custo;
	if(pd[no][faltas] != -1)return pd[no][faltas];
	
	pd[no][faltas] = 1000000000;
	
	if(folha[no]==false){
		custo = go(2*no,faltas) + go(2*no+1,faltas);
		if(custo > 1000000000)
			custo = 1000000000;
	}else{
		custo = 0;
	}
	pd[no][faltas] = min(pd[no][faltas], val[no] + custo);
	
	if(minimo[no] >= faltas+1){
		if(folha[no]==false){
			custo = go(2*no,faltas+1) + go(2*no+1,faltas+1);
			if(custo > 1000000000)
				custo = 1000000000;
		}else{
			custo = 0;
		}
		pd[no][faltas] = min(pd[no][faltas], custo);
	}
	
	return pd[no][faltas];
}

void calc(int no, int left, int right, int linha, int coluna){
	val[no] = price[linha][coluna];
	if(right == left+1){
		minimo[no] = min(M[left],M[right]);
		folha[no] = true;
	}else{
		folha[no] = false;
		calc(2*no,left,(left+right)/2, linha+1,2*coluna);
		calc(2*no+1,(left+right)/2 + 1,right, linha+1,2*coluna+1);
		minimo[no] = min(minimo[2*no],minimo[2*no+1]);
	}
	//printf("no %d => min %d, val %d\n", no, minimo[no], val[no]);
}

int caso = 1;
void process(){
	memset(pd,-1,sizeof(pd));
	
	calc(1, 0, (1 << P)-1, 0, 0);
	
	printf("Case #%d: %d\n", caso++, go(1,0));
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
