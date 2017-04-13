#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
double inner_product(vector< double > v, vector< double >u) {
	double ret = 0.0;
	for (int i = 0; i < 3; i++)
		ret += v[i] * u[i];
	return ret;
}
int main(void) {
	int T, prob = 0;
	for (cin >> T; T; T--) {
		int N;
		cin >> N;
		vector< double > pos(3, 0.0);
		vector< double > vel(3, 0.0);
		for (int i = 0; i < N; i++) {
			int x, y, z, vx, vy, vz;
			cin >> x >> y >> z >> vx >> vy >> vz;
			pos[0] += (double)x;
			pos[1] += (double)y;
			pos[2] += (double)z;
			vel[0] += (double)vx;
			vel[1] += (double)vy;
			vel[2] += (double)vz;
		}
		for (int i = 0; i < 3; i++) {
			pos[i] /= (double)N;
			vel[i] /= (double)N;
		}
		double pp, pv, vv;
		pp = inner_product(pos, pos);
		pv = inner_product(pos, vel);
		vv = inner_product(vel, vel);
		double t, d;
		if (fabs(pp) < 1e-10) {
			t = 0.0;
			d = 0.0;
		}else if (fabs(vv) < 1e-10) {
			t = 0.0;
			d = pp;
		}else {
			t = -1.0 * pv / vv;
			if (t <= 0.0) {
				d = pp;
				t = 0.0;
			}
			else {
				d = pp - pv * pv / vv;
			}
		}
		/*
		cout << endl;
		cout << "pos: ";
		for (int i = 0; i < 3; i++)
			cout << pos[i] << " ";
		cout << endl;
		cout << "vel: ";
		for (int i = 0; i < 3; i++)
			cout << vel[i] << " ";
		cout << endl;
		cout << "pp: " << pp << endl;
		cout << "pv: " << pv << endl;
		cout << "vv: " << vv << endl;
		cout << "d: " << d << ", t: " << t << endl;
		*/
		if (fabs(d) < 1e-10)
			d = 0.0;
		else if (d < 0.0)
			d = 0.0;
			//cout << endl << "NOTICE!" << endl << endl;
		else
			d = sqrt(d);
		cout << "Case #" << ++prob << ": ";
		cout.precision(8);
		cout.setf(ios::fixed);
		cout << d << " " << t;
		cout << endl;
	}
	return 0;
}
