#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>

#define dprintf DEBUG && printf

using namespace std;

const double EPS = 1e-7, PI = 2.0 * acos(0.0);

typedef complex<double> Point;
bool DEBUG = false;

inline Point rotateBy(const Point & vect, double rad) {	return vect * Point(cos(rad), sin(rad)); }
inline bool equal(const Point & a, const Point & b) { return fabs(a.real() - b.real()) < EPS && fabs(a.imag() - b.imag()) < EPS; }
inline int dblcmp(double x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }
inline double cross(const Point & a, const Point & b) { return a.real() * b.imag() - a.imag() * b.real(); }
inline bool onLine(const Point & pt, const Point & a, const Point & b) { return dblcmp(cross(pt - a, b - a)) == 0; }
inline double ptToLineAbsDis(const Point & pt, const Point & a, const Point & b) { return fabs(cross(pt - a, b - a)) / abs(b - a); }
double safe_sqrt(double x) { assert(x > -0.0005); return x < EPS ? 0.0 : sqrt(x); }
inline double getTriangleArea(const Point & pA, const Point & pB, const Point & pC)
{
	static double len[3];
	len[0] = abs(pA - pB); len[1] = abs(pB - pC); len[2] = abs(pA - pC);
	sort(len, len + 3);
	double a = len[2], b = len[1], c = len[0];
	return 0.25 * safe_sqrt((a + b + c) * (c - a + b) * (c + a - b) * (a + b - c));
}


double f, R, t, r, g;
double sqr(double x) { return x * x; }
double safe_acos(double x) { assert(fabs(x) < 1.005);
	return x > 1.0 ? acos(1.0) : x < -1.0 ? acos(-1.0) : acos(x); }

double tri_area(double a, double b, double c) {
	double p = (a + b + c) / 2.0;
	return safe_sqrt(p * (p - a) * (p - b) * (p - c));
}

bool betweenCmp(const double v, double l, double r) {
	if (l > r) swap(l, r);
	return l < v + EPS && v < r + EPS;
}

bool onSegment(const Point & p, const Point & a, const Point & b) {
	if (dblcmp(cross(p - a, b - a)) != 0)
		return false;
	return fabs(a.real() - b.real()) > fabs(a.imag() - b.imag()) ? betweenCmp(p.real(), a.real(), b.real()) :
		betweenCmp(p.imag(), a.imag(), b.imag());
}

inline void intersects(const Point & a, const Point & b, Point & ans, int & ansCnt, const Point & fA, const Point & fB,
	double r)
{
	ansCnt = 0;
	Point vect = b - a, otherVect = Point(-vect.imag(), vect.real());
	//printf("%.2lf, %.2lf, %.2lf, %.2lf\n", a.real(), a.imag(), b.real(), b.imag());
	double len = abs(vect), toLineDis = ptToLineAbsDis(Point(0.0, 0.0), a, b);
	if (toLineDis > r + EPS) // outside of the circle
		return;

	otherVect *= toLineDis / len;
	if (!onLine(otherVect, a, b))
		otherVect = -otherVect;
	assert(onLine(otherVect, a, b)); // ###########################################################################

	//printf("## x = %.6lf, %.6lf\n", r * r - toLineDis * toLineDis, toLineDis);
	double verticalDis = safe_sqrt(r * r - toLineDis * toLineDis);
	vect *= verticalDis / len;

	Point resA = otherVect + vect, resB = otherVect - vect;
	if (onSegment(resA, a, b) && !equal(fA, resA) && !equal(fB, resA))
		ans = resA, ansCnt = 1;
	if (onSegment(resB, a, b) && !equal(fA, resB) && !equal(fB, resB))
		ans = resB, ansCnt = 1;
}

double solve(const Point & left, const Point & right, double arc)
{
	double a = abs(left), b = abs(right), c = abs(left - right);
	if (fabs(a) < 1e-4 || fabs(b) < 1e-4) {
		dprintf("right %.5lf, %.5lf\n", a, b);
		exit(-1);
	}
	return arc * arc * 0.5 * safe_acos((a * a + b * b - c * c) / (2.0 * a * b)) - 0.5 * fabs(cross(left, right)) +
		0.5 * fabs((left.real() - right.real()) * (left.imag() - right.imag()));
}

double getInvalidArea(double left, double right, double lower, double upper, double arc)
{
	if (left + EPS > right || lower + EPS > upper)
		return 0.0;

	int m[4];
	Point p[4];
	Point leftUpper = Point(left, upper), leftLower = Point(left, lower), rightUpper = Point(right, upper),
	      rightLower = Point(right, lower);
	dprintf("%.6lf, %.6lf, %.6lf, %.6lf\n", left, right, lower, upper);
	intersects(leftUpper, leftLower, p[0], m[0], leftUpper, leftLower, arc);
	intersects(leftUpper, rightUpper, p[1], m[1], rightUpper, rightUpper, arc);
	intersects(rightUpper, rightLower, p[2], m[2], rightUpper, rightUpper, arc);
	intersects(leftLower, rightLower, p[3], m[3], rightLower, leftLower, arc);
	double area = (right - left) * (upper - lower);
	if (m[0] + m[1] + m[2] + m[3] == 0)
	{
		return abs(rightUpper) < arc + EPS ? area : 0.0;
	}
	else if (m[0] > 0 && m[1] == 0 && m[2] == 0 && m[3] > 0)
	{
		return solve(p[0], p[3], arc);
	}
	else if (m[0] == 0 && m[1] > 0 && m[2] > 0 && m[3] == 0)
	{
		double a = abs(p[1]), b = abs(p[2]), c = abs(p[1] - p[2]);
		return area - (0.5 * fabs((p[1].real() - p[2].real()) * (p[1].imag() - p[2].imag())) -
			(arc * arc * 0.5 * safe_acos((a * a + b * b - c * c) / (2.0 * a * b)) - tri_area(a, b, c)));
	}
	else if (m[0] == 0 && m[1] > 0 && m[2] == 0 && m[3] > 0)
	{
		return (p[1].real() - left) * (upper - lower) + solve(p[1], p[3], arc);
	}
	else if (m[0] == 1 && m[1] == 0 && m[2] == 1 && m[3] == 0)
	{
		return (p[2].imag() - lower) * (right - left) + solve(p[0], p[2], arc);
	}
	else
	{
		printf("Unknown, %d, %d, %d, %d\n", m[0], m[1], m[2], m[3]);
		printf("%.6lf, %.6lf\n", p[3].real(), p[3].imag());
		exit(-1);
	}
	return 0.0;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		//if (caseNo == 3)
		//	DEBUG = true;
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		double totArea = R * R * PI / 4.0, invalidArea = 0.0;

		double curHt = r;
		double invalidPerSq = max(0.0, sqr(g - 2.0 * f));
		double x = 0.0;
		while (curHt < R - t + EPS)
		{
			double nextHt = curHt + g;

		//	double bottomWidth = safe_sqrt(sqr(R - t) - sqr(curHt));
			double topWidth = safe_sqrt(max(0.0, sqr(R - t) - sqr(nextHt)));

			double curLeft = r;
			while (curLeft < R - t + EPS)
			{
				x += getInvalidArea(curLeft + f, curLeft + g - f, curHt + f, nextHt - f, R - t - f);
				curLeft += g + 2.0 * r;
			}/*
			int totalSqCnt = (int)(floor(topWidth / (g + 2.0 * r) + EPS) + EPS);
			if (totalSqCnt > 0)
				totalSqCnt -= 2;
			invalidArea += totalSqCnt * invalidPerSq;

			printf("Ht = %.2lf, SqCnt = %d, TopWidth = %.2lf\n", curHt, totalSqCnt, topWidth);

			// right_bound: arc (R - t - f)
			// lower_bound: curHt + f;
			// left_bound: totalSqCnt * (g + 2.0 * r) + r + f
			// upper_bound: nextHt - f
			// right_line: (might not be of use)
			x += getInvalidArea(totalSqCnt * (g + 2.0 * r) + r + f,
					(totalSqCnt + 1) * (g + 2.0 * r) - r - f,
					curHt + f, nextHt - f,
				       	R - t - f) + getInvalidArea((totalSqCnt + 1) * (g + 2.0 * r) + r + f,
					(totalSqCnt + 2) * (g + 2.0 * r) - r - f,
					curHt + f, nextHt - f,
				       	R - t - f) + getInvalidArea((totalSqCnt + 2) * (g + 2.0 * r) + r + f,
					(totalSqCnt + 3) * (g + 2.0 * r) - r - f,
					curHt + f, nextHt - f,
				       	R - t - f);*/

			curHt += r * 2.0 + g;
		}

		dprintf("        + x = %.2lf\n", invalidArea + x);
		dprintf("  TotalArea = %.2lf\nInvalidArea = %.2lf\n", totArea, invalidArea);

		printf("Case #%d: %.6lf\n", caseNo + 1, (totArea - invalidArea - x) / totArea);
	}
	return 0;
}

