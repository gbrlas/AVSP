//#define _DEB

#ifndef _DEB
	#define inf cin
	#define ouf cout
	#include <iostream>
#else
	#include <fstream>
#endif

int main()
{
	using namespace std;
#ifdef _DEB
	ifstream inf("input.txt");
	ofstream ouf("output.txt");
#endif

	int i, j, t, n, k, correct;

	inf >> t;

	for (i = 0; i < t; i++)
	{
		inf >> n >> k;

		correct = 1;
		for (j = 1; j < n; j++)
		{
			correct <<= 1;
			correct |= 1;
		}

		ouf << "Case #" << i + 1 << ": ";

		if ((k & correct) == correct)
		{
			ouf << "ON";
		}
		else
		{
			ouf << "OFF";
		}
		ouf << endl;
	}

#ifdef _DEB
	inf.close();
	ouf.close();
#endif
	return 0;
}
