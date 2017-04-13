#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


double const pi = 3.141592653589793;


// indef. integral of sqrt(R^2 - x^2) dx

double Integrate(double x, double R)
{
	double y = sqrt(R*R - x*x);
	return 0.5 * (x * y + R * R * atan2(x, y));
}


// integral from x1 to x2 of (sqrt(R^2 - x^2) - y0) dx

double Integrate(double x1, double x2, double y0, double R)
{
	return Integrate(x2, R) - Integrate(x1, R) - (x2 - x1) * y0;
}


double Solve(double Rt, double r, double g)
{
	double square_size = g + 2 * r;
	double x1 = r, x2 = r + g;
	double result = 0;
	while (x1 < Rt) {
		if (x2 > Rt)
			x2 = Rt;
		double circmax = sqrt(Rt*Rt - x1*x1);
		double circmin = sqrt(Rt*Rt - x2*x2);
		int complete_squares = int((circmin + r) / square_size);
		result += complete_squares * (g * g);
		for (int y = complete_squares; ; ++y) {
			double ylo = y * square_size + r;
			double yhi = ylo + g;
			if (ylo >= circmax) break;
			if (yhi >= circmax)
				yhi = circmax;
			double loint = sqrt(Rt*Rt - ylo*ylo);
			double hiint = sqrt(Rt*Rt - yhi*yhi);
			result += (yhi - ylo) * (hiint - x1) + Integrate(hiint, min(loint, x2), ylo, Rt);
		}
		x1 += square_size;
		x2 += square_size;
	}
	return result;
}


double Case()
{
	double f, R, t, r, g;
	cin >> f >> R >> t >> r >> g;
	t += f;
	r += f;
	g -= 2 * f;
	if (t >= R || g <= 0)
		return 1.0;
	double area = 0.25 * pi * R * R;
	return 1.0 - Solve(R - t, r, g) / area;
}


int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		printf("Case #%d: %.6f\n", i, Case());
	}
}
