#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)

typedef long long int64;

template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }

int patrick_add(int a, int b)
{
	return a^b;
}

int compare (const void * a, const void * b)
{
	return ( *(long*)a - *(long*)b );
}

void solve()
{
	long long ret=0, ssum[1024], psum[1024], rssum[1024];
	long a[1024];
	int n;
	scanf("%d", &n);
	REP(i,n)
		scanf("%ld", &a[i]);

	qsort(a, n, sizeof(long), compare);

	ssum[n-1] = a[n-1];
	rssum[n-1] = a[n-1];
	psum[0] = a[0];
	FOR(i,1,n-2)
	{
		rssum[n-1-i] = rssum[n-i] + a[n-1-i];
		ssum[n-1-i] = patrick_add(ssum[n-i], a[n-1-i]);
		psum[i] = patrick_add(psum[i-1],a[i]);
	}
	psum[n-1] = patrick_add(psum[n-2], a[n-1]);
	ssum[0]   = patrick_add(ssum[1], a[0]);
	rssum[0]  = rssum[1]+a[0];


//	cout << "\n";
//	REP(i,n)
//		cout << rssum[i] << " ";
//
//	cout << "\n";
//	REP(i,n)
//		cout << ssum[i] << " ";
//
//	cout << "\n";
//		REP(i,n)
//			cout << psum[i] << " ";

	bool fl = false;
	FOR(i, 0, n-2)
		if (psum[i] == ssum[i+1])
		{
			fl = true;
			ret = rssum[i+1];
			break;
		}


	if (fl)
	{
		printf("%Ld", ret);
	}
	else
	{
		printf("NO");
	}

}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d\n", &T);
	FOR(i, 1, T)
	{
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 1;
}
