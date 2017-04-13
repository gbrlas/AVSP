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
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define ULLS sizeof(ull)
#define MAXK 425
#define MAXN 210
#define BIT(i) ((ull)1 << (i))

int K, N;
int k[MAXK];
int ans[MAXN];
bool findAns;
int maxkey;
int relkey;

// chests
struct CST {
	int T;
	bool isOpen;
	bool sameKey;
	vector<int> key;
};
CST cst[MAXN];

// number of key of specific id
// number of cst of specific id
int keyId[MAXN];
int cstId[MAXN];

bool isEnoughKey(){
	// keyId now: total key count
	forn( i, MAXN ) {
		if (keyId[i] < cstId[i]) {
			return false;
		}
	}
	return true;
}
void getKey(int id) {
	keyId[id]++;
	relkey++;
}
void useKey(int id) {
	keyId[id]--;
	relkey--;
}
void openCst(int id, bool use) {
	int kid = cst[id].T;

	if(use) useKey(kid);
	if(use) cstId[kid]--;

	cst[id].isOpen = true;
	forn(i, cst[id].key.size()) {
		getKey(cst[id].key[i]);
	}
}
void closeCst(int id, bool use) {
	int kid = cst[id].T;

	if(use) getKey(kid);
	if(use) cstId[kid]++;

	cst[id].isOpen = false;
	forn(i, cst[id].key.size()) {
		useKey(cst[id].key[i]);
	}
}

void searchKey(int nowOpen) {
	vector<int> openId;
	openId.clear();

	while(true){
		int needKey;
		bool isOpen = false;
		for (int i = 0; i < N; i++) {
			if (cst[i].isOpen)
				continue;

			needKey = cst[i].T;
			if (keyId[needKey] == 0)
				continue;

			openCst(i, false);
			openId.pb(i);
			isOpen = true;
		}
		if(!isOpen) break;
	}
	maxkey = max(relkey, maxkey);
	forn(i, openId.size()){
		closeCst(openId[i], false);
	}
}

void search( int nowOpen ) {
	if (nowOpen == N) {
		findAns = true;
		return;
	}

	maxkey = 0;
	searchKey( nowOpen );

	if( N - nowOpen > maxkey ){
//		printf("N%d [%d] max %d\n", N, nowOpen, maxkey);
		return;
	}

	// for every chests
	int needKey;
	for (int i = 0; i < N; i++) {

		if (findAns)
			return;

		if (cst[i].isOpen)
			continue;

		needKey = cst[i].T;
		if (keyId[needKey] == 0)
			continue;

		ans[nowOpen] = i + 1;
		openCst(i, true);

#if 0
		printf("[%d] sureopen %d (", nowOpen, i);
		forn(j, 3) { if(j) printf(" ");
			printf("%d", keyId[ j ]);
		} printf(")\n");
#endif

		search( nowOpen + 1);
		closeCst(i, true);

		if (cst[i].sameKey || keyId[needKey] >= 2 || cstId[needKey] == 1) {
			return;
		}
	}
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		int n, tmp;

		//----------------------------
		// init
		forn(i, MAXN) {
			cst[i].key.clear();
			cst[i].isOpen = false;
			cst[i].sameKey = false;
		}
		seta(keyId, 0);
		seta(cstId, 0);

		seta(ans, 0);
		findAns = false;
		relkey = 0;

		//----------------------------
		// read file
		scanf("%d%d", &K, &N);
		forn(i, K) {
			scanf("%d", &k[i]);
			keyId[k[i]]++;
		}

		forn(i, N) {
			CST& c = cst[i];

			scanf("%d%d", &c.T, &n);
			cstId[c.T]++;
			forn(j, n) {
				scanf("%d", &tmp);
				c.key.pb(tmp);
				keyId[tmp]++;

				if (tmp == c.T)
					c.sameKey = true;
			}
		}

		//----------------------------
		// solve

		// not enough key
		if (isEnoughKey() == false) {
			printf("Case #%d: IMPOSSIBLE\n", casenum++);
			fflush(stdout);
			continue;
		}

		// search
		seta(keyId, 0);
		forn(i, K) {
			keyId[k[i]]++;
			relkey++;
		}
		search( 0 );

		if (findAns == false) {
			printf("Case #%d: IMPOSSIBLE\n", casenum++);
			fflush(stdout);
			continue;
		}

		printf("Case #%d: ", casenum++);
		forn( i, N ) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
		fflush(stdout);

	}
	return 0;
}

