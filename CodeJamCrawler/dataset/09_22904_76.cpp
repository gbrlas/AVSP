#include <cstdio>
#include <algorithm>
using std::min;

const int MAX=102;
const int INF=1000000;

int tab[MAX][MAX];
int num[MAX][MAX];
char bas[MAX][MAX];

char check(int x,int y,bool mn=false) {
	static char c('a');
	if(mn) c='a'-1;
	if(bas[x][y]) return bas[x][y];
	else if(num[x][y]==0) {
		bas[x][y]=c;
		++c;
	}
	else if(num[x][y]==1)
		bas[x][y]=check(x-1,y);
	else if(num[x][y]==2)
		bas[x][y]=check(x,y-1);
	else if(num[x][y]==3)
		bas[x][y]=check(x,y+1);
	else if(num[x][y]==4)
		bas[x][y]=check(x+1,y);
	return bas[x][y];
}

int main() {
	int n;
	scanf("%d",&n);
	for(int ii=0;ii<n;++ii) {
		for(int i=0;i<MAX;++i) for(int j=0;j<MAX;++j)
			tab[i][j]=num[i][j]=bas[i][j]=0;
		int h,w;
		scanf("%d%d",&h,&w);
		for(int i=1;i<=h;++i) for(int j=1;j<=w;++j)
			scanf("%d",tab[i]+j);
		for(int i=0;i<=h+1;++i) tab[i][0]=tab[i][w+1]=INF;
		for(int j=0;j<=w+1;++j) tab[0][j]=tab[h+1][j]=INF;
		for(int i=1;i<=h;++i) for(int j=1;j<=w;++j) {
			int k=min(min(tab[i-1][j],tab[i+1][j]),min(tab[i][j-1],tab[i][j+1]));
			if(k>=tab[i][j]) num[i][j]=0;
			else if(k==tab[i-1][j]) num[i][j]=1;
			else if(k==tab[i][j-1]) num[i][j]=2;
			else if(k==tab[i][j+1]) num[i][j]=3;
			else if(k==tab[i+1][j]) num[i][j]=4;
			else puts("SHOOT");
		}
		check(0,0,true);
		for(int i=1;i<=h;++i) for(int j=1;j<=w;++j)
			check(i,j);
		printf("Case #%d:\n",ii+1);
		for(int i=1;i<=h;++i) {
			for(int j=1;j<=w;++j)
				printf("%c ",bas[i][j]);
			puts("");
		}
	}
	return 0;
}

