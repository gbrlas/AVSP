#include <deque>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <ctype.h>
#include <vector>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

string getans(int a, int n, int m){	
	int x1 = 0;
	int y1 = 0;
	//for(int x1=0; x1 <= n; x1++) for(int y1=0; y1 <= m; y1++)
	for(int x2=0; x2 <= n; x2++) for(int y2=0; y2 <= m; y2++)
	for(int x3=0; x3 <= n; x3++) for(int y3=0; y3 <= m; y3++) {
		if(x1==x2 && x2 == x3) continue;
		if(y1==y2 && y2 == y3) continue;

		int area = abs((x3-x1)*(y2-y1) - (x2-x1)*(y3-y1));
		if (area == a) {
			stringstream ss;
			ss << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
			return ss.str();
		}
	}
	
	return "IMPOSSIBLE";
}



int main() {
	string s;
	getline(cin, s);
	int NUM_TESTS = atoi(s.c_str());
	for(int cnt = 0; cnt < NUM_TESTS; cnt++){
		stringstream ss;
		getline(cin, s);
		ss << s;
		int a, n, m;
		ss >> n >> m >> a;
						
		cout << "Case #" << (cnt+1)<<": " << getans(a, n, m) << endl;
	}

}





