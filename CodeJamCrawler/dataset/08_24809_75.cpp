// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include <algorithm> 
#include <iostream> 
#include <fstream> 
#include <utility> 
#include <numeric> 
#include <sstream> 
#include <iomanip> 
#include <string> 
#include <vector> 
#include <queue> 
#include <cmath> 
#include <list>
#include <map> 
#include <set> 

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
typedef VT<VD> VVD;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair

template<class T>
unsigned int read(std::vector<T>& cont, std::istream& strm, int n)
{
	int c = 0;

	for (; n > 0; n--, c++)
	{
		T t;
		strm >> t;
		cont.push_back(t);
	}

	return c;
}

template<class T>
unsigned int read_table(std::vector<std::vector<T> >& table, std::istream& strm, int n, int m)
{
	int c = 0;

	while (n--)
	{
		std::vector<T> cont;
		c += read(cont, strm, m);
		table.push_back(cont);
	}

	return c;
}

const double PI = 3.1415926535897932384626433832795;
const int MAX_STRINGS = 1000;

void assert(bool expr)
{
	if (!expr)
	{
		std::cerr << "\nAssertion failed\n";
	}
}

double triangle_area(double a, double b, double c)
{
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double segment_area(double x1, double y1, double x2, double y2)
{
	assert(x1<x2&&y2<y1);
	double d1 = sqrt(x1*x1+y1*y1);
	double d2 = sqrt(x2*x2+y2*y2);

	double cos_phi = (x1*x2+y1*y2) / (d1*d2);
	double phi = acos(cos_phi);

	double r_square = x1*x1+y1*y1;
	double sin_phi = sin(phi);

	double tri_s = triangle_area( d1, d2, sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) );

	double s_triangle = r_square*sin_phi / 2;
	double s_shape = r_square*phi/2;

	return s_shape - s_triangle;
}

//  
//  21    22
//
//  11    12
//
// .  ->  r
//

double intersect(double x, double y, double r, double down, double left, double up, double right)
{
	down -= y; up -= y; left -= x; right -= x;

	assert(up>down&&right>left);

	double x11 = left;
	double x12 = right;
	double x21 = left;
	double x22 = right;
	double y11 = down;
	double y12 = down;
	double y21 = up;
	double y22 = up;

	bool in11 = x11*x11+y11*y11 <= r*r;
	bool in12 = x12*x12+y12*y12 <= r*r;
	bool in21 = x21*x21+y21*y21 <= r*r;
	bool in22 = x22*x22+y22*y22 <= r*r;

	if (in11 && in12 && in21 && in22)
		return (right-left)*(up-down);

	if (!in11 && !in12 && !in21 && !in22)
		return 0;

	if (!in12 && !in21)
	{
		double xa = left;
		double ya = sqrt(r*r-left*left);

		double xb = sqrt(r*r-down*down);
		double yb = down;

		assert(ya>down&&xb>left);

		double s = (ya-down)*(xb-left)/2;
		double segment = segment_area(xa, ya, xb, yb);
		return s + segment;
	}
	else if (in12 && !in21)
	{
		double xa = left;
		double ya = sqrt(r*r-left*left);

		double xb = right;
		double yb = sqrt(r*r-right*right);

		assert(ya > yb);
		assert(yb > down);
		
		double s = (ya-yb)*(right-left)/2 + (yb-down)*(right-left);
		double segment = segment_area(xa, ya, xb, yb);
		return s + segment;
	}
	else if (!in12 && in21)
	{
		double xa = sqrt(r*r-up*up);
		double ya = up;

		double xb = sqrt(r*r-down*down);
		double yb = down;

		assert(xb > xa);
		assert(xa > left);

		double s = (xb-xa)*(up-down)/2 + (xa-left)*(up-down);
		double segment = segment_area(xa, ya, xb, yb);
		return s + segment;
	}
	else if (in11 && in12 && in21)
	{
		double xa = sqrt(r*r-up*up);
		double ya = up;

		double xb = right;
		double yb = sqrt(r*r-right*right);
		
		assert((right>xa)&&(up>yb));

		double s = (right-left)*(up-down) - (right-xa)*(up-yb)/2;

		assert(s > 0);

		double segment = segment_area(xa, ya, xb, yb);
		return s + segment;
	}
	
	return 0;
}

double flySwatter(double f, double  R, double t, double r, double g)
{
	if (f*2 >= g)
		return 1;

	double total = PI*R*R/4;

	double area = 0;

	for(int x = 0; x <= MAX_STRINGS; ++x)
	{
		double left = x*(g+2*r)+r+f;
		double right = (x+1)*(g+2*r)-r-f;
		//if (left > R)
		//	break;

		for(int y = 0; y <= MAX_STRINGS; ++y)
		{
			double down = y*(g+2*r)+r+f;
			double up = (y+1)*(g+2*r)-r-f;

		//	if (down > R)
		//		break;

			area += intersect(0, 0, R-t-f, down, left, up, right);
		}

	}


	return 1-area/total;
}


int main(int argc, char* argv[])
{
	std::ifstream f_in("in");
	std::ofstream f_out("out");

	int TestCount = 0;
	f_in >> TestCount;

	int test = 1;
	while (TestCount--)
	{
		double f, R, t, r, g;
		f_in >> f >> R >> t >> r >> g;

		double p = flySwatter(f, R, t, r, g);

		char buf[0xff] = {0};
		sprintf(buf, "%.6f", p);

		stringstream ss;
		ss << "Case #" << test << ": " << buf << "\n";
		std::cerr << ss.str();
		f_out << ss.str();

		test++;
	}

	return 0;
}