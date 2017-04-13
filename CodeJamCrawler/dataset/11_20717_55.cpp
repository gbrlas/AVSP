#include <iostream>
#include <map>
using namespace std;

#define MAX_N 1000

//f[n] = probability that a random permutation of 1..n has no fixed points
//f[n-k] = probability that a random permutation of 1..n has k fixed points
//g[n-k] = gorosort time if k elements of n are in the correct positions

//f[n] = 1 - sum[k=0..n-1]( f(k) / (n-k)! )
//f[0] = 0
//Prob[random permutation of 1..n has k fixed points] = (1/n!) * (n choose k) * ((n-k)! * f(n-k)) = f(n-k)/k!
//g[n] = 1 + sum[k=0..n](Prob[n-perm k fp] * g(n-k))
//g[n] = (1 + sum[k=1..n](f(n-k)*g(n-k)/k!))/(1-f(n))

long double factorial(int n) {
	static map<int, long double> cache;
	map<int, long double>::iterator iter = cache.find(n);
	if (iter != cache.end()) return iter->second;
	if (n == 0) return 1;

	long double ans = n * factorial(n-1);

	cache[n] = ans;
	return ans;
}

long double f(int n) {
	static map<int, long double> cache;
	map<int, long double>::iterator iter = cache.find(n);
	if (iter != cache.end()) return iter->second;
	if (n == 0) return 1;

	long double sum = 0;
	for (int k = 0; k < n; k++) {
		sum += f(k) / factorial(n-k);
	}

	cache[n] = 1-sum;
	return 1-sum;
}

long double g(int n) {
	static map<int, long double> cache;
	map<int, long double>::iterator iter = cache.find(n);
	if (iter != cache.end()) return iter->second;
	if (n == 0) return 0;

	long double sum = 0;
	for (int k = 0; k < n; k++) {
		sum += f(k) * g(k) / factorial(n-k);
	}
	long double ans = (sum + 1) / (1 - f(n));

	cache[n] = ans;
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int n, k = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x == i) k++;
		}
		long double ans = g(n - k);
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}

