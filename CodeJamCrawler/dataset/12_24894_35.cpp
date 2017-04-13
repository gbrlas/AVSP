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

string  in[] = {"a zoo", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
string out[] = {"y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

char MAP['z' + 1];
bool WAS['z' + 1];

char G[110];

int main() {
#ifndef ONLINE_JUDGE
	freopen( "input.txt", "rt", stdin );
	freopen("output.txt", "wt", stdout);
#endif

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < in[i].length(); j++) {
			MAP[out[i][j]] = in[i][j];
			WAS[ in[i][j]] = true;
		}

	MAP['z'] = 'q';

	int T;
	scanf("%d\n", &T);

	for (int i = 1; i <= T; i++) {
		gets(G);

		for (int i = 0; G[i] != 0; i++)
			G[i] = MAP[G[i]];

		printf("Case #%d: %s\n", i, G);
	}

//#ifndef ONLINE_JUDGE
//	printf("\n>>> Time of execution %.3f seconds <<<\n", (double)clock() / CLOCKS_PER_SEC);
//#endif

	ret(0);
}
