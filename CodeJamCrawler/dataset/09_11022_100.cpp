#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <cmath>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (int)b; ++i)
#define G(t) (X * VX + Y * VY + Z * VZ + t * (VX * VX + VY * VY + VZ * VZ))

template<typename T>
vector<T> split(const string& str){
    vector<T> ret;
    istringstream is(str);
    T tmp;
    while(is >> tmp) ret.push_back(tmp);
    return ret;
}

template<typename T>
inline void resize(vector<vector<T> > &v, int X, int Y){
    v.resize(X); for(int x = 0; x < X; ++x) v[x].resize(Y);
}

int T, N;
vector<double> x, y, z, vx, vy, vz;

template<typename T>
inline T sum(const vector<T>& v){
    return accumulate(v.begin(), v.end(), (T)0);
}

template<typename T>
inline T sq(const T& x) { return x * x; }

void calc(void){
    double X, Y, Z, VX, VY, VZ, I = 1.0 / (double)N;
    X = sum(x) * I;
    Y = sum(y) * I;
    Z = sum(z) * I;
    VX = sum(vx) * I;
    VY = sum(vy) * I;
    VZ = sum(vz) * I;

    double l = 0, u = 1e10;
    while(u - l > 1e-8){
	double m = (u + l) * 0.5;
	double g = G(m);
	if(g < 0) l = m;
	else u = m;
    }
//    cout << u << " " << G(u) << endl;
//    cout << 6 << " " << G(6) << endl;
    double t = (u + l) * 0.5;
    double d = sqrt(sq(X + t * VX) + sq(Y + t * VY) + sq(Z + t * VZ));
    //if(d < 1e-6) d = 0;
    cout << d << " " << t << endl;
}

int main(void){
    cin >> T;
    rep(c, 1, T+1){
	cout << "Case #" << c << ": ";
	cin >> N;
	x.clear(); x.resize(N);
	y.clear(); y.resize(N);
	z.clear(); z.resize(N);
	vx.clear(); vx.resize(N);
	vy.clear(); vy.resize(N);
	vz.clear(); vz.resize(N);
	rep(i, 0, N){
	    cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
	}
	calc();
    }
    return 0;
}
