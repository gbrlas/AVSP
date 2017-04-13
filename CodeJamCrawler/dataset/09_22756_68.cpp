#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:60000000")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define double long double

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

char buf[1100000];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		gets(buf);

		string s = buf;

		string c = s;
		sort(all(c), greater<char> ());

		string ans;
		if (c == s) {
			vector<char> u(10);
			forn(i, s.size())
				u[s[i] - '0']++;
			u[0]++;
			for (int i = 1; i < 10; i++)
				if (u[i]) {
					u[i]--;
					ans += char('0' + i);
					break;
				}
			forn(i, 10)
				forn(jj, u[i])
					ans += char('0' + i);
		}
		else {
			vector<char> u(10);
			ans = "";
			ford(i, s.size()) {
				u[s[i] - '0']++;
				for (int j = s[i] - '0' + 1; j < 10; j++)
					if (u[j]) {
						ans = s;
						ans[i] = '0' + j;
						ans.erase(i + 1);
						u[j]--;
						forn(t, 10)
							forn(jj, u[t])
								ans += char('0' + t);
						break;
					}
				if (!ans.empty())
					break;
			}
		}

		printf("Case #%d: %s\n", ii + 1, ans.c_str());
	}
	
	return 0;
}