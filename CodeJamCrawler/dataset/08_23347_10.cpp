#include <iostream>
using namespace std;

bool canUse[10];
int k;
string s;
int a[10];
int minlen;

void dfs(int dep)
{
	if (dep == k)
	{
		string t(s);
		for(int i = 0; i < s.size(); i += k)
		{
			for(int j = 0; j < k; j++)
				t[i+j] = s[a[j] + i];
		}
		int tot = 0;
		char c = '0';
		for(int i = 0; i < t.size(); i++)
			if (c != t[i])
			{
				tot++;
				c = t[i];
			}
		if (tot < minlen)
			minlen = tot;
		return;
	}
	for(int i = 0; i < k; i++)
		if (canUse[i])
		{
			canUse[i] = false;
			a[dep] = i;
			dfs(dep + 1);
			canUse[i] = true;
		}
}

int main()
{
	int cases;
	cin >> cases;
	for(int c = 1; c <= cases; c++)
	{
		cin >> k;
		cin >> s;
		memset(canUse, true, sizeof(canUse));
		minlen = 1 << 30;
		dfs(0);
		cout << "Case #" << c << ": " << minlen << endl;
	}
	return 0;
}
