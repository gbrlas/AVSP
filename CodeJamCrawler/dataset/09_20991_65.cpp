#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500;
const double EPS = 1e-8;

struct Vector {
	double x, y, z;

	Vector() {
		x = y = z = 0.0;
	}
	Vector(double x, double y, double z) : x(x), y(y), z(z) {}

	inline Vector operator + (const Vector & other) const {
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	inline Vector operator - (const Vector & other) const {
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	inline Vector operator * (const double num) const {
		return Vector(x * num, y * num, z * num);
	}

	inline Vector operator / (const double num) const {
		return Vector(x / num, y / num, z / num);
	}

	inline double operator | (const Vector & other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	inline double sqrlen() const {
		return x*x + y*y + z*z;
	}

	inline double len() const {
		return sqrt(x*x + y*y + z*z);
	}
};

Vector start[MAXN], speed[MAXN];

Vector ptoline(const Vector & p, const Vector & from, const Vector & v) {
	double t = -((p - from) | v) / v.sqrlen();
	return from - v * t;
}

int main() {
	int caseNum;
	cin >> caseNum;
	const Vector origin;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n;
		cin >> n;
		Vector psum, vsum;
		for (int i = 0; i < n; i++) {
			cin >> start[i].x >> start[i].y >> start[i].z;
			cin >> speed[i].x >> speed[i].y >> speed[i].z;
			psum = psum + start[i];
			vsum = vsum + speed[i];
		}
		Vector p = psum / n;
		Vector v = vsum / n;
		printf("Case #%d: ", caseIndex);
		if (abs(v.x) <= EPS && abs(v.y) <= EPS && abs(v.z) <= EPS) {
			printf("%.8lf %.8lf\n", p.len(), 0.0);
			//cout << p.len() << ' ' << 0.0 << endl;
		} else {
			Vector nearest = ptoline(origin, p, v);
			Vector delta = nearest - p;
			double t;
			if (abs(v.x) <= EPS) {
				if (abs(v.y) <= EPS) {
					t = delta.z / v.z;
				} else {
					t = delta.y / v.y;
				}
			} else {
				t = delta.x / v.x;
			}
			if (t >= -EPS) {
				printf("%.8lf %.8lf\n", nearest.len(), t);
			} else {
				printf("%.8lf %.8lf\n", p.len(), 0.0);
			}
		}
	}
	
	return 0;
}
