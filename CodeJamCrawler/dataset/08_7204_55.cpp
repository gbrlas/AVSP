#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <boost/math/constants/constants.hpp>

using namespace std;

using boost::math::constants::pi;

#define TRACE_DEBUG(s, ...) printf(s##"\n", __VA_ARGS__)
//#define TRACE_DEBUG(s, ...)

#define sqr(x) ((x) * (x))

struct point_t { 
	point_t(double x, double y) : x(x), y(y) {}

	double x, y; 
};

const point_t center(0, 0);

inline double dist(point_t a, point_t b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double module(point_t a)
{
	return sqrt(sqr(a.x) + sqr(a.y));
}

inline double module(double x, double y)
{
	return sqrt(sqr(x) + sqr(y));
}

inline double triangle_area(double a, double b, double c)
{
	double s = 0.5 * (a + b + c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

inline double triangle_area(point_t x, point_t y, point_t z)
{
	return triangle_area(dist(x, y), dist(y, z), dist(x, z));
}

inline double tetragon_area(point_t a1, point_t a2, point_t a3, point_t a4)
{
	return triangle_area(a1, a2, a3) + triangle_area(a1, a3, a4);
}

inline double pentagon_area(point_t a1, point_t a2, point_t a3, point_t a4, point_t a5)
{
	double value = 0;
	value += triangle_area(a1, a2, a3);
	value += triangle_area(a1, a3, a4);
	value += triangle_area(a1, a4, a5);
	return value;
}

inline double dist_lines(point_t a1, point_t a2, point_t b1, point_t b2)
{

}

class circle_t
{
public:
	circle_t(double R, double r, double g) : _R(R), _r(r), _g(g) {}

	double area();
	double segmentArea(point_t a, point_t b);

	double point2point(double x) 
	{
		return sqrt(sqr(_R) - sqr(x));
	}

	double angle(point_t x)
	{
		return std::asin(x.y / _R);
	}

	bool in_circle(const point_t& a) { return module(a) <= _R; }

private:
	double _R, _r, _g;
};

double circle_t::segmentArea(point_t a, point_t b)
{
	double tetta = fabs(angle(b) - angle(a));
	return 0.5 * sqr(_R) * (tetta - sin(tetta));
}

double circle_t::area()
{
	double value = 0;

	for (double x = _r; x < _R; x += 2 * _r + _g)
	{
		for (double y = _r; y < _R; y += 2 * _r + _g)
		{
			point_t a(x, y), b(x + _g, y), c(x + _g, y + _g), d(x, y + _g);
			
			if (module(a) >= _R)
			{
				continue;
			}

			if (module(b) >= _R && module(d) >= _R)
			{
				point_t e(point2point(a.y), a.y), f(a.x, point2point(a.x));
				value += 0.5 * (e.x - a.x) * (f.y - a.y);
				value += segmentArea(e, f);
				continue;
			}

			if (module(b) <= _R && module(d) >= _R && module(c) > _R)
			{
				point_t e(b.x, point2point(b.x)), f(a.x, point2point(a.x));
				value += tetragon_area(a, b, e, f);
				value += segmentArea(e, f);
				continue;
			}

			if (module(b) >= _R && module(c) > _R && module(d) <= _R)
			{
				point_t e(point2point(a.y), a.y), f(point2point(d.y), d.y);
				value += tetragon_area(a, e, f, d);
				value += segmentArea(e, f);
				continue;
			}

			if (module(b) < _R && module(d) < _R && module(c) > _R)
			{
				point_t e(b.x, point2point(b.x)), f(point2point(d.y), d.y);
				value += pentagon_area(a, b, e, f, d);
				value += segmentArea(e, f);
				continue;
			}


			if (module(b) < _R && module(d) < _R && module(c) <= _R)
			{
				value += sqr(_g);
				continue;
			}

//			throw runtime_error("position not identified");
		}
	}

	return value;
}

class racquet_t
{
public:
	void read(istream& in);

	double probability(double f);

	bool in_circle(const point_t& a) { return module(a) <= _internalRadius; }	

private:
	double _R, _t, _r, _g;
	double _internalRadius;
};

double racquet_t::probability(double f)
{
	if (2 * f >= _g)
	{
		return 1.0;
	}

	circle_t circle(_R - _t - f, _r + f, _g - 2 * f);	
	double loose = (4 * circle.area()) / (pi<double>() * sqr(_R));
	return 1 - loose;
}

void racquet_t::read(istream& in)
{
	in >> _R >> _t >> _r >> _g;
	_internalRadius = _R - _t;
}

int main()
{
	ifstream in("fly_swatter.in");
	ofstream out("fly_swatter.out");
	size_t testCount;	

	in >> testCount;
	for (size_t i = 0; i < testCount; ++i)
	{
		racquet_t manager;
		double f;

		TRACE_DEBUG("Case #%d", i + 1);
		in >> f;
		manager.read(in);
		out << "Case #" << i + 1 << ": " 
			<< setprecision(6) << manager.probability(f) << std::endl;
	}

	return 0;
}