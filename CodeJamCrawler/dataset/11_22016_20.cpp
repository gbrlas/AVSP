#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

using namespace std;

static inline int Abs(int n)
{
	if(n>=0) return n;
	else return -n;
}

static int Gcd(int m, int n)
{
	int a, b, r;
	if (Abs(m) > Abs(n)) {
		a=Abs(m);
		b=Abs(n);
	} else {
		a=Abs(n);
		b=Abs(m);
	}
	if (b == 0) return a;
	r = a % b;
	while (r != 0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}


int main() {
	int T;
	cin >> T;
	assert(T > 0);

	int base[101];
	for (int i = 1; i<=100; i++) {
		base[i] = 100/Gcd(i, 100);
	}

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": ";
		int 	N, PD, PG;
		string	strN;
		cin >> strN;
		N = atoi(strN.c_str());
		cin	>> PD >> PG;
		assert(PG >= 0 && PG <= 100 && PD<= 100 && PD >= 0);
		bool	possible = false;
		if (PG == 100 && PD < 100) {
					possible = false;
		} else if (PD == 0) {
			possible = true;
		} else if ( PG == 0) {
			possible = false;
		} else if (strN.length() > 8) {
			possible = true;
		} else 	{
			possible = N >= base[PD];
		}
		cout << (possible ? "Possible" : "Broken") << endl;
	}
}
