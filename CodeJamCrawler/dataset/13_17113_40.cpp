#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int,int> pint;

#define pb push_back
#define MAX_N 1005
#define MAX 1000

int t;
unsigned long long dp[MAX_N];

bool is_pal(int num)
{
	int a=num;
   	int b=0;
 	while (num)
 	{
		b *= 10;
		b += (num%10);
		num /= 10;
	}
	return (a==b);
}

void calc()
{
	dp[0]=0;
	double root;
	for (int i=1; i<=MAX; i++)
	{
		dp[i]=dp[i-1];
		root = sqrt(i);
		if ((int)root==root && is_pal(i) && is_pal(root))
			dp[i]++;
	}
}

int main()
{
	calc();
	scanf("%d", &t);
	int a,b;
	for (int i=0; i<t; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: ", i+1);
		printf("%lld\n", (dp[b]-dp[a-1]));
	}
	return 0;
}
