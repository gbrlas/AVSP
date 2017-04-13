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

int TestCase;
Int2 tripA, tripB;
priority_queue <int, vector<int>, greater<int> > queueA, queueB, empty_queue;
int startA, startB;

void Input()
{
	int T, NA, NB;
	scanf("%d %d %d\n", &T, &NA, &NB);
	tripA.assign(24 * 60 + T + 1, Int1(0, 0));
	tripB.assign(24 * 60 + T + 1, Int1(0, 0));
	For (i, 0, NA)
	{
		int dh, dm, ah, am, dep, arr;
		scanf("%d:%d %d:%d", &dh, &dm, &ah, &am);
		dep = dh * 60 + dm;
		arr = ah * 60 + am + T;
		tripA[dep].pb(arr);
	}
	For (i, 0, NB)
	{
		int dh, dm, ah, am, dep, arr;
		scanf("%d:%d %d:%d", &dh, &dm, &ah, &am);
		dep = dh * 60 + dm;
		arr = ah * 60 + am + T;
		tripB[dep].pb(arr);
	}
	queueA = queueB = empty_queue;
	//queueA = queueB = priority_queue <int, vector<int>, greater<int>() > (greater<int>());
	queueA.push(INF);
	queueB.push(INF);
	startA = startB = 0;
}

void SolveA(int dep, int arr)
{
	int top = queueA.top();
	if (top > dep)
		++startA;
	else
		queueA.pop();
	queueB.push(arr);
}

void SolveB(int dep, int arr)
{
	int top = queueB.top();
	if (top > dep)
		++startB;
	else
		queueB.pop();
	queueA.push(arr);
}

void Solve()
{
	For (i, 0, 24 * 60)
	{
		For (j, 0, Size(tripA[i]))
			SolveA(i, tripA[i][j]);
		For (j, 0, Size(tripB[i]))
			SolveB(i, tripB[i][j]);
	}
}

void Output()
{
	printf("Case #%d: %d %d\n", TestCase, startA, startB);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d", &N);
	for (TestCase = 1; TestCase <= N; ++TestCase)
	{
		Input();
		Solve();
		Output();
	}
}