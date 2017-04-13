#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

//////////////////////////////////////////////////////////////////////////
struct point {
	double x, y, z;
	point() { }
	point(double xx, double yy, double zz=0) { x = xx; y = yy; z = zz; }
	point operator +(const point &) const;
	point operator -(const point &) const;
	bool operator <(const point &) const;
	double operator *(const point &) const;
	double operator ^(const point &) const;
	double dist(const point &) const;
		
};

point point::operator +(const point &a) const {
	return point(x + a.x, y + a.y, z + a.z);
}

point point::operator -(const point &a) const {
	return point(x - a.x, y - a.y, z - a.z);
}

bool point::operator <(const point &a) const {
	if (y != a.y) return y < a.y;
	if (x != a.x) return x < a.x;
	return z < a.z;
}

//dot product
double point::operator *(const point &a) const {
	return x*a.x + y*a.y;
}

//cross product
double point::operator ^(const point &a) const {
	return x*a.y - y*a.x;
}

double point::dist(const point &a) const {
	double dx=x-a.x;
	double dy=y-a.y;
	return sqrt(dx*dx+dy*dy);
}

//a is the test point (I THINK, if no work try others)!
double pointLineDist(const point &a, const point &b, const point &c) {
	double dist=((b-a)^(c-a))/sqrt((b-a)*(b-a));
	//cut here for non-segments
	double dot1=(c-b)*(b-a);
	if(dot1>0) return sqrt((b-c)*(b-c));
	double dot2=(c-a)*(a-b);
	if(dot2>0) return sqrt((a-c)*(a-c));
	//end cut for non-segments
	return fabs(dist);
}

//Is mid in between points a and b (inside bounded rectangle)?
bool between(const point &mid, const point &a, const point &b) {
	return mid.x >= min(a.x, b.x) && mid.x <= max(a.x, b.x) && mid.y >= min(a.y, b.y) && mid.y <= max(a.y, b.y);
}


//Assumes vectors from the origin pointing towards a and b
double cross(const point &a, const point &b) {
	double x = a.y * b.z - a.z * b.y;
	double y = a.z * b.x - a.x * b.z;
	double z = a.x * b.y - a.y * b.x;
	if (x == 0 && y == 0) return z;
	else return sqrt(x * x + y * y + z * z);
}

//is (x,y) on the line segment?
bool online(double x1, double y1, double x2, double y2, double x, double y) {
	point a(x1,y1), b(x2,y2), c(x,y);
	if(!between(c,a,b)) return 0;
	x1-=x; x2-=x;
	y1-=y; y2-=y;
	return fabs(x1*y2-x2*y1)<1e-9;
}

double px[10000], py[10000];
int n;

//assumes px, py contain polygon coordinates. determines if x,y is in interior of polygon
bool inside(double x, double y) {
	//first check if on border
	for (int i = 0; i < n; i++)
		if (online(px[i], py[i], px[(i+1)%n], py[(i+1)%n], x, y)) return 1;
	//now check if on interior
	bool  oddNodes = 0;
	int j = n - 1;
	for (int i = 0; i < n; i++) {
		if (py[i] < y && py[j] >= y || py[j] < y && py[i] >= y) {
			if (px[i] + (y - py[i]) / (py[j] - py[i]) * (px[j] - px[i]) < x) {
				oddNodes = !oddNodes;
			}
		}
		j = i;
	}
 	return oddNodes;
}


////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

struct segment {
	point p1, p2;
	segment() { }
	segment(const point &a, const point &b) { p1 = a; p2 = b; }
	bool intersect(const segment &) const;	//for 2d space only
};


//Is point p on the line segment?
bool onsegment(const point &p, const segment &seg) {
	return (cross(seg.p1 - p, seg.p2 - p) == 0) && between(p, seg.p1, seg.p2);
}

//Do these two line segments intersect?
bool segment::intersect(const segment &seg) const {
	//Get relative directions for each point with respect to points on the other segment
	double d1 = cross(seg.p2 - seg.p1, p1 - seg.p1), d2 = cross(seg.p2 - seg.p1, p2 - seg.p1);
	double d3 = cross(p2 - p1, seg.p1 - p1), d4 = cross(p2 - p1, seg.p2 - p1);
	//If both segments "straddle" each other, they intersect
	if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0)) return 1;
	//Otherwise, endpoints of one segment could lie on the other one
	if (d1 == 0 && between(p1, seg.p1, seg.p2)) return 1;
	if (d2 == 0 && between(p2, seg.p1, seg.p2)) return 1;
	if (d3 == 0 && between(seg.p1, p1, p2)) return 1;
	if (d4 == 0 && between(seg.p2, p1, p2)) return 1;
	//No other way to intersect
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

//Point of reference which is used for sorting by angles in convexHull
point reference;

//Get the SQUARE of the distance between two points (z is 0 by default in 2d space)
double dist(const point &a, const point &b) {
	double x = a.x - b.x, y = a.y - b.y, z = a.z - b.z;
	return x * x + y * y + z * z;
}

//Do I turn left going from a->reference->b?
//Ties broken by distance to reference point
bool turnleft(const point &a, const point &b) {
	double crossprod = cross(a - reference, b - reference);
	if (crossprod != 0) return crossprod > 0;
	return dist(a, reference) < dist(b, reference);
}

//Do these 3 points form a triangle?
bool triangle(const point &a, const point &b, const point &c) {
	return cross(a - b, c - b) != 0;
}

//Get area of a polygon in either clockwise or counterclockwise order
double polygonArea(const vector<point> &points) {
	double area = 0;
	int n = points.size();
	//Compute area by triangulation
	for(int i = 1; i + 1 < n; i++) area += cross(points[i] - points[0], points[i + 1] - points[0]);
	return abs(area / 2.0);
}

//Get the convex hull of a set of points (it is assumed that there exist 3 non-colinear points)
vector<point> convexHull(vector<point> points) {
	int n = points.size();
	sort(points.begin(), points.end());
	//Other points are sorted by angle about this ont
	reference = points[0];
	points.erase(points.begin());
	sort(points.begin(), points.end(), turnleft);
	n--;
	//Remove all points with the same angle wrt reference except the one farthest away
	for (int i = 0; i + 1 < n; i++) if (cross(points[i] - reference, points[i + 1] - reference) == 0) {
		points.erase(points.begin() + i);
		n--;
		i--;
	}
	vector<point> mystack;
	mystack.push_back(reference); mystack.push_back(points[0]); mystack.push_back(points[1]);
	for (int i = 2; i < n; i++) {
		//Remove points that we know must not be in the convex hull
		while (true) {
			double crossprod = cross(mystack[mystack.size() - 1] - mystack[mystack.size() - 2], points[i] - mystack[mystack.size() - 2]);
			if (crossprod >= 0) break;
			mystack.pop_back();
		}
		mystack.push_back(points[i]);
	}
	//Convex hull is given by points in counterclockwise order wrt reference point
	return mystack;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//circle code will go here
//Assumes points are not colinear.  Returns the center of the circle formed by 3 points
pair<double,double> center(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s = 0.5*((x2 - x3)*(x1 - x3) - (y2 - y3)*(y3 - y1));
	double sUnder = (x1 - x2)*(y3 - y1) - (y2 - y1)*(x1 - x3);
	//if(sUnder==0) badness
	s /= sUnder;
	double xc = 0.5*(x1 + x2) + s*(y2 - y1); // center x coordinate
	double yc = 0.5*(y1 + y2) + s*(x1 - x2); // center y coordinate
	return make_pair(xc,yc);
}

/////////////////////////////////////////////////////////////

























#define llong long long

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

vector<segment> edges;
vector<int> xs, ys;

void proc(string path) {
	while(path[path.size()-1]!='F') path.resize(path.size()-1);
	xs.clear(); ys.clear();
	edges.clear();
	int x=0, y=0, prx=0, pry=0;
	int dir=0;
	int idx=0;
	px[0]=py[0]=0;
	idx++;
	for(int i=0;i<path.size();i++) {
		if(path[i]=='F') {
			x+=dx[dir]; y+=dy[dir];
		} else {
			edges.push_back(segment(point(prx,pry),point(x,y)));
			xs.push_back(prx); ys.push_back(pry);
			px[idx]=prx; py[idx]=pry;
			idx++;
			prx=x; pry=y;
			if(path[i]=='L') dir=(dir+1)%4;
			else dir=(dir+3)%4;
		}
	}
	xs.push_back(0); ys.push_back(0);
	xs.push_back(prx); ys.push_back(pry);
	px[idx]=prx; py[idx]=pry;
	idx++;
	n=idx;
	edges.push_back(segment(point(prx,pry),point(x,y)));
}

double solve() {
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	double ret=0;
	for(int i=0;i+1<xs.size();i++) if(xs[i]!=xs[i+1]) for(int j=0;j+1<ys.size();j++) if(ys[j]!=ys[j+1]) {
			double mx=.5*(xs[i]+xs[i+1]);
			double my=.5*(ys[j]+ys[j+1]);
			if(inside(mx,my)) continue;
			//cout<<xs[i]<<' '<<xs[i+1]<<"****"<<ys[i]<<' '<<ys[i+1]<<endl;
			segment v1(point(mx,my),point(mx,5000));
			segment v2(point(mx,my),point(mx,-5000));
			
			segment h1(point(mx,my),point(5000,my));
			segment h2(point(mx,my),point(-5000,my));
			
			bool a=0, b=0, c=0, d=0;
			
			for(int k=0;k<edges.size();k++) {
				if(edges[k].intersect(v1)) a=1;
				if(edges[k].intersect(v2)) b=1;
				if(edges[k].intersect(h1)) c=1;
				if(edges[k].intersect(h2)) d=1;
			}
			if((a&&b)||((c&&d))) ret+=(ys[j+1]-ys[j])*(xs[i+1]-xs[i]);
	}
	//cout<<endl<<endl;
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cout<<"Case #"<<tc<<": ";
		int l;
		cin>>l;
		string s;
		string path;
		int t;
		for(int i=0;i<l;i++) {
			cin>>s>>t;
			for(int j=0;j<t;j++) path+=s;
		}
		proc(path);
		cout<<solve()<<endl;
	}
}
