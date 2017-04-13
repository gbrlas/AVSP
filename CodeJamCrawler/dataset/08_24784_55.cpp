#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define EPS 1e-9
#define RANGE 600

const double pi = 2*acos(0.);

struct point {
	double x,y;

	point(double xx, double yy) : x(xx), y(yy) {}
};

ostream& operator<<(ostream& out, const point p) {
	return out << "(" << p.x << ", " << p.y << ")";
}

struct circle {
	double r;

	circle(double rr) : r(rr) {}

	bool contains(point p) {
		if (p.x*p.x + p.y*p.y < r*r + EPS) return true;
		return false;
	}

	// Cumulative area function

	double F(double t) const {
		return t/2.*sqrt(r*r-t*t+EPS*EPS)+r*r*asin(t/r)/2.;
	}

	double slice(double a, double b) const{
		return F(b) - F(a);
	}

	double xval(double y) const {
		return sqrt(r*r-y*y + EPS*EPS);
	}

	double yval(double x) const {
		return sqrt(r*r-x*x + EPS*EPS);
	}
};

struct square {
	double x_cen, y_cen, w;
	
	square(double x, double y, double ww) : x_cen(x), y_cen(y), w(ww) {}

	point operator()(int i, int j) const {
		if (i*j != 1 && i*j != -1) {cout << "Point error"; exit(0);}
		return point(x_cen+i*w/2, y_cen+j*w/2);
	}
};

ostream& operator<<(ostream& out, const square s) {
	return out << "[" << s(-1,-1) << " " << s(1,1) << "]";
}

struct boxes {
	double w, s;

	boxes(double ww, double ss) : w(ww), s(ss) {}

	square operator()(int i, int j) {
		if (i < 0 || j < 0) {cout << "Boxes error"; exit(0);}
		return square((s+w)/2 + i*(s+w), (s+w)/2 + j*(s+w), w);
	}
};


int main() {
	int ncases;
	cin >> ncases;
	cout.precision(6);
	cout << fixed;
	for (int n = 1; n <= ncases; n++) {
		cout << "Case #" << n << ": ";

		double f, R, t, r, g;
		
		cin >> f >> R >> t >> r >> g;

		circle rim(R-t-f);
		boxes net(g-2*f, 2*(r+f));

		if (net.w < EPS) cout << 1.0;
		else {
			double area = 0.;
			for (int i = 0; i < RANGE; i++) {
				for (int j = 0; j < RANGE; j++) {
					square cur = net(i,j);
					if (rim.contains(cur(-1,-1))) {
						//cout << i << " " << j << endl;
						//if (n==2) cout << "\tConsidering " << i << " " << j << ": " << cur;
						// Calculate contributing area
						if (rim.contains(cur(1,1))) area += cur.w*cur.w;
						else if (rim.contains(cur(-1,1)))
							if (rim.contains(cur(1,-1))) {
								// Calculate area of 3-included piece
								double a = cur(-1,1).y, b = rim.yval(cur(-1,-1).x);
								area += rim.slice(cur(-1,-1).x, cur(1,-1).x) - cur.w*cur(-1,-1).y;
								area -= rim.slice(a, b) - (b-a)*cur(-1,-1).x;
								//cout << "area: " << ar << endl;
								//area += ar;
							} else {
								// Calculate area of 2-included on left piece
								area += rim.slice(cur(-1,-1).y, cur(-1,1).y) - cur.w*cur(-1,-1).x;
							}
						else if (rim.contains(cur(1,-1))) {
							// Calculate area of 2-include on the bottom piece
							area += rim.slice(cur(-1,-1).x, cur(1,-1).x) - cur.w*cur(-1,-1).y;
						} else {
							// Calculate area of 1-included piece
							double a = cur(-1,-1).x, b = rim.xval(cur(-1,-1).y);
							area += rim.slice(a,b) - (b-a)*cur(-1,-1).y;
						}
					}
				}
			}
			//cout << area << " ";
			double p = 1. - 4.*area/(pi*R*R);
			cout << p;
		}

		cout << endl;
	}
	return 0;
}