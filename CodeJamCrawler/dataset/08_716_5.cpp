#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int MAX = 805;

int main() {
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i) {
	int N;
        cin >> N;

	int a[N], b[N];
	for (int i = 0; i < N; ++i)
	    cin >> a[i];
	for (int i = 0; i < N; ++i)
	    cin >> b[i];

	sort(a, a + N);
	sort(b, b + N, greater<int>());

	long long product = 0;
	for (int i = 0; i < N; ++i)
		product += (a[i] * b[i]);
	//Case #X: Y
	cout << "Case #" << i << ": " << product << endl;
    }    
    
    return 0;    
}
