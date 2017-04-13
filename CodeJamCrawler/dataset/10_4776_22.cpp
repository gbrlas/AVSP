#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

struct point
{
	double x,  y;

	point( const double & x,const double & y)
	{
		this -> x = x;	this ->y = y;
	}
	point () {}
};
struct segment
{
	point p1, p2;

	segment(const point &p1, const point &p2)
	{
		this -> p1 = p1;	this -> p2 = p2;
	}
	segment(){}
};

// dist3D_Segment_to_Segment():
// Input:  two 3D line segments S1 and S2
// Return: the shortest distance between S1 and S2
#define SMALL_NUM  0.00000001 // anything that avoids division overflow
// dot product (3D) which allows vector operations in arguments
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y)
#define norm(v)    sqrt(dot(v,v))  // norm = length of vector
#define d(u,v)     norm(u-v)       // distance = norm of difference
#define abs(x)     ((x) >= 0 ? (x) : -(x))   // absolute value

double
dist3D_Segment_to_Segment( const segment & S1, const segment & S2)
{

	point   u = point(S1.p2.x - S1.p1.x,S1.p2.y - S1.p1.y) ;
	point   v = point(S2.p2.x - S2.p1.x,S2.p2.y - S2.p1.y) ;
	point   w = point(S1.p1.x - S2.p1.x,S1.p1.y - S2.p1.y) ;

	double    a = dot(u,u);        // always >= 0
	double    b = dot(u,v);
	double    c = dot(v,v);        // always >= 0
	double    d = dot(u,w);
	double    e = dot(v,w);
	double    D = a*c - b*b;       // always >= 0
	double    sc, sN, sD = D;      // sc = sN / sD, default sD = D >= 0
	double    tc, tN, tD = D;      // tc = tN / tD, default tD = D >= 0

	// compute the line parameters of the two closest points
	if (D < SMALL_NUM) { // the lines are almost parallel
		sN = 0.0;        // force using point P0 on segment S1
		sD = 1.0;        // to prevent possible division by 0.0 later
		tN = e;
		tD = c;
	}
	else {                // get the closest points on the infinite lines
		sN = (b*e - c*d);
		tN = (a*e - b*d);
		if (sN < 0.0) {       // sc < 0 => the s=0 edge is visible
			sN = 0.0;
			tN = e;
			tD = c;
		}
		else if (sN > sD) {  // sc > 1 => the s=1 edge is visible
			sN = sD;
			tN = e + b;
			tD = c;
		}
	}

	if (tN < 0.0) {           // tc < 0 => the t=0 edge is visible
		tN = 0.0;
		// recompute sc for this edge
		if (-d < 0.0)
			sN = 0.0;
		else if (-d > a)
			sN = sD;
		else {
			sN = -d;
			sD = a;
		}
	}
	else if (tN > tD) {      // tc > 1 => the t=1 edge is visible
		tN = tD;
		// recompute sc for this edge
		if ((-d + b) < 0.0)
			sN = 0;
		else if ((-d + b) > a)
			sN = sD;
		else {
			sN = (-d + b);
			sD = a;
		}
	}
	// finally do the division to get sc and tc
	sc = (abs(sN) < SMALL_NUM ? 0.0 : sN / sD);
	tc = (abs(tN) < SMALL_NUM ? 0.0 : tN / tD);

	// get the difference of the two closest points
	point   dP = point(w.x + (sc * u.x) - (tc * v.x) , w.y + (sc * u.y) - (tc * v.y));  // = S1(sc) - S2(tc)

	return norm(dP);   // return the closest distance
}

int main()
{

	ifstream cin("1.txt");
	ofstream cout("out.txt");
	int t;

	cin >> t;

	for (int casenum = 1; casenum <= t; casenum++)
	{
		int A, B, N;
		vector <segment> segments;
		cin >> N;
		while(N--)
		{
			cin >> A >> B;

			segments.push_back(segment(point(-1000,A),point(1000,B) ));
		}

		int result = 0;
		//test intersection
		for (int x = 0; x < segments.size(); x++)
		{
			for (int y = x+1; y < segments.size(); y++)
			{
				if (dist3D_Segment_to_Segment(segments[x],segments[y]) <= SMALL_NUM*4)
					result++;
				
			}
		}

		cout << "Case #"<<casenum<<": " << result << endl;
	}

	cout.close();
}