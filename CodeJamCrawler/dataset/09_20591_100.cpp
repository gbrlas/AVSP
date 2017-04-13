#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int x[512], y[512], z[512];
int vx[512], vy[512], vz[512];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int test = 1; test <= T; ++test)
	{
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d %d %d %d %d %d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
		double cx = 0, cy = 0, cz = 0, cvx = 0, cvy = 0, cvz = 0;
		for(int i = 0; i < N; ++i)
		{
			cx += x[i];
			cy += y[i];
			cz += z[i];
			cvx += vx[i];
			cvy += vy[i];
			cvz += vz[i];
		}
		cx /= N;
		cy /= N;
		cz /= N;
		cvx /= N;
		cvy /= N;
		cvz /= N;

		double t = 0;
		if(!(cvx == 0 && cvy == 0 && cvz == 0))
			t = -(cx * cvx + cy * cvy + cz * cvz) / (cvx * cvx + cvy * cvy + cvz * cvz);
		double bx = cx, by = cy, bz = cz;
		if(t < 0) t = 0;
		if(t > 0)
		{
			bx += t * cvx;
			by += t * cvy;
			bz += t * cvz;
		}
		double dis = sqrt(bx * bx + by * by + bz * bz);
		printf("Case #%d: %.8g %.8g\n", test, dis, t);
	}

	return 0;
}