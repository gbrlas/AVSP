#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
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
int gcd(int a, int b) {
	if (b==0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	int g = gcd(a,b);
	if (a%g == 0) return (a/g * b);
	else if (b%g == 0) return (b/g *a);
	else return (a*b / g);
}
int main() {
	int tc;
	scanf("%d",&tc);
	FOR(ii,0,tc) {
		int n,L,H;
		scanf("%d %d %d",&n,&L,&H);
		int a;
		vector<int> v(n);
		// scanf("%d",&a);
		// int kpk = lcm(1,a);
		
		FOR(i,0,n) {
			scanf("%d",&v[i]);
			// kpk = lcm(kpk,a);
		}
		// cout << kpk << endl;
		bool k = false;
		printf("Case #%d: ",ii+1);
		FOR(i,L,H+1) {
			// if (L <= (kpk*i) && (kpk*i) <= H) {
				// printf("%d\n",kpk*i);
				// found = true;
				// break;
			// }
			int found = true;
			FOR(j,0,n) {
				if (v[j] % i == 0 || i % v[j] == 0){
				} else {
					found = false;
					break;
				}
			}
			if (found) {
				k = true;
				printf("%d\n",i);
				break;
			}
		}
		if (!k) {
			printf("NO\n");
		}
	}
	return 0;
}
