#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
  freopen("small.in", "rt", stdin);
  //freopen("large.in", "rt", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
	long long a, n, m;
	cin >> n >> m >> a;
	long long y3 = 0;
	long long x3 = 0;

	bool done = false;
	//for (long long  x3 = 0; !done && x3 <= n; x3++)
	for (long long  x1 = 0; !done && x1 <= n; x1++)
		for (long long y1 = 0; !done && y1 <= m; y1++)
			for (long long  x2 = 0; !done && x2 <= n; x2++)
				for (long long  y2 = 0; !done && y2 <= m; y2++)
				{
					long long s = (x1 - x2) * (y1 + y2) + (x2 - x3) * (y2 + y3) + (x3 - x1) * (y3 + y1);
					if (s < 0) s = - s;
					if (s == a) {
						done = true;
						cout << "Case #" << t + 1 << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
					}
				}
	if (!done)
	cout << "Case #" << t + 1 << ": " << "IMPOSSIBLE" << endl;
  }

  return 0;
}