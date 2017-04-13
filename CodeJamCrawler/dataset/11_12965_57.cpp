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

int stars[1000000];
int group[1000];

void solve()
{
	ll t;
	int L, N, C;
	cin >> L >> t >> N >> C;

	for(int i=0; i<C; ++i)
		cin >> group[i];

	for(int i=0; i<N; ++i)
	{
		stars[i] = group[i % C];
	}

	ll ini = t;
	int i=0;
	while(i < N && ini)
	{
		if(2 * stars[i] >= ini)
		{
			stars[i] -= ini / 2;
			ini = 0;
		}
		else
		{
			ini -= 2 * stars[i];
			stars[i] = 0;
		}
		i++;
	}

	if(ini)
	{
		cout << t - ini << endl;
		return;
	}

	sort(stars, stars+N, std::greater<int>());

	ll speed=0; ll ns=0;
	for(i=0; i<L; ++i)
	{
		speed += stars[i];
	}
	for( ; i<N; ++i)
	{
		ns += stars[i];
	}

	cout << t + speed + 2 * ns << endl;
}

int main()
{
//	freopen("test.in", "r", stdin);
	
	int T; cin >> T;
	for(int test=1; test<=T; ++test)
	{
		printf("Case #%d: ", test);
		solve();
	}
}