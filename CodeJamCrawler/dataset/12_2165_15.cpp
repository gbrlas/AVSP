#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int runs;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small.out");

	map<char, char> charMap;
	charMap['a'] = 'y';
	charMap['b'] = 'h';
	charMap['c'] = 'e';
	charMap['d'] = 's';
	charMap['e'] = 'o';
	charMap['f'] = 'c';
	charMap['g'] = 'v';
	charMap['h'] = 'x';
	charMap['i'] = 'd';
	charMap['j'] = 'u';
	charMap['k'] = 'i';
	charMap['l'] = 'g';
	charMap['m'] = 'l';
	charMap['n'] = 'b';
	charMap['o'] = 'k';
	charMap['p'] = 'r';
	charMap['q'] = 'z';
	charMap['r'] = 't';
	charMap['s'] = 'n';
	charMap['t'] = 'w';
	charMap['u'] = 'j';
	charMap['v'] = 'p';
	charMap['w'] = 'f';
	charMap['x'] = 'm';
	charMap['y'] = 'a';
	charMap['z'] = 'q';
	charMap[' '] = ' ';


	fin >> runs;

	string line;
	getline(fin, line); //junk

	for(int r = 0; r < runs; r++)
	{
		getline(fin, line);
		fout << "Case #" << r+1 << ": ";
		for(int i = 0; i < line.size(); i++)
		{
			fout << charMap[line[i]];
		}
		fout << endl;
	}
	return 0;
}