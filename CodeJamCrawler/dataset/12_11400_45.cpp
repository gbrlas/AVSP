#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,char> m;

void init()
{
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
}

int main()
{
	init();
	int t;
	char buf[256];
	cin >> t;
	cin.getline(buf, 256, '\n');
	for (int ca = 1; ca <= t; ca++)
	{
		cin.getline(buf, 256, '\n');
		int sz = strlen(buf);
		for (int i = 0; i < sz; i++)
		{
			buf[i] = m[buf[i]];
		}
		cout << "Case #" << ca << ": " << buf << endl;
	}
	return 0;
}