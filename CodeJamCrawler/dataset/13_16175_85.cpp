#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator iter;

const unsigned MAXN = 1010;

char str[10];

bool isPal(int n)
{
	sprintf(str, "%d", n);
	
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

vector<int> good;

void gen()
{
	int n2;
	for(int n=1; n*n < MAXN; n++)
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

	int a, b;

	gen();

	for(int t = 1; t <= T; t++)
	{
		scanf("%d%d", &a, &b);
			
		iter lb=  lower_bound(good.begin(), good.end(), a);
		iter ub = upper_bound(good.begin(), good.end(), b);

		int ans = ub - lb;
		printf("Case #%d: %d\n", t, ans);
	}
}