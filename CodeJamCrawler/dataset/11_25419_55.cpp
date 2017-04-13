// I love natalia

#include <iostream>
#include <cstdio>

using namespace std;

long long aC[1010];

long long N;

long long PatrickSum(long long a, long long b) {
	long long res = a ^ b;

	return ( res );
}

long long f(long long p = 0, long long S1 = 0, long long S2 = 0, long long RealS1 = 0, long long k1 = 0, long long k2 = 0) {
	if ( p == N ) 
		if ( S1 == S2 && k1 > 0 && k2 > 0)
			return (RealS1);
		else
			return (-1);

	return (max(
					f(p+1, PatrickSum(S1, aC[p]),            S2        , RealS1+aC[p], k1+1, k2  ),
					f(p+1,            S1        , PatrickSum(S2, aC[p]), RealS1      , k1  , k2+1)
			));
}

int main() {
	freopen( "input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	long long    T;
	cin >> T;

	for (long long t = 1; t <= T; t++) {
		cin >> N;

		for (long long n = 0; n < N; n++)
			cin >> aC[n];

		long long res = f();

		if ( res == -1 )
			cout << "Case #" << t  << ": NO" << endl;
		else
			cout << "Case #" << t  << ": " << res << endl;
	}

	return 0;
}
