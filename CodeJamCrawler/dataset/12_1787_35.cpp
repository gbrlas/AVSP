#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

double eps = 1e-8;

double R[101010], W, L;
pair<double, double> ans[101010];
int n, id[101010];

int intersect(int x, int y)
{
	double dis = sqrt(sqr(ans[x].first - ans[y].first) + sqr(ans[x].second - ans[y].second));
	if (dis < R[x] + R[y] + eps) return 1;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		cin >> n >> W >> L;
		for (int i = 1; i <= n; i ++)
			cin >> R[i], id[i] = i;

		//sort
		for (int i = 1; i <= n; i ++)
			for (int j = i; j <= n; j ++)
				if (R[i] < R[j])
					swap(R[i], R[j]), swap(id[i], id[j]);
					
		//
		double cur = 0.0, dir = 1;   //1 -> right   -1 -> left
		
		for (int i = 1; i <= n; i ++)
		{
			double lo = 0, hi = L, mid;
			for (int k = 1; k <= 100; k ++)
			{
				mid = (lo + hi) / 2;
				pair<double, double> v = ans[i];
				ans[i] = make_pair(cur, mid);
				int colps = 0;
				for (int j = 1; j < i; j ++)
					if (intersect(i, j))
					{
						colps = 1; break;
					}
				ans[i] = v;
				if (colps)
					lo = mid; else {ans[i] = make_pair(cur, mid); hi = mid;}
			}
			if (i == n) continue;
			if (dir == 1)
			{
				cur += R[i];
				cur += R[i + 1] + eps;
				if (cur > W - eps)
				{
					cur = W; dir = -1;
				}
			}
			else
			{
				cur -= R[i];
				cur -= R[i + 1] + eps;
				if (cur < eps)
				{
					cur = 0; dir = 1;
				}
			}
		}
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (intersect(i, j))
					cout << "fuckyou" << endl;
		for (int i = 1; i <= n; i ++)	
			for (int j = 1; j <= n; j ++)
				if (id[j] == i)
					printf("%.10lf %.10lf ", ans[j].first, ans[j].second);
		cout << endl;
	}
	return 0;
}
