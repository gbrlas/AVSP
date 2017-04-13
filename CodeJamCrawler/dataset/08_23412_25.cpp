#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define FOREACH(T, it, a) for (T::iterator it = (a).begin(); it != (a).end(); ++it)
#define CD complex<double>
#define All(x) (x).begin(), (x).end()

LL N, k, d, g, ming;
char S[50047], old;
vector<char> vc;

int main()
{
	cin >> N;

	FOR (icase, 0, N)
	{
		cin >> k;
		scanf("%s", &S);
		d = strlen(S);

		vc.resize(k);
		FOR (i, 0, k)
			vc[i] = i;
		
		ming = d+d;

		do
		{
			old = 255;
			g = 0;

			FOR (i, 0, d)
			{
				if (old != S[(i/k)*k+vc[i%k]])
					g++;
				
				old = S[(i/k)*k+vc[i%k]];
			}
			
			if (ming > g)
				ming = g;

		} while (next_permutation(All(vc)));
		
		cout << "Case #" << icase+1 << ": " << ming << endl;
	}
	return 0;
}
