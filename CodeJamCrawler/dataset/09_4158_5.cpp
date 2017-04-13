#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0, _n = n; i < _n; ++i)
#define REP(i, a, b) for (int i = a, _n = b; i < _n; ++i)

struct Circle{
	double x, y, r;

	double dist(double xx, double yy) const
	{
		double dx = xx - x;
		double dy = yy - y;
		return r + sqrt(dx * dx + dy * dy);
	};
};


double Dist(double x, double y, const vector<Circle>& vs)
{
	double r = 0, r1;
	rep(i, vs.size()){
		r1= vs[i].dist(x, y);
		if (r1 > r) r = r1;
	}

	return r;
}

double bestX(double y, const vector<Circle>& vs, double& x)
{
	double xMin = 0, xMax = 1000, m1, m2;
	
	rep(i, 100)
	{
		m1 =( 2 * xMin + xMax) / 3.0;
		m2 =( xMin + 2 * xMax) / 3.0;
		if (Dist(m1, y, vs) < Dist(m2, y, vs))
			xMax = m2;
		else
			xMin = m1;
	}
	x = xMin;

	return Dist(m1, y, vs);
}

Circle bestCircle(const vector<Circle>& vs)
{
	double yMin = 0, yMax = 1000, m1, m2, x;

	rep(i, 100)
	{
		m1 =( 2 * yMin + yMax) / 3.0;
		m2 =( yMin + 2 * yMax) / 3.0;
		if (bestX(m1, vs, x) < bestX(m2, vs, x))
			yMax = m2;
		else
			yMin = m1;
	}

	Circle c;
	c.r = bestX(m1, vs, x);
	c.x = x;
	c.y = yMin;
	return c;
}

double eps = 1E-5;
Circle c[100];

double rCompute(Circle fc, int n)
{
	vector<Circle> vs;
	rep(i, n){
		if (c[i].dist(fc.x, fc.y) > fc.r + eps)
			vs.push_back(c[i]);
	}

	if (vs.empty())
		return fc.r;

	double r = fc.r;
	Circle c = bestCircle(vs);
	if (c.r > r) r = c.r;
	return r;
}

//Circle pC[64000];

int main()
{
	ifstream cin("D-small-attempt0.in");
	ofstream cout("D-small-attempt0.out");

	int tc; cin >> tc;
	rep(t, tc)
	{
		int n;
		cin >> n;
		rep(i, n) cin >> c[i].x >> c[i].y >> c[i].r;


		double r = 1E10, r1;
		// single
		rep(i, n)
		{
			r1 = rCompute(c[i], n);
			if (r1 < r) r = r1;
		}
		vector<Circle> v2(2);
		Circle cc;
		rep(i, n) for (int j = i + 1; j < n; ++j)
		{
			v2[0] = c[i]; v2[1] = c[j];
			cc = bestCircle(v2);
			if (cc.r >= r) continue;

			r1 = rCompute(cc, n);
			if (r1 < r) r = r1;			
		}

		vector<Circle> v3(3);
		rep(i, n) for (int j = i + 1; j < n; ++j) for (int k = j + 1; k < n; ++k)
		{
			v3[0] = c[i]; v3[1] = c[j]; v3[2] = c[k];
			cc = bestCircle(v3);
			if (cc.r >= r) continue;
			r1 = rCompute(cc, n);
			if (r1 < r) r = r1;
		}
		cout.precision(6); 
		cout << std::fixed << std::showpoint;
		cout << "Case #"<< (t + 1) <<": " << r << '\n';
	}

	return 0;
}