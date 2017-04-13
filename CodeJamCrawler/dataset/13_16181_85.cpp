#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull>::iterator iter;

const ull MAXN = 100000000100000;

char str[1000];

bool isPal(ull n)
{
	sprintf(str, "%llu", n);
	
	int len = strlen(str);
	bool pal = true;
	for(int i=0; i<len/2; i++)
	{
		if(str[i] != str[len-1-i])
		{
			pal = false;
			break;
		}
	}

	return pal;
}

vector<ull> good;

void gen()
{
	ull n2;
	for(ull n=1; n*n < MAXN; n++)
	{
		if(isPal(n))
		{
			n2 = n*n;
			if(isPal(n2))
				good.push_back(n2);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d\n", &T);

	ull a, b;

	gen();

	for(int t = 1; t <= T; t++)
	{
		scanf("%llu%llu", &a, &b);
			
		iter lb=  lower_bound(good.begin(), good.end(), a);
		iter ub = upper_bound(good.begin(), good.end(), b);

		int ans = ub - lb;
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}