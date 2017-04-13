#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 4
int N;
ull r, t;

// (2r + 1) + (2r + 5) + (2r + 9) ...
//
// N (4N + 2r - 3) * N / 2 < t

bool check(ull n){
	ull s = ( 2 * n - 1 + 2 * r );
	if( s <= t / n ) return true;
	return false;
}

//binary search
ull FindMax(){
	ull beg = 0;
	ull end = inf64;
	ull mid;

	do{
		mid = (beg+end+1) / 2;
		if(check(mid)){
			beg = mid;
		}
		else
			end = mid-1;
	}while(beg < end);
	return end;
}

int main()
{
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while(cases--)
	{

		scanf("%llu%llu", &r, &t);
		ull ans = FindMax();


		printf("Case #%d: %llu\n", casenum++, ans);

	}
	return 0;
}

