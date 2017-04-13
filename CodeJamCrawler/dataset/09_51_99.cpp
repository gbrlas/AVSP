#include <stdio.h>
#include <string.h>

char dict[5001][16] = {0};
char pattern[5001] = {0};
int L, D, N;

int get_num(char* pattern){
	int i, len, j, num = 0, pos = 0;
	short de[16][30] = {0};
	len = strlen(pattern);
	for( i = 0; i < len; ++i){
		if (pattern[i] != '(')
			de[pos][pattern[i] - 'a'] = 1;
		else {
			for(++i; pattern[i] != ')'; ++i)
				de[pos][pattern[i] - 'a'] = 1;
		}
		++pos;
	}
	num = 0;
	for(i = 0; i < D; ++i){
		for(j = 0; j < L; ++j){
			if (!de[j][dict[i][j] - 'a'])
				break;
		}
		if (j == L)
			++num;
	}
	return num;
}

int main(){
	int i;
	scanf("%d%d%d", &L, &D, &N);
	for(i = 0; i < D; ++i)
		scanf("%s", dict[i]);
	for(i = 1; i <= N; ++i){
		scanf("%s", pattern);
		printf("Case #%d: %d\n", i, get_num(pattern));
	}
}

