#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>

using namespace std;

int L, D, N;
char word[5010][30];
char str[1000];
bool pode[5010];

int main(){
	
	freopen("data.in","r", stdin);
	freopen("data.out","w", stdout);
	
	scanf("%d%d%d", &L, &D, &N);
	
	for(int i = 0; i < D; i++){
		scanf("%s", word[i]);
	}
	int j, qtd, jj, mask;
	
	
	for(int i = 1; i <= N; i++){
		scanf("%s", str);
		
		j = qtd = 0;
		
		for(int k = 0; k < D; k++)
			pode[k] = true;
		
		for(int k = 0; k < L; k++){
			if(str[j] == '('){
				jj = j+1;
				while(str[jj] != ')')
					jj++;
				j++;
				mask = 0;
				for(int l = j; l < jj; l++){
					mask |= (1 << (str[l]-'a'));
				}
				j = jj+1;
			}else{
				mask = 1 << (str[j]-'a');
				j++;
			}
			for(int l = 0; l < D; l++){
				if((mask&(1 << (word[l][k]-'a'))) == 0){
					pode[l] = false;
				}
			}
		}
		for(int l = 0; l < D; l++){
			if(pode[l]){
				qtd++;
			}
		}
		printf("Case #%d: %d\n", i, qtd);
	}
	
	return 0;
}
