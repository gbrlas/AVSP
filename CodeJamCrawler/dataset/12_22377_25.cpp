#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int getIntFromFile(ifstream &); //Function to get a line from a file and convert it to an int.
string convert(char);

int main()
{
	ifstream fin;
	fin.open("input.in");

	ofstream fout;
	fout.open("output.txt");

	int testCases = getIntFromFile(fin); //Get the number of test cases, and fin is ready ready at the next line.
	
	for (int i = 0; i < testCases; i++)
	{
		string result = "";
		string input;
		getline(fin, input);
		while (input.length() != 0)
		{
			result = result + convert(input.front());
			input = input.substr(1,input.length());
		}
		fout << "Case #" << i + 1 << ": " << result << endl;
	}

	fin.close();
	fout.close();
	return 0;
}

int getIntFromFile(ifstream & fin)
{
	int result;
	string s;
	getline(fin,s);
	istringstream convert(s);
	convert >> result;
	return result;
}

string convert(char c)
{
	string result;
	switch (c)
	{
		case ' ':
			result = " ";
			break;
		case 'y':
			result = "a";
			break;
		case 'n':
			result = "b";
			break;
		case 'f':
			result = "c";
			break;
		case 'i':
			result = "d";
			break;
		case 'c':
			result = "e";
			break;
		case 'w':
			result = "f";
			break;
		case 'l':
			result = "g";
			break;
		case 'b':
			result = "h";
			break;
		case 'k':
			result = "i";
			break;
		case 'u':
			result = "j";
			break;
		case 'o':
			result = "k";
			break;
		case 'm':
			result = "l";
			break;
		case 'x':
			result = "m";
			break;
		case 's':
			result = "n";
			break;
		case 'e':
			result = "o";
			break;
		case 'v':
			result = "p";
			break;
		case 'z':
			result = "q";
			break;
		case 'p':
			result = "r";
			break;
		case 'd':
			result = "s";
			break;
		case 'r':
			result = "t";
			break;
		case 'j':
			result = "u";
			break;
		case 'g':
			result = "v";
			break;
		case 't':
			result = "w";
			break;
		case 'h':
			result = "x";
			break;
		case 'a':
			result = "y";
			break;
		case 'q':
			result = "z";
			break;
	}
	return result;
}
