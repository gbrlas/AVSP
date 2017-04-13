#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
using namespace std;
#define INF 1000000000
#define clr(u) memset(u, 0, sizeof u)
#define ini(u) memset(u, -1, sizeof u)
typedef long long int64;
typedef pair<int, int> PAIR;
/********************************/
int n;
char str[61];
int res[61], ri;
int r[200];
int main() {
	FILE* in = fopen("A-small-attempt0.in", "r");
	FILE* out = fopen("A.out", "w");
	fscanf(in, "%d", &n);
	for(int m = 1; m <= n; m++) {
		ini(r); ri = 0;
		fscanf(in, "%s", str);
		int len = strlen(str);
		if(str[0] >= '0' && str[0] <= '9')
			r[str[0] - '0'] = 1;
		else if(str[0] >= 'a' && str[0] <= 'b')
			r[str[0] - 'a' + 20] = 1;
		else
			r[str[0] - 'A' + 60] = 1;
		res[ri++] = 1;
		int now = 0;
		int maxn = 1;
		for(int i = 1; i < len; i++) {
			if(str[i] >= '0' && str[i] <= '9')
				if(r[str[i] - '0'] == -1) {
					r[str[i] - '0'] = now;
					res[ri++] = now;
					now++;
					if(now == 1) now++;
				} else {
					res[ri++] = r[str[i] - '0'];
				}
			else if(str[i] >= 'a' && str[i] <= 'b')
				if(r[str[i] - 'a' + 20] == -1) {
					r[str[i] - 'a' + 20] = now;
					res[ri++] = now;
					now++;
					if(now == 1) now++;
				} else {
					res[ri++] = r[str[i] - 'a' + 20];
				}
			else
				if(r[str[i] - 'A' + 60] == -1) {
					r[str[i] - 'A' + 60] = now;
					res[ri++] = now;
					now++;
					if(now == 1) now++;
				} else {
					res[ri++] = r[str[i] - 'A' + 60];
				}
			maxn = max(maxn, res[ri-1]);
		}
		int p = 1; int64 ans = 0;
		for(int i = ri - 1; i >= 0; i--) {
			ans += res[i] * p;
			p *= (maxn+1);
		} 
		fprintf(out, "Case #%d: %lld\n", m, ans);
	}
}