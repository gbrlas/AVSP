#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

double C, F, X;

void solve(int tc) {
	scanf("%lf %lf %lf", &C, &F, &X);
	double speed = 2.0;
	double minn = X / speed;
	
	//int steps = 0;
	
	double sum = C / 2.0;
	speed += F;
	while (sum + (X / speed) < minn) {
		minn = sum + (X / speed);
		sum += C / speed;
		speed += F;
		//steps++;
	}
	printf("Case #%d: %.7lf\n", tc, minn);
	// fprintf(stderr, "steps needed %d\n", steps);
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) {
		solve(i+1);
	}
	return 0;
}
