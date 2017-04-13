#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

#define inputFile string("C-small-attempt0.in")
#define outputFile string("C-small-attempt0.out")

streambuf *cinbuf;
streambuf *coutbuf;


bool palindrom(string num)
{
	string numCopy = num;
	reverse(num.begin(), num.end());
	return (numCopy == num);
}

bool fairSquare(unsigned long long num)
{
	ostringstream oss1,oss2;
	oss1 << num;
	string num1 = oss1.str();

	oss2 << sqrt(num);
	string num2 = oss2.str();
	if (num2.find(".") != string::npos)
			return false;
	return (palindrom(num1)&&palindrom(num2));
}


void calc()
{
	int cases;
	cin >> cases;
	unsigned long long a,b,nums;
	for (int i = 1; i <= cases; i++)
	{
		nums=0;
		cin >> a >> b;
		for (unsigned long long num = a; num <= b; num++)
		{
			if (fairSquare(num))
				nums++;
		}
		cout << "Case #" << i<<": " << nums << endl;
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
