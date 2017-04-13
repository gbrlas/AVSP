#include <cstdio>

char M[10][10];
char s[10];

int calc( char c ){
	for (int i=0; i<4; ++i){
		int f=1;
		for (int j=0; j<4; ++j)
			if (M[i][j]!=c && M[i][j]!='T'){
				f=0; break;
			}
		if (f) return 1;
		f=1;
		for (int j=0; j<4; ++j)
			if (M[j][i]!=c && M[j][i]!='T'){
				f=0; break;
			}
		if (f) return 1;
	}
	int f=1;
	for (int j=0; j<4; ++j)
		if (M[j][j]!=c && M[j][j]!='T'){
			f=0; break;
		}
	if (f) return 1;
	f=1;
	for (int j=0; j<4; ++j)
		if (M[3-j][j]!=c && M[3-j][j]!='T'){
			f=0; break;
		}
	if (f) return 1;
	return 0;
}

int checkfinish(){
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (M[i][j]=='.') return 0;
	return 1;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		for (int i=0; i<4; ++i)
			scanf("%s", &M[i]);
		int xwon = calc('X');
		int owin = calc('O');
		int finish = checkfinish();
		printf("Case #%d: ", T);
		if (xwon)
			printf("X won\n");
		else
			if (owin)
				printf("O won\n");
			else
				if (finish)
					printf("Draw\n");
				else
					printf("Game has not completed\n");
	}
}
