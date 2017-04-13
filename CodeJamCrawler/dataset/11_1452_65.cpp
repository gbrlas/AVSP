#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define X first
#define INF 1000000000
#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
#define V second
#define P first
#define ull unsigned long long
char *prime ;

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	int tt, l, n, c, a;
	long long t;

	cin >> tt;
	for(int tc = 1; tc <= tt; tc++)
	{
		cin >> l >> t >> n >> c;
		vector<int> d(n);
		for (int i=0; i < c; i++){
			cin >> a;
			for (int k = 0; k*c + i < n; k++){
				d[k*c + i] = a;
			}
		}
		int positionition;
		long long time = 0, ress = 0;
		for (positionition=0; positionition < n && time < t; positionition++){
			ress += 2 * d[positionition];
			time += 2*  d[positionition];
		}

		vector<int> temmp(d.begin() + positionition, d.end());
		if (time > t){
			ress = t;
			temmp.push_back((time - t) / 2);
		}
		sort(temmp.rbegin(), temmp.rend());
		int tl = 0;
		for (int i=0; i < temmp.size(); i++){
			if (tl < l){
				ress += temmp[i];
				tl++;
			} else {
				ress += 2 * temmp[i];
			}
		}
		printf("Case #%d: %lld\n",tc, ress);
	}
	return 0;
}