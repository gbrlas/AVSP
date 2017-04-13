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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------
#define MAXN 100100

int N;
char str[MAXN];
int con[MAXN];
int add[MAXN];
#define ISV(x) (x=='a' || x=='e' || x=='o' || x=='i' || x=='u')

int main() {

	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		scanf("%s%d", str, &N);
		//printf("%s\n", str);

		seta(con, 0);
		seta(add, 0);
		int len = (int) strlen(str);
		/*
		 forn(i, len){
		 if(!i){
		 con[i] = ISV(str[i]) ? 0 : 1;
		 } else {
		 con[i] = ISV(str[i]) ? 0 : con[i - 1] + 1;
		 }

		 // i - N ~ i
		 if( con[i] >= N ){
		 int s = i - N;
		 }
		 printf("%d\n", con[i]);
		 }*/
		/*
		 for(int i = len - 1; i >= 0; i--){
		 if( con[i] >= N ){
		 add[i] = add[i + 1] + 1;
		 }
		 printf("add %d\n", add[i]);
		 }*/
		int ans = 0;
		forn(i, len) {
			for (int j = i; j < len; j++) {
				seta(con, 0);
				for (int k = i; k <= j; k++) {
					if (k == i) {
						con[k] = ISV(str[k]) ? 0 : 1;
					} else {
						con[k] = ISV(str[k]) ? 0 : con[k - 1] + 1;
					}
					if (con[k] >= N) {
						ans++;
						break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", casenum++, ans);
		fflush(stdout);
	}
	return 0;
}
