#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define FOR(i,s,n) for(int(i)=(s);(i)<(n);(i)++)
#define DFOR(i,s,n) for(int(i)=(s);(i)>(n);(i)--)
#define SZ(v) (int)(v).size()
#define RESET(v,n) memset((v),(n),sizeof((v)))
#define PII pair<int,int>
#define PFF pair<double,double>
#define eps 1e-8
#define isEQF(f,a) (abs((f)-(a)) < eps)
#define LL long long
#define DEBUG puts("OK")
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
using namespace std;

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

inline void OPEN(string s) {
	freopen((s+ ".in").c_str(), "r",stdin );
	freopen((s+".out").c_str(), "w",stdout);
}

int n, optimum;
int list[100];

int stupidsum(deque<int>& L) {
	if (L.size() == 0) return -1;
	int ans = 0;
	for (deque<int>::iterator it=L.begin(); it!=L.end(); it++) {
		ans ^= (*it);
	}
	return ans;
}

void Divide(int ans, deque<int>& bigbro, deque<int>& litbro, int idx) {
	// cout << idx << ans << endl;
	if (idx==n) {
		if (bigbro.size() != 0 && litbro.size()!=0){
			int sumbro = stupidsum(bigbro);
			int sumlit = stupidsum(litbro);
			if (sumbro != -1 && sumlit!= -1) {
				if (sumbro == sumlit) {
					if (ans>optimum) {
						optimum = ans;
					}
				}
			}
		}
	} else {
		bigbro.push_back(list[idx]);
		Divide(ans+list[idx], bigbro, litbro, idx+1);
		bigbro.pop_back();
		litbro.push_back(list[idx]);
		Divide(ans, bigbro,litbro,idx+1);
		litbro.pop_back();
	}
}

int main() {
	int tc;
	scanf("%d",&tc);
	FOR(ii,0,tc) {
		deque<int> bigbro,litbro;
		optimum = -1;
		RESET(list,0);
		n = 0;
		scanf("%d",&n);
		FOR (i,0,n) {
			scanf("%d",&list[i]);
		}
		Divide(0,bigbro,litbro,0);
		// int a,b;
		// cin >> a >> b;
		// cout << (a^b);	
		if (optimum == -1) {
			printf("Case #%d: NO\n",ii+1);
		} else  {
			printf("Case #%d: %d\n",ii+1,optimum);
		}
	}
	return 0;
}
