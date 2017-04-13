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
ll INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

int main(){
	ll T;
	cin >> T;
	
	string line;
	getline(cin,line);

	for(ll cnt = 0; cnt < T; cnt++) {
		getline(cin, line);
		stringstream ss(line.c_str());
		ll N, K;
		ss >> N >> K;

		ll remaining = K % (1LL << N);
		bool yes =  (remaining == ((1LL << N) - 1)); 
		
		cout << "Case #" << (cnt+1) << ": " << (yes ? "ON":"OFF")<< endl;
	}
}
	
	
	
	