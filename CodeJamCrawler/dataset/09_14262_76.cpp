#include <stdio.h>
#include <string.h>

char words[5001][16];
int L, D;

char pattern[4096];
char validMap[15][128];

int main(){
    int N;
    int cc;

    scanf(" %d%d%d", &L, &D, &N);

    int i, j;
    for(i = 0; i < D; ++i)
	scanf(" %s", words[i]);

    for(cc = 1; cc <= N; ++cc){
	scanf(" %s", pattern);
	memset(validMap, 0, sizeof(validMap));

	j = 0;
	for(i = 0; pattern[i] && j < L; ++i, ++j){
	    if(pattern[i] != '(')
		validMap[j][(int) pattern[i]] = 1;
	    else
		while(pattern[++i] != ')')
		    validMap[j][(int) pattern[i]] = 1;
	}

	int count = 0;
	for(i = 0; i < D; ++i){
	    int ok = 1;
	    for(j = 0; j < L; ++j)
		if(!validMap[j][(int) words[i][j]]){
		    ok = 0;
		    break;
		}
	    if(ok)
		++count;
	}
	printf("Case #%d: %d\n", cc, count);
    }
    return 0;
}
