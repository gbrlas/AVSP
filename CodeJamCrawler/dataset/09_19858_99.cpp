#include <cstdio>
#define REP(i,n) for(int i = 0;i<n;i++)

using namespace std;

int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
int tab[200][200];
char s[200][200];
int h, w;
char last;

char f(int x, int y) {
	if(s[y][x]!=0)
		return s[y][x];
	int c=-1, v=tab[y][x];
	REP(i,4) if(x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h) if(tab[y+dy[i]][x+dx[i]]<v) {c=i; v=tab[y+dy[i]][x+dx[i]];}
	if(c==-1) {s[y][x]=last; last++;}
	else s[y][x]=f(x+dx[c],y+dy[c]);
	return s[y][x];
}

int main() {
	int T;
	scanf("%d", &T);
	REP(z,T) {
		scanf("%d %d", &h, &w);
		REP(i,h) REP(j,w) scanf("%d", &tab[i][j]);
		last='a';
		REP(i,h) REP(j,w) s[i][j]=0;
		REP(i,h) REP(j,w) if(s[i][j]==0) f(j,i);
		printf("Case #%d:\n", z+1);
		REP(i,h) {
			REP(j,w) printf("%c ", s[i][j]);
			printf("\n");
		}
	}
	return 0;
}
