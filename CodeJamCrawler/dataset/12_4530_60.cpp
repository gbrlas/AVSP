#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


void main()
{
	map<char,char> m;
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
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string Ts;
	getline(fin,Ts);
	int T = atol(Ts.c_str());

	for(int i=1;i<=T;i++)
	{
		string linein;
		getline(fin,linein);
		for(int j=0;j<linein.size();j++)
			linein[j] = m[linein[j]];
		fout<<"Case #"<<i<<": "<<linein<<endl;
	}
}