#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>

using namespace std;
char code[] = "yhesocvxduiglbkrztnwjpfmaq";

string process_testcase(string s)
{
	string out;
	for (int i = 0; i < s.size(); ++i) {
	
		if (s[i] == ' ')
			out += " ";
		else
			out += code[s[i]-'a'];
	}

	return out;
}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if(argc == 1)
		is.open("input.txt");
	else
		is.open(argv[1]);

	string s;
	getline(is,s); 
	istringstream iss(s);
	iss >> tc;

	for(int i = 1; i <= tc; i++)
	{
		cout << "Case #" << i << ": ";
		getline(is,s); 
		cout << process_testcase(s) << endl;
	}
	is.close();
	return 0;
}
