#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0, _n = n; i < _n; ++i)
#define REP(i, a, b) for (int i = a, _n = b; i < _n; ++i)

const int m = 1000;
double x, y, z, vx, vy, vz;

double dist(int n, double t)
{
	double cx, cy, cz;
	cx = cy = cz = 0.0;
	
	cx += x + t * vx;
	cy += y + t * vy;
	cz += z + t * vz;
	
	return sqrt(cx * cx + cy * cy + cz * cz);
}

int main()
{
	ifstream cin("B-large.in");
	ofstream cout("B-large.out");

	int tc; cin >> tc;
	rep(t, tc)
	{
		int n; cin >> n;

		x = y = z = vx = vy = vz = 0.0;
		double xi , yi , zi , vxi , vyi , vzi;
		rep(i, n) 
		{
			cin >> xi >> yi >> zi >> vxi >> vyi >> vzi;
			x += xi; y += yi; z += zi;
			vx += vxi; vy += vyi; vz += vzi;
		}
		x /= n; y /= n; z /= n; 
		vx /= n; vy /= n; vz /= n;

		double tMin = 0.0, tMax = 1E15, tm1, tm2, d1, d2;

		rep(i, 5000)
		{
			tm1 = (2 * tMin + tMax) / 3.0;
			tm2 = (tMin + 2 * tMax) / 3.0;

			d1 = dist(n, tm1);
			d2 = dist(n, tm2);
			if (d1 > d2)
				tMin = tm1;
			else
				tMax = tm2;
		}
		
		cout << "Case #" << (t + 1) << ": ";
		cout.precision(8);
		cout << std::fixed << std::showpoint << dist(n, tMin) << " " << tMin << '\n';

	}

	return 0;
}