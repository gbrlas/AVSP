#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Abs(a) ((a)>0?(a):-(a))
#define Sqr(a) ((a)*(a))

#define EPS 1e-7
#define INF 1e9

using namespace std;

#ifdef _MSC_VER
	typedef __int64 LL;
#else
	typedef long long LL;
#endif

typedef vector <int> VI;
typedef vector <VI> VVI;

typedef double LD;
typedef vector <LD> VD;
typedef vector <VD> VVD;

typedef vector <string> VS;

const int MAX = 128;
const int MAXT = 2000;

int T;
int NA, NB;

struct Time
{
	int hh, mm;
	int t;

	void Read()
	{
		scanf("%d:%d", &hh, &mm);
		t = hh*60 + mm;
	}
};

Time begA[MAX], endA[MAX];
Time begB[MAX], endB[MAX];

void Read()
{
	scanf("%d", &T);
	scanf("%d %d", &NA, &NB);

	for (int i=0;i<NA;i++)
	{
		begA[i].Read();
		endA[i].Read();
	}

	for (int i=0;i<NB;i++)
	{
		begB[i].Read();
		endB[i].Read();
	}
}

void Solve()
{
	int curA = 0, curB = 0;
	int maxA = 0, maxB = 0;
	int freeA[MAXT], freeB[MAXT];
	memset(freeA, 0, sizeof(freeA));
	memset(freeB, 0, sizeof(freeB));

	int needA[MAXT], needB[MAXT];
	memset(needA, 0, sizeof(needA));
	memset(needB, 0, sizeof(needB));
	for (int i=0;i<NA;i++)
	{
		needA[begA[i].t]++;
		freeB[endA[i].t + T]++;
	}

	for (int i=0;i<NB;i++)
	{
		needB[begB[i].t]++;
		freeA[endB[i].t + T]++;
	}

	for (int i=0;i<MAXT;i++)
	{
		curA += freeA[i];
		curB += freeB[i];

		if ( needA[i]>curA )
		{
			maxA += needA[i] - curA;
			curA = needA[i];
		}
		if ( needB[i]>curB )
		{
			maxB += needB[i] - curB;
			curB = needB[i];
		}

		curA -= needA[i];
		curB -= needB[i];
	}

	printf("%d %d\n", maxA, maxB);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int ntest;
	scanf("%d", &ntest);
	for (int t=0;t<ntest;t++)
	{
		printf("Case #%d: ", t+1);
		Read();
		Solve();
	}

	return 0;
}
