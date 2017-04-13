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

int ans[32] = {0,5,27,143,751,935,607,903,991,335,47,943,471,55,447,463,991,95,607,263,151,855,527,743,351,135,407,903,791,135,647};

int main()
{
	int cas, k, n;

 	freopen("C-small-attempt1.in","r",stdin);
 	freopen("C-small-attempt1.out","w",stdout);

	cin >> cas;
	for(k=1;k<=cas;k++)
	{
		cin >> n;
		printf("Case #%d: %03d\n", k, ans[n]);
	}
}