#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

const int MAX_DATA = 8;
const int MAX_SERVER = 4;

int tc;
int NData, NServer;
vector<string> data;
int catat[MAX_SERVER + 5];
int conf[MAX_DATA + 5];
vector<int> serverEl[MAX_SERVER + 5];

int ansCount, ansNode;
void lho() {
	memset(catat, 0, sizeof catat);
	REP(i, NData) catat[conf[i]] = 1;
	
	int ada = accumulate(catat, catat + NServer, 0);
	if (ada != NServer) return;
	
	REP(i, MAX_SERVER) serverEl[i].clear();
	REP(i, NData) serverEl[conf[i]].PB(i);
	
	int currConfNode = 0;
	//printf("conf : ");
	//REP(i, NData) printf("%d, ", conf[i]); puts("");
	
	REP(i, NServer) {
		//printf("i = %d\n", i);
		int maxLen = 0;
		REP(j, SZ(serverEl[i])) maxLen = max(maxLen, SZ(data[serverEl[i][j]]));
		set<string> zz;
		int currServerNode = 1;
		FOR(len, 1, maxLen) {
			zz.clear();
			REP(j, SZ(serverEl[i])) {
				if (SZ(data[serverEl[i][j]]) >= len) {
					zz.insert(data[serverEl[i][j]].substr(0, len));
				}
			}
			currServerNode += SZ(zz);
		}
		currConfNode += currServerNode;
		//printf("serverNode = %d\n", currServerNode);
	}
	if (currConfNode > ansNode) {
		ansNode = currConfNode;
		ansCount = 1;
		//if (currConfNode == 10) puts("a");
	}
	else if (currConfNode == ansNode) {
		ansCount++;
		//if (currConfNode == 10) puts("b");
	}
	//if (currConfNode == 10) puts("waaa");
}

void bruteConf(int x) {
	if (x < NData) {
		REP(i, NServer) {
			conf[x] = i;
			bruteConf(x + 1);
		}
	}
	else {
		lho();
	}
}

void solve() {
	cin >> NData >> NServer;
	scanf("%d %d", &NData, &NServer);
	data.clear();
	REP(i, NData) {
		string s;
		cin >> s;
		data.PB(s);
	}
	
	ansNode = 0;
	ansCount = 0;
	bruteConf(0);
	printf("Case #%d: %d %d\n", tc, ansNode, ansCount);
}

int main() {
	int T;
	cin >> T;
	for (tc = 1; tc <= T; tc++) solve();
	return 0;
}
