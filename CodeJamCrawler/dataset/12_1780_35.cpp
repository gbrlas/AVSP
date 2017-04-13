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

int D[101010], Len[101010], F[101010];
int n, Dis;
vector<pair<int, int> > M;

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
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> D[i] >> Len[i];
		cin >> Dis;
		//DP
		M.clear();
		M.push_back(make_pair(D[1], 0));
		F[0] = D[1]; D[0] = 0;
		for (int i = 1; i <= n; i ++)
		{
			F[i] = -1000000; int ans = -1;
			//find
			for (int L = 0, R = M.size() - 1; L <= R; )
			{
				int mid = (L + R) / 2;
				if (M[mid].first >= D[i])
				{
					ans = M[mid].second;
					R = mid - 1;
				}
				else L = mid + 1;
			}
			if (ans != -1)
				F[i] = min(Len[i], D[i] - D[ans]) + D[i];
			//insert
			if (F[i] >= M[M.size() - 1].first)
				M.push_back(make_pair(F[i], i));
		}
		int Flag = 0;
		for (int i = 0; i <= n; i ++)
			if (F[i] >= Dis) Flag = 1;	
		if (Flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
