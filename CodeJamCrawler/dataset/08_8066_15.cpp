#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi; 
typedef vector<string> vs;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rep(i, n) for(int i = 0; i < n; ++i) 
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it) 
#define INT_INF 0x7FFFFFFF 

main() {
	int N;
	int cas = 1;
	scanf("%d", &N);
	
	rep(i,N) {
		int num;
		scanf("%d", &num);
		vector<int> a(num);
		vector<int> b(num);
		
		int positivosA = 0;
		int positivosB = 0;
		rep(i,num) {
			scanf("%d", &a[i]);
		}
		rep(i,num) {
			scanf("%d", &b[i]);
		}
		
		sort(all(a));
		sort(b.rbegin(), b.rend());
		
		long long res = 0;
		
		rep(i, num) {
				//printf("%d*%d\n", *it1, *it2);
				res += (a[i])*(b[i]);
		}
		printf("Case #%d: %d\n", cas++, res);
	}
}	