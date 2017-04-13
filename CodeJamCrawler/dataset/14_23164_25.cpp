#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1000000 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;
int cs, T;
double C,F,X;

double solve() {
	double cookies = 0;
	double numCookiesPerSecond = 2;

	double timeElapsed = 0;
	while(true) {
		if(cookies >= X)
			break;

		double timeToWaitToBuyFarms = max((C - cookies) / numCookiesPerSecond, 0.0);
		double totalTimeToWaitForCompletionWithBuyingFarms = timeToWaitToBuyFarms 
							+ (
								(X-(cookies - C + timeToWaitToBuyFarms * numCookiesPerSecond)) / 
								(numCookiesPerSecond + F)
							);
		double timeToWaitForCompletion = (X - cookies) / numCookiesPerSecond;

		if(totalTimeToWaitForCompletionWithBuyingFarms < timeToWaitForCompletion) {
			timeElapsed += timeToWaitToBuyFarms;
			cookies = timeToWaitToBuyFarms * numCookiesPerSecond - C;
			numCookiesPerSecond = numCookiesPerSecond + F;
		}
		else {
			timeElapsed += timeToWaitForCompletion;
			cookies += timeToWaitForCompletion * numCookiesPerSecond;
		}
	}
	return timeElapsed;
}

int main() {
	int first, second;
	cin >> T;

	while(T--) {
		cin >> C >> F >> X;
		printf("Case #%d: %.6f\n", ++cs, solve());
	}
}