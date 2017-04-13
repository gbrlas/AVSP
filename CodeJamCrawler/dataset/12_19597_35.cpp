
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s = "yhesocvxduiglbkrztnwjpfmaq";

	ifstream in("a.in");
	ofstream out("out.txt");
	int n;
	in >> n;

	char line[102];
	in.getline(line, 102);

	for ( int i = 0; i < n; i++ )
	{
		in.getline(line, 102);
		string x = line;
		for ( int j = 0; j < x.size(); j++ )
			if ( x[j] != ' ')
				x[j] = s[x[j]-'a'];
		
		out << "Case #" << i+1 << ": " << x << "\n";
	}

	return 0;
}