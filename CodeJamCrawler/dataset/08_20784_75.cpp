#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
const double pi = 3.1415926;

/* Get the corner between (x1, y1)->(0,0) and (x2, y2)->(0, 0). */
double corner (double x1, double y1, double x2, double y2, double R)
{
	double dis = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	return 2 * asin (dis/(2*R));
}

/* Get the hu du square between (x1, y1) and (x2, y2). */
double corner_square (double x1, double y1, double x2, double y2, double R)
{
	double c = corner (x1, y1, x2, y2, R);
	double s1 = R * R * c/2;
	double s2 = R * R * sin (c)/2;
	return s1 - s2;
}




/* Compute the square with the nearest corner (x, y). */
double square (double R, double g, double t, double x, double y)
{
	double lim_R = R - t;


	if (x*x + y*y >= lim_R*lim_R)
	{
		return 0;
	}

	if ((x + g)*(x+g) + (y + g)*(y+g) <= lim_R*lim_R)
	{
		return g*g;
	}
	if (x > y)
	{
		return square (R, g, t, y, x);
	}

	double k1 = sqrt (x*x + (y+g)*(y+g));
	double k2 = sqrt ((x+g)*(x+g) + y * y);
	if (k1 >= lim_R && k2 >= lim_R)
	{
		double x1, x2, y1, y2;
		y1 = y;
		x2 = x;
		y2 = sqrt (lim_R * lim_R - x2 * x2);
		x1 = sqrt (lim_R * lim_R - y1 * y1);
		double s1 = corner_square (x1, y1, x2, y2, lim_R);
		double s2 = ((x1 - x)* (y2 - y)/2);
		return s1 + s2;
	}

	if (k1 < lim_R)
	{
		double x1, x2, y1, y2;
		x1 = x + g;
		y2 = y + g;
		y1 = sqrt (lim_R*lim_R - x1*x1);
		x2 = sqrt (lim_R * lim_R - y2*y2);
		double s1 = corner_square (x1, y1, x2, y2, lim_R);
		double s2 = (g*g - (y2 - y1)*(x1 - x2)/2);
		return s1 + s2;
	}
	else
	{
		double x1, x2, y1, y2;
		x1 = x + g;
		y1 = sqrt (lim_R*lim_R - x1*x1);
		x2 = x;
		y2 = sqrt (lim_R*lim_R - x2*x2);
		double s1 = corner_square (x1, y1, x2, y2, lim_R);
		double s2 = (g/2) * (y1 + y2 - 2 * y);
		return s1 + s2;
	}
}

void everycase (fstream &f1, fstream &f2, int no)
{
	stringstream ssf,ssR,sst,ssr,ssg;
	string s;
	double f, R, t, r, g;
	string sf, sR, st, sr, sg;
	getline (f1, s);
	int x[4];
   	x[0] = s.find (' ', 0);
	sf = s.substr (0, x[0]);
	ssf << sf;
   	ssf >> f;	
	x[1] = s.find (' ', x[0] + 1);
	sR = s.substr (x[0] + 1, x[1] - x[0] - 1);
	ssR << sR;
	ssR >> R;
	x[2] = s.find (' ', x[1] + 1);
	st = s.substr (x[1] + 1, x[2] - x[1] - 1);
	sst << st;
	sst >> t;
	x[3] = s.find (' ', x[2] + 1);
	sr = s.substr (x[2] + 1, x[3] - x[0] - 1);
	ssr << sr;
	ssr >> r;
	sg = s.substr (x[3] + 1, s.size () - x[3] - 1);
	ssg << sg;
	ssg >> g;

	t = t + f;	
	g = g - 2 * f;

	r = r + f;

	f2.setf (ios::fixed);
	f2 << setprecision(6);
	if (g <= 0)
	{
		f2 << "Case #" << no << ": "<< (double)1.0 << endl;
		return;
	}

	double halfandhalf = 0;
	for (double x = r; x < R - t; x += g + 2 * r )
		for (double y = r; y < R - t; y += g + 2 * r)
		{
				halfandhalf += square (R, g, t, x, y);
		}
	halfandhalf*=4;


	double percent =  (double)1 - halfandhalf/(pi*R*R);
	f2 << "Case #" << no << ": "<<percent<<endl;
	
}


int main (int argc, char **argv)
{
	fstream fs, fs_out;
	stringstream ss;
	string s;
	int num_cases;
	fs.open (argv[1], fstream::in);
	getline (fs, s);
	ss << s;
	ss >> num_cases;
	fs_out.open ("output", fstream::out);
	for (int i = 1; i <= num_cases; i++)
	{
		everycase (fs, fs_out, i);
	}

	fs.close ();
	fs_out.close ();
}

