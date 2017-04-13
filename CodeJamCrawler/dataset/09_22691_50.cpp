#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int tt;
    cin >> tt;

    REP (t, tt)
    {
    	cout << "Case #" << t+1 << ": ";

		int n;
		cin >> n;

		long long x=0,y=0,z=0,vx=0,vy=0,vz=0;
		long long xc=0,yc=0,zc=0,vxc=0,vyc=0,vzc=0;

		REP(i,n)
		{
			cin >> x >> y >> z >> vx >> vy >> vz;
			xc += x;
			yc += y;
			zc += z;
			vxc += vx;
			vyc += vy;
			vzc += vz;
		}

		double dx = (double)xc/(double)n;
		double dy = (double)yc/(double)n;
		double dz = (double)zc/(double)n;

		double dvx = (double)vxc/(double)n;
		double dvy = (double)vyc/(double)n;
		double dvz = (double)vzc/(double)n;

		double t=0.0;
		if((dvx*dvx+dvy*dvy+dvz*dvz)<=0.0)
			t=0.0;
		else
			t=(dvx*(-dx)+dvy*(-dy)+dvz*(-dz)) / (dvx*dvx+dvy*dvy+dvz*dvz);
		if(t<=0.0)
			t=0.0;

		double d=0.0;
		if(t>0.0)
		{
			dx+=dvx*t;
			dy+=dvy*t;
			dz+=dvz*t;
		}
		d=dx*dx+dy*dy+dz*dz;
		d = sqrtl (d);

		printf("%.15lf %.15lf", d, t);
		cout << endl;
	}

    return 0;
}
