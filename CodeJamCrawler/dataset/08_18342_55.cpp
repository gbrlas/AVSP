#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
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

int N, M;
LL A;

void Read()
{
	scanf("%d %d", &N, &M);
	scanf("%I64d", &A);
}

bool Satis(int x1, int y1, int x2, int y2, int x3, int y3)
{
	LL sq = LL(x1-x2)*LL(y1+y2) + LL(x2-x3)*LL(y2+y3) + LL(x3-x1)*LL(y3+y1);
	sq = Abs(sq);
	return (sq==A);
}

void Solve()
{
	int x1, y1, x2, y2, x3, y3;
	for (y1=0;y1<=0;y1++)
	{
		//x1==0
		for (x1=0;x1<=0;x1++)
			for (x2=0;x2<=N;x2++)
				for (y2=0;y2<=M;y2++)
					for (x3=0;x3<=N;x3++)
						for (y3=0;y3<=M;y3++)
							if ( Satis(x1, y1, x2, y2, x3, y3) )
							{
								printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
								return;
							}

		//x2==0
		for (x1=0;x1<=N;x1++)
			for (x2=0;x2<=0;x2++)
				for (y2=0;y2<=M;y2++)
					for (x3=0;x3<=N;x3++)
						for (y3=0;y3<=M;y3++)
							if ( Satis(x1, y1, x2, y2, x3, y3) )
							{
								printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
								return;
							}


	}

	printf("IMPOSSIBLE\n");
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
