#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 10e9
#define INFL 10e18
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(a) (a).begin(),(a).end()

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long ulong;

#define MAX_N 1000005

int n,s;
char l[MAX_N];

bool valid(char c) { return (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'); }

bool has(int a, int b)
{
	int x=0;
	for (int i=a; i<=b; i++)
		if (valid(l[i]))
		{
			x++;
			if (x==n) return true;
		} else x=0;
	return false;
}

ll solve()
{
	ll ans=0;
	for (int i=0; i<s; i++)
		for (int j=i; j<s; j++)
			if (has(i,j))
				ans++;
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++)
	{
		scanf("%s %d", l, &n);
		s=strlen(l);
		printf("Case #%d: %lld\n", i+1, solve());
	}
	return 0;
}
