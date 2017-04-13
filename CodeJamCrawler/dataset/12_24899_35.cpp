// (.Y.)™

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ui unsigned int
#define ll long long int
#define ull unsigned long long int
#define pii pair <int, int>
#define pdd pair <double, double>
#define mp make_pair
#define pf push_front
#define pb push_back
#define ret return
#define all(x) (x).begin(), (x).end()
//#define DEBUG(x) cout << #x << ": " << (x) << endl

bool tab1[50][50];
bool tab2[50][50];

int main() {
#ifndef ONLINE_JUDGE
	freopen( "input.txt", "rt", stdin );
	freopen("output.txt", "wt", stdout);
#endif

	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			for (int k = 0; k <= 10; k++) {
				int MIN = min(min(i, j), k);
				int MAX = max(max(i, j), k);

				int S = i+j+k;

				if ( MAX-MIN <  2 )
					for (int i = 0; i <= MAX; i++)
						tab1[i][S] = true;

				if ( MAX-MIN == 2 )
					for (int i = 0; i <= MAX; i++)
						tab2[i][S] = true;
			}

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N, S, p;
		cin >> N >> S >> p;

		int res = 0;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;

			if ( tab1[p][t] )
				res++;
			else if ( tab2[p][t] )
				cnt++;
		}

		res += min(S, cnt);

		cout << "Case #" << i << ": " << res << endl;
	}

//#ifndef ONLINE_JUDGE
//	printf("\n>>> Time of execution %.3f seconds <<<\n", (double)clock() / CLOCKS_PER_SEC);
//#endif

	ret(0);
}
