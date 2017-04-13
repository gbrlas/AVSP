// test
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

typedef unsigned long UL;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;

#define foreach(it,c) for (it=(c).begin(); it!=(c).end(); it++)

const int NMAX = 810;


int main()
{
	int i, j, cas, n;

	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	cin >> cas;
	for (j=1; j<=cas; j++)
	{
		VI x, y;
		cin >> n;
		for (i=0;i<n;i++)
		{
			int t;
			cin >> t;
			x.push_back(t);
		}
		for (i=0;i<n;i++)
		{
			int t;
			cin >> t;
			y.push_back(t);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());
		LL sum = 0;
		for (i=0; i<n; i++)
			sum += x[i] * y[i];
		cout << "Case #" << j << ": " << sum << endl;
	}
}