#include <stdio.h>
#include <string.h>

#define LEN_WELCOME 19
char welcome[LEN_WELCOME + 1] = "welcome to code jam";

int results[2][501];
char line[502];

int dp(){
	int i, j, k, len_line, before, now, num;
	len_line = strlen(line);
	for(j = 0; j < len_line - LEN_WELCOME +1; ++j){		
		results[0][j] = results[1][j] = 0;
		if(line[j] == welcome[0])
			results[0][j] = 1;
	}
	for(;j < len_line; ++j)
		results[0][j] = results[1][j] = 0;
	before = 0;
	now = 1;
	for(i = 1; i < LEN_WELCOME; ++i){
		num = 0;
		for(j = 0; j < len_line - LEN_WELCOME +1 + i; ++j){
			if (line[j] == welcome[i])
				results[now][j] = num;
			else
				results[now][j] = 0;
			num += results[before][j];
			if (num > 10000)
				num = num - 10000;
		}
		for(; j < len_line; ++j)
			results[now][j] = 0;
		before = now;
		now = 1 -now;
	}
	num = 0;
	for(j = LEN_WELCOME -1; j < len_line; ++j)
		num += results[before][j];
	return num % 10000;
}

int main(){
	int N, i;
	scanf("%d", &N);
	gets(line);
	for(i = 1; i <= N; ++i){
		gets(line);
		printf("Case #%d: %04d\n", i, dp());
	}
}