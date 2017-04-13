#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string>
using namespace std;

#define inputFile string("A-small-attempt0.in")
#define outputFile string("A-small-attempt0.out")

streambuf *cinbuf;
streambuf *coutbuf;

void calc()
{
	int cases;
	cin >>cases;
	string line, s;
	string all;
	string col, diag1, diag2, diag;
	string c1 = "kkkk";
	string c2 = c1; string c3 = c1;string c4 = c1;
	for (int i = 1; i <= cases; i++)
	{
		line = "";
		c1 = "kkkk";
		diag1 = "";
		diag2 = "";
		c2 = c1; c3 = c1; c4 = c1;
		for (int j = 0; j < 4; j++)
		{
			cin >> s;
			line += " " + s;
			diag1.push_back(s[j]);
			diag2.push_back(s[3-j]);

			c1[j] = s[0];
			c2[j] = s[1];
			c3[j] = s[2];
			c4[j] = s[3];

		}

		diag = diag1 + " " + diag2;
		col = c1 + " " + c2 + " " + c3 + " " + c4;
		all = diag + " " + col + " " + line;

		if (all.find("TXXX") != string::npos || all.find("XXXT") != string::npos || all.find("XXXX") != string::npos)
		{
			cout << "Case #" << i<<": X won" << endl;
		}
		else if (all.find("TOOO") != string::npos || all.find("OOOT") != string::npos || all.find("OOOO") != string::npos)
		{
			cout << "Case #" << i<<": O won" << endl;
		}
		else if (line.find(".") != string::npos)
		{
			cout << "Case #" << i<<": Game has not completed" << endl;
		}
		else
		{
			cout << "Case #" << i<<": Draw" << endl;
		}

	}
}






int main()
{
	ifstream in(inputFile.c_str());
	if (!in.is_open())
	{
		cerr << "couldn't open input file, using default cin" << endl;
		cinbuf = NULL;
	}
	else
	{
		cinbuf = cin.rdbuf();
		cin.rdbuf(in.rdbuf());
	}

	ofstream out(outputFile.c_str());
	if (!out.is_open())
	{
		cerr << "couldn't open output file, using default cout" << endl;
		coutbuf = NULL;
	}
	else
	{
		coutbuf = cout.rdbuf();
		cout.rdbuf(out.rdbuf());
	}

	calc();

	if (cinbuf != NULL)
	{
		cin.rdbuf(cinbuf);
	}
	if (coutbuf != NULL)
	{
		cout.rdbuf(coutbuf);
	}
	exit(0);
}
