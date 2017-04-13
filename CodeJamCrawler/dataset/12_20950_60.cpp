#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include<set>
#include<vector>
#include <map>;
using namespace std;

typedef unsigned long long int ll;


map<char, char> dict;
int t;
int main ()
{
   freopen("A-small-attempt0.in", "rt", stdin);
   freopen("A-small-attempt0.out", "wt", stdout);
    
    cin >> t;
	dict[' '] = ' ';
	dict['a'] = 'y';
	dict['b'] = 'h';
	dict['c'] = 'e';
	dict['d'] = 's';
	dict['e'] = 'o';
	dict['f'] = 'c';
	dict['g'] = 'v';
	dict['h'] = 'x';
	dict['i'] = 'd';
	dict['j'] = 'u';
	dict['k'] = 'i';
	dict['l'] = 'g';
	dict['m'] = 'l';
	dict['n'] = 'b';
	dict['o'] = 'k';
	dict['p'] = 'r';
	dict['q'] = 'z';
	dict['r'] = 't';
	dict['s'] = 'n';
	dict['t'] = 'w';
	dict['u'] = 'j';
	dict['v'] = 'p';
	dict['w'] = 'f';
	dict['x'] = 'm';
	dict['y'] = 'a';
	dict['z'] = 'q';

	getchar();
	for(int i = 0; i < t; i++)
	{
		string temp;
		getline(cin, temp);
		for(int j = 0; j < (int) temp.length(); j++)
		{
			temp[j] = dict[temp[j]];
		}
		cout << "Case #" << i+1 << ": " << temp << endl;
	}
}