#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXL 111
char s[MAXL];
string t;

int main()
{
	t = "yhesocvxduiglbkrztnwjpfmaq";
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; ++i)
	{
		gets(s);
		int len = strlen(s);
		printf("Case #%d: ", i);
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == ' ')
				printf(" ");
			else
			{
				int u = s[i] - 'a';
				cout << t[u];
			}
		}
		puts("");
	}	
	return 0;
}