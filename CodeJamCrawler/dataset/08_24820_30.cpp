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
	int pos(int r2, int r3, int r5, int r7)
	{
		int p = 0;
		p += r2*1000;
		p += r3*100;
		p += r5*10;
		p += r7;
		return p;
	}

	void get_res(int p, int &r2, int &r3, int &r5, int &r7)
	{
		r7 = p % 10;
		p /= 10;

		r5 = p % 10;
		p /= 10;

		r3 = p % 10;
		p /= 10;

		r2 = p % 10;
		//p /= 10;

	}

	//long long solve() 
	//{
	//	string str;
	//	cin >> str;
	//	int N = str.size();
	//	int P = 10000;
	//	vector<vector<LL> > total(N, vector<LL>(P,0));

	//	int df = str[0]-'0';
	//	total[0][pos(df%2, df%3, df%5, df%7)] = 1;

	//	FOR(i, 1, N)
	//	{
	//		REP(j, P)
	//		{
	//			if (total[i-1][j])
	//			{
	//				int r2, r3, r5, r7;
	//				get_res(j, r2, r3, r5, r7);

	//				int d = str[i] - '0';
	//				
	//				int q2, q3, q5, q7;
	//				q2 = (r2*10+d)%2;
	//				q3 = (r3*10+d)%3;
	//				q5 = (r5*10+d)%5;
	//				q7 = (r7*10+d)%7;

	//				int pq = pos(q2, q3, q5, q7);
	//				total[i][pq] += total[i-1][j];

	//				int w2, w3, w5, w7;
	//				w2 = (16+r2*10-d)%2;
	//				w3 = (27+r3*10-d)%3;
	//				w5 = (25+r5*10-d)%5;
	//				w7 = (49+r7*10-d)%7;

	//				int pw = pos(w2, w3, w5, w7);
	//				total[i][pw] += total[i-1][j];

	//				int e2, e3, e5, e7;
	//				e2 = (r2*10-0)%2;
	//				e3 = (r3*10-0)%3;
	//				e5 = (r5*10-0)%5;
	//				e7 = (r7*10-0)%7;

	//				int pe = pos(e2, e3, e5, e7);
	//				total[i][pe] += total[i-1][j];

	//			}
	//		}
	//	}

	//	LL res = 0;


	//	REP(j, P)
	//	{
	//		int r2, r3, r5, r7;
	//		get_res(j, r2, r3, r5, r7);
	//		if (!r2 || !r3 || !r5 || !r7)
	//		{
	//			res += total[total.size()-1][j];
	//		}
	//	}



	//	return res;

	//}


	LL solve()
	{
		LL n, m, X, Y, Z;
		cin >> n>> m>> X>> Y>> Z;
		
		vector<LL> A;
		REP(i, m)
		{
			LL a; cin >> a; A.PB(a);
		}

		vector<LL> s;

		for (int i = 0; i <= n-1; ++i)
		{
			s.PB(A[i % m]);
			A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
		}
		s.push_back(1000000000000000000LL);

		vector <LL> cnt(s.size());
		cnt[0] = 1;

		int N = s.size();
		
		FOR(i, 1, N)
		{
			REP(j, i)
			{
				if (s[i] > s[j])
				{
					cnt[i] += cnt[j];
					cnt[i] %= 1000000007LL;
				}
			}
			if (i != N-1)
			{
				cnt[i] += 1;
				cnt[i] %= 1000000007LL;
			}
		}

		return cnt[cnt.size()-1];
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
		cout << "Case #" << TC+1 << ": " << r << "\n";
		cerr << "Case #" << TC+1 << ": " << r << "\n";

	}

	fclose(stdout);
}
