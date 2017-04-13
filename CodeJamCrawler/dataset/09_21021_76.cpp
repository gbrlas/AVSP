#include <algorithm> 
#include <numeric>
#include <cmath> 

#include <string> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 
#include <ctime> 

using namespace std;
#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (int i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector < PI > VP;

int tt,n,m;
int c[110][110];
char w[110][110];
PI q[110][110];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int nn;

bool can(int x, int y){
	return (x>=0&&x<n&&y>=0&&y<m);
}

bool qq( int a, int b, int mx){
	return (can(a,b)&&mx>c[a][b]);
}

PI go(int x, int y){
	int xx=x;
	int yy=y;
	int mx=c[x][y];

	Rep(k,4) 
		if(qq(x+dx[k],y+dy[k],mx)){
			xx=x+dx[k];
			yy=y+dy[k];
			mx=c[xx][yy];

		}
	if(x!=xx||y!=yy)
		q[x][y]=go(xx,yy);
	else q[x][y]=make_pair(xx,yy);

	return q[x][y];
}

void fill(int x, int y){
	Rep(i,n) Rep(j,m) 
		if(q[i][j]==q[x][y])
			w[i][j]=w[x][y];
}



int main(){
	freopen("in.in","rt",stdin);
	freopen("small.txt","wt",stdout);



	scanf("%d\n",&tt);

	For(t,1,tt){
		scanf("%d %d",&n,&m);
		Rep(i,n) Rep(j,m) scanf("%d",&c[i][j]);
		Rep(i,n) Rep(j,m) go(i,j);
		Fill(w,0);
		nn=0;
		Rep(i,n) Rep(j,m) 
			if(w[i][j]==0){
				w[i][j]='a'+nn;
				fill(i,j);
				nn++;
			}
		printf("Case #%d:\n",t);
		Rep(i,n){
			Rep(j,m) printf("%c ",w[i][j]);
			printf("\n");
		}
	}




	return 0;
}
