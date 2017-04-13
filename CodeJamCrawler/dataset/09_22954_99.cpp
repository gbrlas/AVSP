#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

char line[1024];

int n;
int m;
char *pattern = "welcome to code jam";
int ok[20];

void work()
{
	memset(ok, 0, sizeof(ok));
	gets(line);
	ok[0] = 1;
	for (char *ch = line; *ch; ++ch)
	{
		char c = *ch;
		for (int i = m; i>0; --i)
			if (c==pattern[i-1])
			{
				ok[i] = ok[i]+ok[i-1];
				if (ok[i]>=10000)
					ok[i]-=10000;
			}
	}
	static int pid = 0;
	printf("Case #%d: %04d\n", ++pid, ok[m]%10000);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	m = strlen(pattern);
	int t;
	gets(line);
	sscanf(line, "%d", &t);
	for (int i = 0; i < t; ++i)
	{
		work();
	}
	return 0;
}
