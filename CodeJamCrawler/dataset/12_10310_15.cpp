#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<char, char> m;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	m['a'] = 'y';
	m['b'] = 'h';
	m['c'] = 'e';
	m['d'] = 's';
	m['e'] = 'o';
	m['f'] = 'c';
	m['g'] = 'v';
	m['h'] = 'x';
	m['i'] = 'd';
	m['j'] = 'u';
	m['k'] = 'i';
	m['l'] = 'g';
	m['m'] = 'l';
	m['n'] = 'b';
	m['o'] = 'k';
	m['p'] = 'r';
	m['q'] = 'z';
	m['r'] = 't';
	m['s'] = 'n';
	m['t'] = 'w';
	m['u'] = 'j';
	m['v'] = 'p';
	m['w'] = 'f';
	m['x'] = 'm';
	m['y'] = 'a';
	m['z'] = 'q';
	m[' '] = ' ';

	int T;
	scanf("%d\n", &T);

	int c = 0;
	while(T--)
	{
		++c;
		printf("Case #%d: ", c);
		
		char s[200];
		gets(s);
		for (int i = 0; i < strlen(s); ++i)
		{
			printf("%c", m[s[i]]);
		}
		printf("\n");
	}

	return 0;
}