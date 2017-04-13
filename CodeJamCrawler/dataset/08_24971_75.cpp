#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double PI = 2 * acos(.0);
double f,R,r,t,g;
double nr, ng, nR;

inline int sig(double k) {
	if (k<-eps) return -1;
	return k>eps;
}

inline int check_in(double x, double y) {
	return sig(x*x+y*y-nR*nR) <= 0;
}

inline void calc_inter(double x1, double y1, double x2, double y2, double &cx, double &cy) {
	if (sig(x1-x2) == 0) {
		cx = x1;
		cy = sqrt(nR*nR-cx*cx);
		assert((cy>=y1 && cy <= y2) || (cy>=y2 && cy<=y1));
	} else {
		cy = y1;
		cx = sqrt(nR*nR-cy*cy);
		assert((cx>=x1 && cx <= x2) || (cx>=x2 && cx<=x1));
	}
}

inline double calc_gong(double x1, double y1, double x2, double y2) {
	double t1 = atan2(x1, y1);
	if (t1 < 0) t1 += PI * 2;
	double t2 = atan2(x2, y2);
	if (t2 < 0) t2 += PI * 2;
	double a = fabs(t1 - t2);
	while (a > PI * 2) a -= PI * 2;
	if (a > PI) a = 2 * PI - a;
	return a * nR * nR / 2 - nR * nR * sin(a) / 2;
}

int main() {
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int T, ca = 0;
	double x, y, tot, cx1, cy1, cx2, cy2;
	scanf("%d",&T);
	while (T--) {
		scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
		printf("Case #%d: ",++ca);
		ng = g - 2 * f;
		nr = r + f;
		nR = R - t - f;
		if (sig(ng) <= 0) {
			printf("1.000000\n");
			continue;
		}
		tot = .0;
		for (x = r + f ; sig(x - nR) <= 0 ; x += g + r + r) {
			for (y = r + f ; ; y += g + r + r) {
				if (check_in(x,y) == 0) break;
				if (check_in(x+ng, y+ng)) {
					tot += ng * ng;
				} else if (check_in(x+ng,y) && check_in(x,y+ng)) {
					calc_inter(x+ng,y,x+ng,y+ng,cx1,cy1);
					calc_inter(x,y+ng,x+ng,y+ng,cx2,cy2);
					double tmp = ng * ng - (y+ng-cy1)*(x+ng-cx2)/2;
					tot += tmp + calc_gong(cx1,cy1,cx2,cy2);
				} else if (check_in(x+ng, y) && !check_in(x,y+ng)) {
					calc_inter(x+ng,y,x+ng,y+ng,cx1,cy1);
					calc_inter(x,y,x,y+ng,cx2,cy2);
					tot += ((cy1-y)+(cy2-y))*ng/2 + calc_gong(cx1,cy1,cx2,cy2);
				} else if (!check_in(x+ng, y) && check_in(x,y+ng)) {
					calc_inter(x,y,x+ng,y,cx1,cy1);
					calc_inter(x,y+ng,x+ng,y+ng,cx2,cy2);
					tot += ((cx1-x)+(cx2-x))*ng/2 + calc_gong(cx1,cy1,cx2,cy2);
				} else {
					calc_inter(x,y,x+ng,y,cx1,cy1);
					calc_inter(x,y,x,y+ng,cx2,cy2);
					tot += (cx1-x) * (cy2-y) / 2 + calc_gong(cx1, cy1, cx2, cy2);
				}
			}
		}
		//printf("ans:%.6lf tot:%.6lf\n",tot,PI*R*R);
		printf("%.6lf\n",1-tot*4/(PI*R*R));
	}
	return 0;
}
