#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

map<char, vector<int> > init_pos()
{
	map<char, vector<int> > pos;
	map<char, bool> used;

	string str = "welcome to code jam";
	for (int i=0; i<str.length(); i++)
	{
		if (!used[str[i]])
		{
			used[str[i]] = true;
			pos[str[i]] = vector<int>();
		}
		pos[str[i]].push_back(i);
	}

	return pos;
}

int main()
{
	ifstream in("C.in");
	ofstream out("C.out");

	map<char, vector<int> > pos = init_pos();
	int mat[502][21];

	int tests;
	in >> tests;

	string tmp;
	getline(in, tmp);

	for (int i=1; i<=tests; i++)
	{
		string text;
		getline(in, text);

		for (int j=0; j<text.length() + 2; j++)
			for (int k=0; k<21; k++)
				mat[j][k] = 0;

		mat[text.length() + 1][20] = 1;
		for (int j=text.length(); j>0; j--)
		{
			for (int k=0; k<21; k++)
				mat[j][k] = mat[j + 1][k];

			vector<int> ind = pos[text[j - 1]];
			for (int k=0; k<ind.size(); k++)
				mat[j][ind[k] + 1] = (mat[j][ind[k] + 1] + mat[j + 1][ind[k] + 2]) % 10000;
		}

		out << "Case #" << i << ": " << mat[1][1] / 1000 % 10 << mat[1][1] / 100 % 10 << mat[1][1] / 10 % 10 << mat[1][1] % 10 << endl;
	}

	return 0;
}