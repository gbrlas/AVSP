#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void ReadFile(char* filename, map<char, char> D);
map<char, char> BuildDictionary();

int main()
{
	map<char, char> D = BuildDictionary();
	ReadFile("A-small-attempt0.in", D);
	return 0;
}

void ReadFile(char* filename, map<char, char> D)
{
	ifstream input;
	input.open(filename);

	int T;
	input >> T;

	ofstream output;
	output.open("Googlerese.out");

	char* buffer = new char[1024];
	input.read(buffer, 1);
	for(int i = 0; i < T; i++)
	{
		output << "Case #" << (i+1) << ": ";
		input.getline(buffer, 1024);
		for(int j = 0; buffer[j] != 0; j++)
		{
			output << D.find(buffer[j])->second;
		}
		if(i != (T-1))
			output << endl;
	}
}

map<char, char> BuildDictionary()
{
	map<char, char> D;
	D.insert(pair<char, char>('a', 'y'));
	D.insert(pair<char, char>('b', 'h'));
	D.insert(pair<char, char>('c', 'e'));
	D.insert(pair<char, char>('d', 's'));
	D.insert(pair<char, char>('e', 'o'));
	D.insert(pair<char, char>('f', 'c'));
	D.insert(pair<char, char>('g', 'v'));
	D.insert(pair<char, char>('h', 'x'));
	D.insert(pair<char, char>('i', 'd'));
	D.insert(pair<char, char>('j', 'u'));
	D.insert(pair<char, char>('k', 'i'));
	D.insert(pair<char, char>('l', 'g'));
	D.insert(pair<char, char>('m', 'l'));
	D.insert(pair<char, char>('n', 'b'));
	D.insert(pair<char, char>('o', 'k'));
	D.insert(pair<char, char>('p', 'r'));
	D.insert(pair<char, char>('q', 'z'));
	D.insert(pair<char, char>('r', 't'));
	D.insert(pair<char, char>('s', 'n'));
	D.insert(pair<char, char>('t', 'w'));
	D.insert(pair<char, char>('u', 'j'));
	D.insert(pair<char, char>('v', 'p'));
	D.insert(pair<char, char>('w', 'f'));
	D.insert(pair<char, char>('x', 'm'));
	D.insert(pair<char, char>('y', 'a'));
	D.insert(pair<char, char>('z', 'q'));
	D.insert(pair<char, char>(' ', ' '));
	return D;
}