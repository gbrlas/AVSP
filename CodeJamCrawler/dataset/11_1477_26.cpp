#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

//#define X first
#define INF 1000000000
//#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
#define V second
#define P first
#define ull unsigned long long

#define speed first
#define path second


int main() {
	freopen("B-small.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("B-small__.out", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		char s;
		int R, C, D;
		cin >> R >> C >> D;
		vector<vector<int> > a(R, vector<int>(C));
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> s;
				a[i][j] = D + (s - '0');
			}
		}
		double c;
		int x, y;
		bool flag = false;
		for (int k = min(R, C); k >= 3 && !flag; k--)
		{
			c = (k + .0) / 2;
			for (int i = 0; i <= R - k && !flag; i++)
			{
				for (int j = 0; j <= C - k && !flag; j++)
				{
					double resx = 0, resy = 0;
					for (int m = 0; m < k; m++)
					{
						for (int n = 0; n < k; n++)
						{
							if (!((m == 0 && n == 0) || (m == 0 && n == k - 1) || (m == k - 1 && n ==0) || (m == k -1 && n == k -1)))
							{
								x = i + m;
								y = j + n;
								resx += a[x][y]*(k - m - 0.5 - c) ;
								resy += a[x][y]*(k - n - 0.5 - c) ;
							}
						}
					}
					if (resx == 0 && resy == 0)
					{
						cout << "Case #" << test << ": " << k << endl;
						flag = true;
					}
				}
			}
		}
		if (!flag)
		{
			cout << "Case #" << test << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}