#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROBLEM "B-large1"
#define SZ(X) (int)X.size()

int main() {
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int N;
  cin >> N;
  for(int test = 1; test <= N; test++) {
    long long a=0,b=0,c=0,d=0,e=0,f=0;
    int n;    cin >> n;
    vector<long long> x(n),y(n),z(n),vx(n),vy(n),vz(n);
    for(int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
      a += x[i];
      b += vx[i];
      c += y[i];
      d += vy[i];
      e += z[i];
      f += vz[i];
    }
    //cerr<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<endl;
    double t, dist;
    long long tmp = b*b + d*d + f*f;
    if(tmp == 0) {
      t = 0.0;
    }
    else {
      t = ((a*b + c*d +e*f) * 1.0 / (b*b + d*d + f*f));
    }
    if(t > 0) {
      t = 0.0;
    }
    else {
      t = abs(t);
    }
    //cerr << t << endl;
    double xc=0.0,yc=0.0,zc=0.0;
    for(int i = 0; i < n; i++) {
      xc += x[i]*1.0 + t*vx[i];
      yc += y[i]*1.0 + t*vy[i];
      zc += z[i]*1.0 + t*vz[i];
    }
    xc /= n * 1.0;
    yc /= n * 1.0;
    zc /= n * 1.0;
    //cerr << xc << " " << yc << " " << zc << endl;
    dist = sqrt(xc * xc + yc * yc + zc * zc);
    cout << "Case #" << test << ": ";
    printf("%.8f %.8f\n", dist, t);
    
    /*
    for(double r = 0.0; r <= 10; r+=0.1) {
    t = r;
    xc=yc=0;zc=0;
    for(int i = 0; i < n; i++) {
      xc += x[i]*1.0 + t*vx[i];
      yc += y[i]*1.0 + t*vy[i];
      zc += z[i]*1.0 + t*vz[i];
    }
    xc /= n * 1.0;
    yc /= n * 1.0;
    zc /= n * 1.0;
    //cerr << xc << " " << yc << " " << zc << endl;
    dist = sqrt(xc * xc + yc * yc + zc * zc);
    printf("%.8f %.8f\n", dist, t);
    }
        */
  }
  return 0;
}
