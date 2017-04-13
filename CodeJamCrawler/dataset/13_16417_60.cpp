#include <cstdio>

const int N = 10;

char t[N][N];

void output(int nr, const char* s){
	printf("Case #%d: %s\n", nr, s);
}

bool test(char w){
	for(int i=1; i<=4; i++){
		bool ok=true;
		for(int x=1; x<=4; x++){
			if(t[i][x]!='T' && t[i][x]!=w) ok = false;
		}
		if(ok) return true;
	}
	for(int i=1; i<=4; i++){
		bool ok=true;
		for(int x=1; x<=4; x++){
			if(t[x][i]!='T' && t[x][i]!=w) ok = false;
		}
		if(ok) return true;
	}

	{
		bool ok=true;
		for(int x=1; x<=4; x++){
			if(t[x][x]!='T' && t[x][x]!=w) ok = false;
		}
		if(ok) return true;
	}
	{
		bool ok=true;
		for(int x=1; x<=4; x++){
			if(t[5-x][x]!='T' && t[5-x][x]!=w) ok = false;
		}
		if(ok) return true;
	}

	return false;

}

bool empty(){
	for(int i=1; i<=4; i++) for(int j=1; j<=4; j++) if(t[i][j] == '.') return true;
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int x=1; x<=4; x++) scanf("%s", t[x]+1);
		if(test('O')) output(i, "O won");
		else if(test('X')) output(i, "X won");
		else if(empty()) output(i, "Game has not completed");
		else output(i, "Draw");
	}
}
