#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <sstream>
#include <cmath>

using namespace std;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI; 

#define PB push_back
#define MP make_pair

struct Task 
{
	int M, V;

	VI G, C, Val;

	VVI t;

	LL solve()
	{
		cin >> M >> V;

		G.assign(M,0), C.assign(M,0), Val.assign(M,0);
		t.assign(M, VI(2, 100000));


		REP(i, ((M-1)/2))
		{
			int g, c;
			cin >> g >> c;
			G[i] = g;
			C[i] = c;
		}

		REP(i, ((M+1)/2))
		{
			int v;
			cin >> v;
			Val[i+(M-1)/2] = v;
		}

		int res = change(0, V);


		return res;

	}



	int change(int p, int v)
	{
		if (p >= M)
			return 0;


		int& res = t[p][v];
		if (res != 100000)
			return res;

		if (p >= (M-1)/2)
			return res = (v == Val[p] ? 0 : 100000);

		REP(x, 2)
		{
			REP(y, 2)
			{
				if (v)
				{
					if (!x && !y)
						continue;

					int m = change((p+1)*2-1,x);
					int m1 = change((p+1)*2,y);
					if (m > 1000 || m1 > 1000)
						continue;

					if (x && y)
						res = min(res, m+m1);
					else
					{
						if (!G[p])
						{
							res = min(res, m+m1);
						}
						if (G[p] && C[p])
						{
							res = min(res, m+m1+1);
						}
					}
				}
				else
				{

					if (x && y)
						continue;

					int m = change((p+1)*2-1,x);
					int m1 = change((p+1)*2,y);
					if (m > 1000 || m1 > 1000)
						continue;

					if (!x && !y)
						res = min(res, m+m1);
					else
					{
						if (G[p])
						{
							res = min(res, m+m1);
						}
						if (!G[p] && C[p])
						{
							res = min(res, m+m1+1);
						}
					}

				}
			}
		}

		return res;
	}



};

int main() 
{
	freopen("in", "rt", stdin);
	freopen("out", "w", stdout);

	int tc; cin >> tc;
	REP(TC, tc) 
	{
		Task t;
		LL r = t.solve();

		//int N, M, A;
		//cin >> N>>M>>A;

		//bool more = true;
		//REP(x1, N+1)
		//{
		//	if (!more)break;

		//	REP(y1, M+1)
		//	{
		//		if (!more)break;

		//		REP(x2, N+1)
		//		{
		//			if (!more)break;

		//			REP(y2, M+1)
		//			{
		//				if (!more)break;

		//				REP(x3, N+1)
		//				{
		//					if (!more)break;

		//					REP(y3, M+1)
		//					{


		//						double a = sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
		//						double b = sqrt((double)((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
		//						double c = sqrt((double)((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));

		//						if (a+b <= c || a+c <= b || b+a <= c)
		//							continue;

		//						double p =(a+b+c)/2;

		//						double S = sqrt(p*(p-a)*(p-b)*(p-c));

		//						if (abs(S - (double)A/2) < 1e-14)
		//						{
		//							cout << "Case #" << TC+1 << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
		//							cerr << "Case #" << TC+1 << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";

		//							more = false;
		//						}



		//							if (!more)break;
		//					}
		//				}

		//			}
		//		}

		//	}
		//}

		//if (more)
		//{
		//cout << "Case #" << TC+1 << ": IMPOSSIBLE" << "\n";
		//cerr << "Case #" << TC+1 << ": IMPOSSIBLE" << "\n";
		//}

		if (r == 100000)
		{
			cout << "Case #" << TC+1 << ": IMPOSSIBLE" << "\n";
			cerr << "Case #" << TC+1 << ": IMPOSSIBLE" << "\n";
		}
		else
		{
			cout << "Case #" << TC+1 << ": " << r << "\n";
			cerr << "Case #" << TC+1 << ": " << r << "\n";
		}
	}

	fclose(stdout);
}
