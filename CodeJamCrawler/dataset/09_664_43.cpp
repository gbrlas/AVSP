#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define ROF(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define PER(i,a) ROF(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))
#define st first
#define nd second
#define LL long long

typedef pair<int,int> PII;

int H,W;
int P[102][102];
char res[102][102];
int ax[]={0,-1,1,0};
int ay[]={-1,0,0,1};
int n;

void fill(int ynow,int xnow) {
	int pnow=P[ynow][xnow];	
	int smallest=1000000;
	
	REP(i,4) {
		int yt=ynow+ay[i];
		int xt=xnow+ax[i];
		if(yt<1||yt>H||xt<1||xt>W) continue;
		smallest=min(smallest,P[yt][xt]);
	}
	
	if(pnow<=smallest) {
		res[ynow][xnow]='a'+n;
		n++;
	} else {
		REP(i,4) {
			int yt=ynow+ay[i];
			int xt=xnow+ax[i];
			if(yt<1||yt>H||xt<1||xt>W) continue;
			if(pnow>P[yt][xt]&&P[yt][xt]==smallest&&res[yt][xt]==' ') fill(yt,xt);
		}
		
		REP(i,4) {
			int yt=ynow+ay[i];
			int xt=xnow+ax[i];
			if(yt<1||yt>H||xt<1||xt>W) continue;
			if(smallest==P[yt][xt]) {
				res[ynow][xnow]=res[yt][xt];
				break;
			}
		}
	}
}

int main (void) {
	int NC; scanf("%d",&NC);
	int TC=1;
	while(NC--) {
		scanf("%d %d",&H,&W);
		FOR(i,1,H) FOR(j,1,W)
			scanf("%d",&P[i][j]);
		
		FOR(i,1,H) FOR(j,1,W) res[i][j]=' ';
		
		n=0;
		FOR(i,1,H) FOR(j,1,W)
			if(res[i][j]==' ')
				fill(i,j);

		printf("Case #%d:\n",TC++);
		FOR(i,1,H) FOR(j,1,W)
			printf("%c%s",res[i][j],(j==W?"\n":" "));
	}
	return 0;
}
