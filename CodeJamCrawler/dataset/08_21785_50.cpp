#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

#define For(i,l,h) for (int i = (l); i < (h); ++i)
#define ForU(i,l,h) for (int i = (l); i <= (h); ++i)
#define Size(c) (int)(c).size()
#define pb(c) push_back(c)
#define All(c) (c).begin(),(c).end()
#define RAll(c) (c).rbegin(),(c).rend()

typedef long long lint;
typedef vector <int> Int1;
typedef vector <Int1> Int2;
typedef vector <Int2> Int3;

const int INF = (1 << 30) - 1;
const double pi = acos(-1.0);

int N;
int TestCase;
int S;
map <string, int> input;
int Q;
Int1 query;
Int2 dp;
int result;

void Input()
{
	char buf[65536];

	scanf("%d\n", &S);
	input.clear();
	For (i, 0, S)
	{
		gets(buf);
		input[string(buf)] = i;
	}

	scanf("%d\n", &Q);
	query.assign(Q, 0);
	For (i, 0, Q)
	{
		gets(buf);
		query[i] = input[string(buf)];
	}

	dp.assign(Q + 1, Int1(S, INF));
	For (j, 0, S)
		dp[0][j] = 0;
}

void Solve()
{
	ForU (i, 1, Q)
		For (j, 0, S)
	{
		dp[i][j] = dp[i - 1][j];
		For (k, 0, S)
			dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
		dp[i][query[i - 1]] = INF;
	}
	result = *min_element(All(dp[Q]));
}

void Output()
{
	printf("Case #%d: %d\n", TestCase, result);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for (TestCase = 1; TestCase <= N; ++TestCase)
	{
		Input();
		Solve();
		Output();
	}
}