#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const char *inf = "A-small-attempt1.in";
const char *ouf = "output.txt";

using namespace std;

int n;
int s[100];
int v[100];
bool m[100];
int ans;

void init()
{
	memset(s, 0, sizeof(s));
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			char x;
			cin >> x;
			if (x>'0')
				s[i] = j;
		}
}

void check()
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (v[i] > v[j])
				++ret;
	if (ret < ans)
		ans = ret;
}

void search(int h)
{
	if (h >= n)
	{
		check();
		return ;
	}
	for (int i = 0; i < n; ++i)
		if (m[i] && s[i]<=h)
		{
			v[h] = i;
			m[i] = false;
			search(h+1);
			m[i] = true;
		}
}

void process()
{
	ans = n * n;
	memset(m, true, sizeof(m));
	search(0);
}

void print()
{
	printf("%d", ans);
}

int main()
{
	freopen(inf, "rt", stdin);
	freopen(ouf, "wt", stdout);
	
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
	{
		printf("Case #%d: ", i+1);
		init();
		process();
		print();
		printf("\n");
	}
	return 0;
}
