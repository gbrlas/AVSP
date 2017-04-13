#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

double x[100], y[100], r[100];
double px[10000], py[10000];
long cover[10000];
int N, C;
int nn;
double PI = acos(-1.0);

ifstream fin("r2d.in");
ofstream fout("r2d.out");
ofstream fout2("r2d2.out");

void addcenter(double x1, double y1, double rad)
{
	px[nn] = x1;
	py[nn] = y1;
	cover[nn] = 0;
	for (int i=0; i<N; i++)
	{
		if (hypot(x1-x[i], y1-y[i])+r[i] <= rad + 1e-8)
		cover[nn] |= 1ll<<i;
	}
	nn++;
}

bool possible(double rad)
{
	nn=0;
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (!(x[i] == x[j] && y[i] == y[j]))
			{
				double r1 = rad - r[i];
				double r2 = rad - r[j];
				if (r1 <= 1e-6 || r2 <= 1e-6) return false;
				double d = hypot(x[i] - x[j], y[i] - y[j]);
				if (r1 + r2 >= d)
				{
					double a = acos(fabs((d*d - r1*r1+r2*r2)/(2*d*r2)));
					double b = acos(fabs((d*d + r1*r1-r2*r2)/(2*d*r1)));
					double o;
					if (x[i] == x[j])
					{
						if (y[j] > y[i]) o = PI/2;
						else o = -PI/2;
					}
					else o = atan((y[j] - y[i])/(x[j] -x[i]));
					addcenter(x[i]+r1*cos(o+a), y[i]+r1*sin(o+a), rad);
					addcenter(x[i]+r1*cos(o-a), y[i]+r1*sin(o-a), rad);
				}
			}
	for (int i=0; i<N; i++)
		addcenter(x[i], y[i], rad);

	long full = (1ll<<N) -1;
	for (int i=0; i<nn; i++)
		for (int j=i; j<nn; j++)
			if ((cover[i] | cover[j]) == full)
			{
				return true;
			}
	return false;
}

bool possible2(double rad)
{
	for (int i=0; i<N; i++)
		if (rad < r[i]) return false;
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (!(x[i] == x[j] && y[i] == y[j]))
			{
				double r1 = rad - r[i];
				double r2 = rad - r[j];
				if (r1 <= 1e-6 || r2 <= 1e-6) return false;
				double d = hypot(x[i] - x[j], y[i] - y[j]);
				if (r1 + r2 + 1e-6 >= d)
				{
					return true;
				}
			}
	return false;
}

int main()
{
	int cases = 0;
	fin >> C;
	while (C--)
	{
		fin >> N;
		for (int i=0; i<N; i++)
			fin >> x[i] >> y[i] >> r[i];
		double ll = 0;
		double rr = 3000;
		while (fabs(ll-rr) > 1e-8)
		{
			double m = (ll+rr)/2;
			if (possible(m)) rr = m; else ll = m;
		}
		fout << "Case #" << ++cases << ": " << fixed << (ll+rr)/2 << endl;

		if (N==3)
		{
		ll = 0;
		rr = 3000;
		while (fabs(ll-rr) > 1e-8)
		{
			double m = (ll+rr)/2;
			if (possible2(m)) rr = m; else ll = m;
		}
		}
		else
		{
			if (N==1) ll=rr=r[0];  else ll=rr=max(r[0],r[1]); 
		}
		fout2 << "Case #" << cases << ": " << fixed << (ll+rr)/2 << endl;
	}
	return 0;
}