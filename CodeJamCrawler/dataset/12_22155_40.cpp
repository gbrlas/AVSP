#include <iostream>
#include <string>
#include <map>

using namespace std;

string convertString(const string& str);

int main()
{
	int numOfCases;
	cin >> numOfCases;
	cin.ignore(256, '\n');

	for(int i=1; i<=numOfCases; ++i)
	{
		string line;
		getline(cin, line);
		cout << "Case #" << i << ": " << convertString(line) << endl;
	}

	return 0;
}

string convertString(const string& str)
{
	map<char, char> dict;
	dict['y'] = 'a';
	dict['n'] = 'b';
	dict['f'] = 'c';
	dict['i'] = 'd';
	dict['c'] = 'e';
	dict['w'] = 'f';
	dict['l'] = 'g';
	dict['b'] = 'h';
	dict['k'] = 'i';
	dict['u'] = 'j';
	dict['o'] = 'k';
	dict['m'] = 'l';
	dict['x'] = 'm';
	dict['s'] = 'n';
	dict['e'] = 'o';
	dict['v'] = 'p';
	dict['z'] = 'q';
	dict['p'] = 'r';
	dict['d'] = 's';
	dict['r'] = 't';
	dict['j'] = 'u';
	dict['g'] = 'v';
	dict['t'] = 'w';
	dict['h'] = 'x';
	dict['a'] = 'y';
	dict['q'] = 'z';
	dict[' '] = ' ';

	string converted = "";
	for(int i=0; i!=str.length(); ++i)
		converted += dict[str[i]];

	return converted;
}
