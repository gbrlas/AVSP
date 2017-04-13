#include <vector>
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

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

int ans[31] = {5, 27, 143, 751, 935, 607, 903, 991, 335, 47, 943, 471, 55, 447,
463, 991, 95, 607, 263, 151, 855, 527, 743, 351, 135, 407, 903, 791,
135, 647, 343};

int main() {
	string s;
	getline(cin, s);
	int NUM_TESTS = atoi(s.c_str());
	for(int cnt = 0; cnt < NUM_TESTS; cnt++){
		int temp;
		getline(cin, s);
		temp = atoi(s.c_str());
		
		int ret = ans[temp-1];
		stringstream rss;
		if(ret<10) rss << "0";
		if(ret<100) rss << "0";
		rss << ret;
				
		cout << "Case #" << (cnt+1)<<": " << rss.str() << endl;
	}

}





