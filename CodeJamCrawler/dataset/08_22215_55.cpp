#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

double ans;
double f, R, t, r, g;
double sr;

const double eps = 1e-7;
const double PI = atan(1.0) * 4;

inline double sqr(double x)
{
	return x * x;
}

void init()
{
	scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
}

double getarea(double x1, double y1, double x2, double y2)
{
	return fabs(x1 * y2 - x2 * y1) / 2;
}

double getRa(double x1, double y1, double x2, double y2)
{
	double ang = fabs(atan2(y2, x2) - atan2(y1, x1));
//	cout << ang * sqr(sr) / 2 << endl;
	if (y2>y1)
	{
//		cout << getarea(x2, y2, x2, y1) + getarea(x2, y1, x1, y1) << endl;
		return ang * sqr(sr) / 2 - getarea(x2, y2, x2, y1) - getarea(x2, y1, x1, y1);
	}
	else
	{
//		cout << getarea(x2, y2, x1, y2) + getarea(x1, y2, x1, y1) << endl;
		return ang * sqr(sr) / 2 - getarea(x2, y2, x1, y2) - getarea(x1, y2, x1, y1);
	}
}

double getother(double x)
{
	return sqrt(sqr(sr) - sqr(x));
}

bool intersect(double x0, double y0, double xu, double yu, double &x1, double &y1, double &x2, double &y2)
{
	x1 = x0;
	if (x1>=sr*(1-eps))
		y1 = yu + 1;
	else
		y1 = getother(x1);
	if (y1>yu*(1+eps))
	{
		y1 = yu;
		x1 = getother(y1);
	}
	
	x2 = xu;
	if (x2>=sr*(1-eps))
		y2 = y0 - 1;
	else
		y2 = getother(x2);
	if (y2<y0*(1-eps))
	{
		y2 = y0;
		x2 = getother(y2);
	}
	if (x1<x0*(1-eps) || x1>xu*(1+eps)) return false;
	if (x2<x0*(1-eps) || x2>xu*(1+eps)) return false;
	if (y1<y0*(1-eps) || y1>yu*(1+eps)) return false;
	if (y2<y0*(1-eps) || y2>yu*(1+eps)) return false;
	return true;
}

void process()
{
	if (g <= (2 + eps) * f)
	{
		ans = 1;
		return ;
	}
	sr = R - f - t;
	double w = g + 2 * r;
	double block = sqr(g - 2 * f);
	int x = 0, y = (int)floor(sr / w), ly = y;
	double ts = 0;
	while (y >= 0)
	{
		double x0, y0, xu, yu, x1, y1, x2, y2;
		x0 = x * w+r+f;
		y0 = y * w+r+f;
		xu = (x+1)*w-r-f;
		yu = (y+1)*w-r-f;
		if (intersect(x0, y0, xu, yu, x1, y1, x2, y2))
		{
			//cout << x << ' ' << y << ' ' << x0 << ' ' << y0 << ' ' << xu << ' ' << yu << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << ts << endl;
			ts += (x1-x0)*(yu-y0) + (y2-y0)*(xu-x1);
//			cout << "RA=" << getRa(x1, y1, x2, y2) << endl;
			ts += getRa(x1, y1, x2, y2);
			ly = y;
		}
		intersect(x * w, y * w, (x+1)*w, (y+1)*w, x1, y1, x2, y2);
		//cout << x << ' ' << y << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << ts << endl;
		if (x2>=(x+1)*w*(1-eps))
		{
//			cout << "B" << y << endl;
			ts += block * ly;
			++x;
		}
		else
			--y;
	}
	double area = PI * sqr(R) / 4;
//	cout << ts << ' ' << area << endl;
	ans = 1 - ts / area;
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %0.6lf\n", id, ans);
}

int main()
{
	freopen("c.txt", "rt", stdin);
	freopen("c_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
	return 0;
}
