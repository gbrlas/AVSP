#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define CLEAR(a,v) memset((a), (v), sizeof(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
const double eps = 1e-9;
const int INF = 1000000000;
const LL LLINF = (LL)INF * INF;
const double PI = 2 * acos(.0);

const int dir[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
struct SEG {char s[40]; int cnt;} seg[1024];
int xmin[6010], xmax[6010];
int ymin[6010], ymax[6010];
const int DELTA = 3001;

struct Pt {int x, y;} tpt;
vector<Pt> plist;

int main() {
	freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	FILE *fp = fopen("A-large.out","w");
	int T, i, cx, cy, d, n, j, k, ca = 0;
	int tminx, tminy, tmaxx, tmaxy;
	scanf("%d",&T);
	while (T--) {
		plist.clear();
		scanf("%d",&n);
		for (i = 0 ; i < n ; i++) {
			scanf("%s%d",&seg[i].s,&seg[i].cnt);
		}
		for (i = 0 ; i < 6010 ; i++) {
			xmin[i] = ymin[i] = tminx = tminy = INF;
			xmax[i] = ymax[i] = tmaxx = tmaxy = -INF;
		}
		cx = cy = DELTA; d = 0;
		tpt.x = tpt.y = DELTA;
		plist.PB(tpt);
		for (i = 0 ; i < n ; i++) {
			for (j = 0 ; j < seg[i].cnt ; j++) {
				for (k = 0 ; seg[i].s[k] ; k++) {
					if (seg[i].s[k] == 'F') {
						cx += dir[d][0]; cy += dir[d][1];
						//printf("cx:%d cy:%d\n",cx,cy);
						if (d == 0) {
							ymin[cx-1] <?= cy;
							ymax[cx-1] >?= cy;
						} else if (d == 1) {
							xmin[cy-1] <?= cx;
							xmax[cy-1] >?= cx;
						} else if (d == 2) {
							ymin[cx] <?= cy;
							ymax[cx] >?= cy;
						} else {
							xmin[cy] <?= cx;
							xmax[cy] >?= cx;
						}
						tminx <?= cx;
						tmaxx >?= cx;
						tminy <?= cy;
						tmaxy >?= cy;
					}
					else {
						tpt.x = cx; tpt.y = cy;
						plist.PB(tpt);
						if (seg[i].s[k] == 'R') {if (++d == 4) d = 0;}
						else {
							--d;
							if (d < 0) d = 3;
						}
					}
				}
			}
		}
		//printf("minx:%d miny:%d maxx:%d maxy:%d\n",tminx,tminy,tmaxx,tmaxy);
		int cnt = 0;
		for (i = tminx ; i <= tmaxx ; i++)
			for (j = tminy ; j <= tmaxy ; j++)
				if (ymin[i] <= j && ymax[i] > j ||
					xmin[j] <= i && xmax[j] > i) ++cnt;
		//tpt.x = tpt.y = 0;
		plist.PB(plist[0]);
		LL s = 0;
		for (i = 0 , s = 0 ; i < plist.size() - 1 ; i++) {
			//printf("[%d,%d]\n",plist[i].x,plist[i].y);
			s += (LL)plist[i].x * plist[i+1].y - (LL)plist[i+1].x * plist[i].y;
		}
		if (s<0) s = -s;
		//printf("s:%I64d siz:%d cnt:%d\n",s,plist.size(),cnt);
		fprintf(fp, "Case #%d: %I64d\n",++ca,cnt-s/2);
		printf("case %d\n",ca);
	}
	fclose(fp);
	return 0;
}
