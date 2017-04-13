#include <iostream>

using namespace std;

double xx, yy, zz;
int vx, vy, vz;

const double eps = 1e-10;

double dist(double t)
{
	return sqrt((xx + vx * t)*(xx + vx * t) + (yy + vy * t)*(yy + vy * t) + (zz + vz * t)*(zz + vz * t));
}

int main()
{
	freopen("b.in", "rt", stdin);
	freopen("b.out", "wt", stdout);
	int t;
	cin >> t;
	cout.precision(12);
	for (int T = 1; T <= t; ++T)
	{
		int n;
		cin >> n;
		int x = 0, y = 0, z = 0;
		vx = 0, vy = 0, vz = 0;
		for (int i = 0; i < n; ++i)
		{
			int xx, yy, zz, vxx, vyy, vzz;
			cin >> xx >> yy >> zz >> vxx >> vyy >> vzz;
			vx += vxx;
			vy += vyy;
			vz += vzz;
			x += xx;
			y += yy;
			z += zz;
		}
		cout << "Case #" << T << ": ";
		xx = 1.0*x/n;
		yy = 1.0*y/n;
		zz = 1.0*z/n;
		if (vx == 0 && vy == 0 && vz == 0)
		{
			cout << dist(0) << ' ' << 0 << '\n';
			continue;
		}
		double l = 0;
		double r = 1e10;
		double ans = 1e20;
		while (r - l > eps)
		{
			double x1 = (2*l + r)/3;
			double x2 = (l + 2*r)/3;
			double a1 = dist(x1);
			double a2 = dist(x2);
			if (a1 < a2)
				r = x2;
			else
				l = x1;
		}
		cout << dist(l) << ' ' << l*n << '\n';
	}
	return 0;
}
