#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;


#define MAX_SIZE 100

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	string str;
	getline(cin, str);
	stringstream ss;
	ss << str;
	ss >> T;

	REP(t,T)
	{
		int N;
		string str;
		getline(cin, str);
		stringstream ss;
		ss << str;
		ss >> N;


		double x0=0,y0=0,z0=0,vx=0,vy=0,vz=0;


		REP(n, N)
		{
		getline(cin, str);
		stringstream ss_;
		ss_ << str;
		double xn0,yn0,zn0,vnx,vny,vnz;
		ss_ >> xn0>>yn0>>zn0>>vnx>>vny>>vnz;

		x0 += xn0;
		y0 += yn0;
		z0 += zn0;

		vx += vnx;
		vy += vny;
		vz += vnz;
		}

		//x0 /= N;
		//y0 /= N;
		//z0 /= N;
		//vx /= N;
		//vy /= N;
		//vz /= N;


		const int ITERS = 120000;

		double tl = 0;
		double tr = 10e30;

		while(abs(tr-tl) > 10e-10)
		{
			double ta = tl + (tr-tl)/3;
			double tb = tl + 2*(tr-tl)/3;

			double xa = x0+vx*ta, ya = y0+vy*ta, za=z0+vz*ta;
			double fa = sqrt(xa*xa+ya*ya+za*za) / N;


			double xb = x0+vx*tb, yb = y0+vy*tb, zb = z0+vz*tb;
			double fb = sqrt(xb*xb+yb*yb+zb*zb) / N;

			if (fa > fb)
				tl = ta;
			else
				tr = tb;
		}

		double xf= x0+vx*tl, yf = y0+vy*tl, zf = z0+vz*tl;
		double f = sqrt(xf*xf+yf*yf+zf*zf)/N;


		char buf[0xff] = {0};
		sprintf(buf, "%.10f", tl);

		char buf_[0xff] = {0};
		sprintf(buf_, "%.10f", f);

		cout << "Case #" << (t+1) << ": " << buf_ << " " << buf << "\n";

		

	}




}