#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
	//freopen("test.in", "r", stdin);

	int T; cin >> T;
	for(int test=1; test<=T; ++test)
	{
		int N; cin >> N;

		ll total = 0;
		ll m = 1 << 30;
		ll sum = 0;

		for(int i=0; i<N; ++i)
		{
			ll curr; cin >> curr;
			
			if(m > curr)
				m = curr;

			total ^= curr;
			sum += curr;
		}

		cout << "Case #" << test << ": ";
		if(total)
			cout << "NO" << endl;
		else
			cout << (sum - m) << endl;
	}
}