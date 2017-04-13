#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double pi = acos (-1.0);
const double eps = 1.0e-10;

void small(char *problem, int try_time)
{
	char inFile[1024], outFile[1024];
	sprintf(inFile, "C:\\Users\\Lee\\Desktop\\%s-small-attempt%d.in", problem, try_time);
	sprintf(outFile, "C:\\Users\\Lee\\Desktop\\%s-small-attempt%d.out", problem, try_time);
	freopen (inFile, "r", stdin);
	freopen (outFile, "w", stdout);
}

void large(char *problem)
{
	char inFile[1024], outFile[1024];
	sprintf(inFile, "C:\\Users\\Lee\\Desktop\\%s-large.in", problem);
	sprintf(outFile, "C:\\Users\\Lee\\Desktop\\%s-large.out", problem);
	freopen (inFile, "r", stdin);
	freopen (outFile, "w", stdout);
}

int normal(int n)
{
    if (n % 3 == 0)
        return n / 3;
    if (n % 3 == 1)
        return (n + 2) / 3;
    return (n + 1) / 3;
}

int surprise(int n)
{
    if (n % 3 == 0)
        return n / 3 + 1;
    if (n % 3 == 1)
        return (n + 2) / 3;
    return (n + 4) / 3;
}

void solve()
{
    int n, s, p, x, c = 0;
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (normal(x) >= p)
            ++c;
        if (s > 0 && x > 1 && normal(x) < p && surprise(x) >= p)
            --s, ++c;
    }
    printf("%d\n", c);
}

int main()
{
	//small("B", 0);
	large("B");
	//freopen ("C:\\Users\\Lee\\Desktop\\A-large-practice.in", "r", stdin);
	//freopen ("C:\\Users\\Lee\\Desktop\\A-large-practice.out", "w", stdout);
	int ncase = 0;
	scanf("%d", &ncase);
	getchar();
	for (int icase = 1; icase <= ncase; ++icase)
	{
		printf("Case #%d: ", icase);
		solve();
	}
}
