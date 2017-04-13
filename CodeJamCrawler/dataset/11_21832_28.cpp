#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int i , j , l , u , n , w;

struct point
{
	double x , y;
	point(){}
	point(double  _x , double _y)
	{
		x = _x;
		y = _y;
	}
};

struct line {
	double a, b, c;
	line(){}
	line(point aa , point bb)
	{
		a = aa.y - bb.y;
		b = bb.x - aa.x;
		c = -a * aa.x - b * aa.y;
	}
};
 
const double EPS = 1e-9;
 
double det (double a, double b, double c, double d) {
	return a * d - b * c;
}
 
bool intersect (line m, line n, point & res) {
	double zn = det (m.a, m.b, n.a, n.b);
	if (fabs (zn) < EPS)
		return false;
	res.x = - det (m.c, m.b, n.c, n.b) / zn;
	res.y = - det (m.a, m.c, n.a, n.c) / zn;
	return true;
}


double calc(vector<point> v)
{
	int i;
	int l = v.size();
	double ret = 0;
	for (i = 0; i < v.size(); i++)
	{
		ret = ret + v[i].x * v[(i+1) % l].y - v[i].y * v[(i+1) % l].x;
	}
	return fabs(ret);
}

point pu[1000] , pl[1000];

double get(double s)
{
	double le = 0;
	double ri = w;
	double x;
	vector<point> v , v1;
	int j;
	for (int i = 0; i < 100; i++)
	{
		x = (le + ri) / 2;
		v.clear();
		j = 0;
		while (j < l && x > pl[j].x)
		{
			v.push_back(pl[j]);
			j++;
		}
		
		line l1 = line(pl[j] , pl[j-1]);
		line l2 = line(point(x , 0) , point(x , 1));
		point xx;
		intersect(l1 , l2 , xx);
		v.push_back(xx);

		v1.clear();
		j = 0;
		while (j < u && x > pu[j].x)
		{
			v1.push_back(pu[j]);
			j++;
		}
		
		l1 = line(pu[j] , pu[j-1]);
		l2 = line(point(x , 0) , point(x , 1));
		intersect(l1 , l2 , xx);
		v1.push_back(xx);

		for (j = v1.size() - 1; j >= 0; j--)
			v.push_back(v1[j]);

		double area = calc(v);

		if (area > s)
			ri = x; else
			le = x;

	}
	return x;
}

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	int T, number = 0;
	cin>>T;
	while(T--) {
		cin>>w>>l>>u>>n;
		for (i = 0; i < l; i++)
		{
			cin>>pl[i].x>>pl[i].y;
		}

		for (i = 0; i < u; i++)
		{
			cin>>pu[i].x>>pu[i].y;
		}

		vector<point> p;
		for (i = 0; i < l; i++)
			p.push_back(pl[i]);

		for (i = u - 1; i >= 0; i--)
			p.push_back(pu[i]);

		double s = calc(p);
		
		vector<double> ans;

	

		cout << "Case #" << ++number << ":\n";

		double k = s / n;
		double xx = 0;
		for (i = 1; i < n; i++)
		{
			xx += k;
			printf("%.9lf\n" , get(xx));
		}

	}

	return 0;
}