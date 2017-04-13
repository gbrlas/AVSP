#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
//#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;

#define lint __int64
#define ss stringstream
#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=0;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

int WW[1000010];
int XX[1000010];
int Q[1000010];
int V[200][200], QX[100000], QY[100000];

int W, H, x1, x2, y1, y2, sx, sy, qb, qe;
lint ans;

void F() {
	int i,j,qb,qe;
	QX[0] = sx;
	QY[0] = sy;
	qe = 1;
	memset(V,0,sizeof(V));
	V[sx][sy] = 1;
	FOR(qb,qe) {
		if ((QY[qb] + y1 >= 0) && (QY[qb] + y1 < H) && (QX[qb] + x1 >= 0) && (QX[qb] + x1 < W))
			if (V[QX[qb] + x1][QY[qb] + y1] == 0) {
				QX[qe] = QX[qb] + x1;
				QY[qe] = QY[qb] + y1;
				V[QX[qe]][QY[qe]] = 1;
				qe++;
			}
		swap(x1,x2);
		swap(y1,y2);
		if ((QY[qb] + y1 >= 0) && (QY[qb] + y1 < H) && (QX[qb] + x1 >= 0) && (QX[qb] + x1 < W))
			if (V[QX[qb] + x1][QY[qb] + y1] == 0) {
				QX[qe] = QX[qb] + x1;
				QY[qe] = QY[qb] + y1;
				V[QX[qe]][QY[qe]] = 1;
				qe++;
			}
	}
	ans = qe;
}

int main() {
	int t,tt;
	FILE *fp = fopen("B-small.in","r");
	FILE *fp1 = fopen("B-small.out","w");
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d%d%d%d%d%d%d",&W,&H,&x1,&y1,&x2,&y2,&sx,&sy);

ans = 0;
		F();

/*		if (x1*(lint)y2 == x2*(lint)y1) {
			if (y1 == 0) { swap(x1,y1); swap(x2, y2); swap(sx, sy); swap(W, H); }
			memset(WW,0,sizeof(WW));
			WW[sy] = 1;
			XX[sy] = sx;
			qe = 1;
			Q[0] = sy;
			FOR(qb,qe) {
				if ((Q[qb] + y1 >= 0) && (Q[qb] + y1 < H) && (XX[Q[qb]] + x1 >= 0) && (XX[Q[qb]] + x1 < W))
					if (WW[Q[qb] + y1] == 0) {
						WW[Q[qb] + y1] = 1;
						XX[Q[qb] + y1] = XX[Q[qb]] + x1;
						Q[qe] = Q[qb] + y1;
						qe++;
					}
				swap(x1,x2);
				swap(y1,y2);
				if ((Q[qb] + y1 >= 0) && (Q[qb] + y1 < H) && (XX[Q[qb]] + x1 >= 0) && (XX[Q[qb]] + x1 < W))
					if (WW[Q[qb] + y1] == 0) {
						WW[Q[qb] + y1] = 1;
						XX[Q[qb] + y1] = XX[Q[qb]] + x1;
						Q[qe] = Q[qb] + y1;
						qe++;
					}
			}
			ans = qe;
		} else {
			int mx, my;
			while ((sx >= 0) && (sy >= 0) && (sx < W) && (sy < H)) {
				if (x2 == 0) mx = 10000000; else if (x2 > 0) mx = (W-sx-1)/x2; else mx = sx/abs(x2);
				if (y2 == 0) my = 10000000; else if (y2 > 0) my = (H-sy-1)/y2; else my = sy/abs(y2);
				ans += 1+min<int>(mx,my);
				sx += x1;
				sy += y1;
			}
		}
*/
		printf("Case #%d: %I64d\n", t+1, ans);
		fprintf(fp1,"Case #%d: %I64d\n", t+1, ans);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}