#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Circle
{
	double x, y, r;
};

typedef vector <Circle> VC;
typedef vector <int> VI;

const int ITER_MAX = 64;
const double MAX = 10000;
const double MIN = 0;

inline bool inRange(const Circle &c1, const Circle &c2, double range)
{
	return (range - c2.r) * (range - c2.r) >= (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

double dist(const VC &vc, const VI &ix, double x, double y)
{
	int n = (int) ix.size();
	double dist = 0;
	for (int i = 0; i < n; ++ i)
		dist = max(dist, hypot(x - vc[ix[i]].x, y - vc[ix[i]].y) + vc[ix[i]].r);
	return dist;
}

double minDist(const VC &vc, const VI &ix, double x)
{
	double l = -MAX, r = MAX, m1, m2;
	for (int i = 0; i < ITER_MAX; ++ i)
	{
		m1 = (2 * l + r) / 3;
		m2 = (l + 2 * r) / 3;
		if (dist(vc, ix, x, m1) < dist(vc, ix, x, m2))
			r = m2;
		else
			l = m1;
	}
	double ans = dist(vc, ix, x, m1);
	/*static bool blq = false;
	if (!blq) cout << m1 << endl;
	blq = true;*/
	return ans;
}

map <VI, double> mem;
double minRange(const VC &vc, const VI &ix)
{
	if (ix.size() == 0) return 0;
	if (mem.count(ix)) return mem[ix];
	double l = -MAX, r = MAX, m1, m2;
	for (int i = 0; i < ITER_MAX; ++ i)
	{
		m1 = (2 * l + r) / 3;
		m2 = (l + 2 * r) / 3;
		if (minDist(vc, ix, m1) < minDist(vc, ix, m2))
			r = m2;
		else
			l = m1;
	}
	double ans = minDist(vc, ix, m1);
	/*static bool blq = false;
	if (!blq) cout << ans << endl;
	blq = true;*/
	mem[ix] = ans;
	return ans;
}

double minRadius(int f, const VC &vc)
{
	mem.clear();
	int n = (int) vc.size();
	double l = vc[f].r, r = MAX, m;
	VI ix1, ix2;
	for (int i = 0; i < ITER_MAX; ++ i)
	{
		m = (l + r) / 2;
		ix1.clear();
		ix2.clear();
		for (int i = 0; i < n; ++ i)
			if (inRange(vc[f], vc[i], m))
				ix1.push_back(i);
			else
				ix2.push_back(i);
		//cout << m << endl;
		//cout << ix1.size() << " " << ix2.size() << endl;
		if (minRange(vc, ix1) > minRange(vc, ix2))
			r = m;
		else
			l = m;
	}
	//cout << minRange(vc, ix1) << " " << minRange(vc, ix2) << endl;
	return max(minRange(vc, ix1), minRange(vc, ix2));
}

int main(int argc, char *argv[])
{
	//freopen("D-test.in", "r", stdin);
	//freopen("D-test.out", "w", stdout);
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large.out", "w", stdout);

	int casesNumber = 0;
	cin >> casesNumber;
	for (int testCase = 1; testCase <= casesNumber; ++ testCase)
	{
		int n;
		scanf("%d", &n);
		VC vc(n);
		for (int i = 0; i < n; ++ i)
		{
			cin >> vc[i].x >> vc[i].y >> vc[i].r;
		}
		double ans = 1e30;
		for (int i = 0; i < n; ++ i)
			ans = min(ans, minRadius(i, vc));
		cout << "Case #" << testCase << ": " << ans << endl;
	}
	return 0;
}
