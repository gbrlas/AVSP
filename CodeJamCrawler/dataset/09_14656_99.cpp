#include <stdio.h>
#include <string.h>
#define MAXLINELENGTH 500

int main()
{
	const char pattern[] = "welcome to code jam";
	int N = strlen(pattern);

	int table[2][N+1];
	int T, ncase, i;
	int *prev, *now, *tmp;
	char c;

	scanf("%d ", &T);
	for(ncase=0; ncase<T; ++ncase){
		for(i=1; i<=N; ++i)
			table[0][i] = table[1][i] = 0; 
		table[0][0] = table[1][0] = 1; 

		prev = table[0];
		now = table[1];
		while(scanf("%c", &c) != EOF && c != '\n'){
			for(i=0; i<N; ++i){
				now[i+1] = prev[i+1];
				if(c == pattern[i]){
					now[i+1] = (now[i+1] + prev[i]) % 10000;
					//fprintf(stderr, "%c: %d\n", c, now[i+1]);
				}
			}
			tmp = prev;
			prev = now;
			now = tmp;
		}
		printf("Case #%d: %04d\n", ncase+1, prev[N]);
	}
	return 0;
}
